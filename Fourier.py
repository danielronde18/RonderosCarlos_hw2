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

