import matplotlib.pyplot as plt
import numpy as np
import scipy.io.wavfile as wav
from scipy.signal import butter, filtfilt

filename = 'data/sample12.wav'
samplerate, data = wav.read(filename)

spectrum = np.fft.fft(data)
freq = np.fft.fftfreq(len(spectrum), 1 / samplerate)
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

carrier_freq = 43_500

t = np.arange(0, len(data)) / samplerate
demodulated_signal = data * np.cos(2 * np.pi * carrier_freq * t)

cutoff_freq = 18000
nyquist = 0.5 * samplerate
normal_cutoff = cutoff_freq / nyquist

b, a = butter(10, normal_cutoff, btype='low', analog=False)
add_signal = filtfilt(b, a, data)
diff_signal = filtfilt(b, a, demodulated_signal)

left_channel = (add_signal + diff_signal * 2) / 2
right_channel = (add_signal - diff_signal * 2) / 2

wav.write('data/12_ch1.wav', samplerate, left_channel)
wav.write('data/12_ch2.wav', samplerate, right_channel)

plt.plot(freq, spectrum)
plt.xlabel('Частота (Гц)')
plt.ylabel('Спектр')
plt.title('Спектр композитного сигнала')
plt.grid()
plt.xlim(0, 150)
plt.ylim(-150, 150)
plt.show()

freq_med_ind = len(freq) // 2
delta = 10
dc_component = np.abs(np.average(spectrum[freq_med_ind - delta:freq_med_ind + delta]))
print(dc_component)
