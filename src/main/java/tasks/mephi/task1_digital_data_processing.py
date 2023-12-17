import warnings

import matplotlib.pyplot as plt
import numpy as np
import scipy
import soundfile as sf
from scipy.fft import rfft, rfftfreq
from scipy.signal import butter, lfilter

warnings.filterwarnings("ignore", category=scipy.io.wavfile.WavFileWarning)

filename = 'data/sample12.wav'
data, samplerate = sf.read(filename)

n = len(data)
T = 1 / samplerate
yf = rfft(data)
xf = rfftfreq(len(data), T)


def plot_spectrum(signal, sample_rate):
    spectrum = np.fft.fft(signal)
    freq = np.fft.fftfreq(len(spectrum), 1 / sample_rate)
    positive_freq_indices = np.where(freq > 0)
    positive_freq = freq[positive_freq_indices]
    positive_spectrum = np.abs(spectrum[positive_freq_indices])

    plt.figure(figsize=(10, 4))
    plt.plot(positive_freq, positive_spectrum)
    plt.xlabel('Частота (Гц)', fontsize=50)
    plt.ylabel('Амплитуда', fontsize=50)
    plt.title('Спектр композитного сигнала', fontsize=50)
    plt.grid()
    plt.xlim(0, max(positive_freq))
    plt.show()


plot_spectrum(data, samplerate)


def butter_bandpass(lowcut, highcut, fs, order=5):
    nyquist = 0.5 * fs
    low = lowcut / nyquist
    high = highcut / nyquist
    b, a = butter(order, [low, high], btype='band')
    return b, a


def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y


lowcut = 43400
highcut = 43600
carrier_freq = 43500

filtered_audio = butter_bandpass_filter(data, lowcut, highcut, samplerate)


def demodulate_am(signal, carrier_freq, sample_rate):
    t = np.arange(0, len(signal)) / sample_rate
    demodulated_signal = signal * np.cos(2 * np.pi * carrier_freq * t)
    return demodulated_signal


demodulated_signal = demodulate_am(data, carrier_freq, samplerate)
data = data / max(abs(data))
demodulated_signal = demodulated_signal / max(abs(demodulated_signal))

cutoff_freq = 15000
nyquist = 0.5 * samplerate
normal_cutoff = cutoff_freq / nyquist
b, a = butter(7, normal_cutoff, btype='low', analog=False)
filtered_signal = lfilter(b, a, demodulated_signal)

left_channel = (data + demodulated_signal) / 2
right_channel = (data - demodulated_signal) / 2

sf.write('data/12_ch1.wav', left_channel, samplerate)
sf.write('data/12_ch2.wav', right_channel, samplerate)
