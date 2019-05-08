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



