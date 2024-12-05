import matplotlib.pyplot as plt
import numpy as np
import scipy
import scipy.io.wavfile as swav
import scipy.signal
from scipy.signal import find_peaks


def discretization(sn, freq_disk):
    fft_mag = np.abs(np.fft.rfft(sn))
    num_point = len(sn)
    freq = np.fft.rfftfreq(num_point, 1 / freq_disk)
    return freq, fft_mag


def main():
    filename = 'data/sample12_2.wav'
    (freq_disk, sn) = swav.read(filename)

    time_array = np.arange(0, len(sn) / freq_disk, 1 / freq_disk)
    plt.figure('Graph of signal')
    plt.title('Graph of signal:')
    plt.xlabel('t,с')
    plt.ylabel('sn(t),В')
    plt.plot(time_array, sn)
    plt.grid()
    plt.show()

    freq, fft_mag = discretization(sn, freq_disk)

    plt.figure('Spectrum of signal')
    plt.title('Spectrum of signal')
    plt.xlabel('freq,Gz')
    plt.ylabel('А')
    plt.grid()
    plt.plot(freq, fft_mag)
    plt.show()

    filter_low = scipy.signal.firwin(300, 0.2, window="hamming")
    filt_sn = scipy.signal.convolve(filter_low, sn)
    time_array_2 = np.arange(0, len(filt_sn) / freq_disk, 1 / freq_disk)[:-1]

    plt.figure('First signal')
    plt.title('First signal')
    plt.xlabel('t,last')
    plt.ylabel('sn(t),В')
    plt.grid()
    plt.plot(time_array_2, filt_sn)
    plt.show()

    freq_first, fft_mag_first = discretization(filt_sn, freq_disk)

    plt.figure('Spectrum of first signal')
    plt.title('Spectrum of first signal')
    plt.xlabel('freq,Gz')
    plt.ylabel('А')
    plt.xlim(0, 2000)
    plt.grid()
    plt.plot(freq_first, fft_mag_first)
    plt.show()

    swav.write('data/12_filt_sample.wav', freq_disk, filt_sn)

    xf = freq
    yf = fft_mag
    freq_range = (xf >= 5_500) & (xf <= 6_500)
    xf_range = xf[freq_range]
    yf_range = yf[freq_range]

    peaks, _ = find_peaks(np.abs(yf_range), height=6_000)
    parasitic_frequencies = xf_range[peaks]
    print("Шумовые гармоники:", parasitic_frequencies)


if __name__ == '__main__':
    main()
