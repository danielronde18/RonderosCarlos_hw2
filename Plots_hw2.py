import numpy as np
import matplotlib.pyplot as plt

datos1 = np.genfromtxt("ui_maximo.txt")

plt.figure()
plt.xlabel("$\omega$")
plt.ylabel("Amplitud máxima")
plt.plot(datos1[:,0], datos1[:,1], "-b", lw=2, label="u1")
plt.plot(datos1[:,0], datos1[:,2], "-g", lw=2, label="u2")
plt.plot(datos1[:,0], datos1[:,3], "-r", lw=2, label="u3")
plt.legend()
plt.savefig("amplitud_maxima.pdf",dpi=150)

datos2 = np.genfromtxt("datos1.txt")
plt.figure()
plt.xlim(left=0,right=150)
plt.xlabel("$t$")
plt.ylabel("$u_i(t)$")
plt.plot(datos2[:,0], datos2[:,1], "-b", lw=2, label="u1")
plt.plot(datos2[:,0], datos2[:,2], "-g", lw=2, label="u2")
plt.plot(datos2[:,0], datos2[:,3], "-r", lw=2, label="u3")
plt.legend()
plt.savefig("plot1.pdf",dpi=150)

datos3 = np.genfromtxt("datos2.txt")
plt.figure()
plt.xlim(left=0,right=150)
plt.xlabel("$t$")
plt.ylabel("$u_i(t)$")
plt.plot(datos3[:,0], datos3[:,1], "-b", lw=2, label="u1")
plt.plot(datos3[:,0], datos3[:,2], "-g", lw=2, label="u2")
plt.plot(datos3[:,0], datos3[:,3], "-r", lw=2, label="u3")
plt.legend()
plt.savefig("plot2.pdf",dpi=150)

datos4 = np.genfromtxt("datos3.txt")
plt.figure()
plt.xlim(left=0,right=150)
plt.xlabel("$t$")
plt.ylabel("$u_i(t)$")
plt.plot(datos4[:,0], datos4[:,1], "-b", lw=2, label="u1")
plt.plot(datos4[:,0], datos4[:,2], "-g", lw=2, label="u2")
plt.plot(datos4[:,0], datos4[:,3], "-r", lw=2, label="u3")
plt.legend()
plt.savefig("plot3.pdf",dpi=150)

datos5 = np.genfromtxt("datos4.txt")
plt.figure()
plt.xlim(left=0,right=150)
plt.xlabel("$t$")
plt.ylabel("$u_i(t)$")
plt.plot(datos5[:,0], datos5[:,1], "-b", lw=2, label="u1")
plt.plot(datos5[:,0], datos5[:,2], "-g", lw=2, label="u2")
plt.plot(datos5[:,0], datos5[:,3], "-r", lw=2, label="u3")
plt.legend()
plt.savefig("plot4.pdf",dpi=150)