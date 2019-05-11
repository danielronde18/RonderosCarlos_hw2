import numpy as np
import matplotlib.pylab as plt
import scipy as sp
from scipy.fftpack import fft, fftfreq,ifft
import math

senal=np.genfromtxt("signal.dat")
senalSuma=np.genfromtxt("signalSuma.dat")

xonsen=senal[:,0]
yonsen=senal[:,1]

xonsensum=senalSuma[:,0]
yonsensum=senalSuma[:,1]

plt.figure()
f, axarr = plt.subplots(2, sharex=True)
f.suptitle('señal Sumada')
plt.title("Señal Sumada")
plt.xlabel("x")
plt.ylabel("y(x)")
axarr[0].plot(xonsensum,yonsensum)
axarr[1].plot(xonsen,yonsen)
plt.title("Señal Original")
plt.xlabel("x")
plt.ylabel("y(x)")
plt.savefig("RonderosCarlos_signalSumasub.pdf")

def transfor(xonsen,yonsen):
    N=len(xonsen)
    pi=np.pi
    suma=np.linspace(0,0,len(xonsen))
    for i in range(len(xonsen)):
        for j in range(len(yonsen)):
            suma[i]+= yonsen[j]*np.exp((-1j)*2*pi*i*j/N)
    suma=suma/N
    return suma

SS=xonsen[1]-xonsen[0]
freqx=fftfreq(len(xonsen),SS)
plt.figure()
plt.plot(freqx,abs(transfor(xonsen,yonsen)))
plt.title("Transformada de fourier")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada")
plt.xlim(-750,750)
plt.savefig("RonderosCarlos_transformada.pdf")

SS4=xonsensum[1]-xonsensum[0]
freqx4=fftfreq(len(xonsensum),SS4)
plt.figure()
plt.plot(freqx4,abs(transfor(xonsensum,yonsensum)))
plt.title("Transformada de fourier")
plt.xlabel("Frecuencia")
plt.ylabel("Transformada")
plt.xlim(-750,750)
plt.savefig("RonderosCarlos_transformada_originalSuma.pdf")



dt3 = 0.00003022
#t3 = np.arange(2.38558376754426e-08, 0.06187167870047863, dt3)
t3 = np.linspace(2.38558376754426e-08, 0.06187167870047863, 2048)
NFFT3 = 1024  # the length of the windowing segments
Fs3 = int(1.0 / dt3)  # the sampling frequency
fig, (ax1, ax2) = plt.subplots(nrows=2)
ax1.plot(t3, abs(transfor(xonsen,yonsen)))
Pxx, freqs, bins, im = ax2.specgram(abs(transfor(xonsen,yonsen)), NFFT=NFFT3, Fs=Fs3, noverlap=900)

plt.savefig("espectrograma_original.pdf")
plt.show()


dt4 = 0.00000009364
t4 = np.arange(2.609337192143404e-11,0.00019175507296341149 , dt4)

NFFT4 = 1024  
Fs4 = int(1.0 / dt4)  
fig, (ax1, ax2) = plt.subplots(nrows=2)
ax1.plot(t4, abs(transfor(xonsensum,yonsensum)))
Pxx, freqs, bins, im = ax2.specgram(abs(transfor(xonsensum,yonsensum)), NFFT=NFFT4, Fs=Fs4, noverlap=900)


plt.savefig("espectrograma_originalSumado.pdf")
plt.show()
