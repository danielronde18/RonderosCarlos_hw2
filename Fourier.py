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
