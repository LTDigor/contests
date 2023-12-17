import matplotlib.pyplot as plt
import numpy as np
import scipy.io.wavfile as swav
import scipy.signal


def discretization(sn, freq_disk):
    fft_mag = np.abs(np.fft.rfft(sn))
    num_point = len(sn)
    freq = np.fft.rfftfreq(num_point, 1 / freq_disk)
    return freq, fft_mag


def main():
    (freq_disk, sn) = swav.read('data/sample12_2.wav')
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
    plt.xlabel('t,c')
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


if __name__ == '__main__':
    main()
