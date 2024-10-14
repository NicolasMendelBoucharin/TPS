# type: ignore
# flake8: noqa
#
#
#
#
#
#
#
import numpy as np
import scipy.stats as stats
import scipy.linalg as linalg
import matplotlib.pyplot as plt
import matplotlib
import random
import math
#
#
#
#
#
#
#

import  csv
with open('/home/aldaron/Documents/Cours/probastat/TP/donnees5.csv' , newline = '') as f:
        lignes = [ligne for ligne in csv.reader(f)]


lignes = list(map(float, lignes[0][:]))

estimemp=2*np.mean(lignes)

print("l'estimateur empirique est : ", estimemp)
maxivrai=np.max(lignes)
print("l'estimateur du maximum de vraisemblance est : ", maxivrai)


#
#
#
#
#
y=np.cumsum(lignes)
x=np.arange(1, 1001, 1)
z=[]
zz=[]
for i in x:
    z.append(2*y[i-1]/i)
    zz.append(np.max(lignes[0:i]))

plt.plot(x, z, color = 'blue', label = 'estimateur empirique')
plt.plot(x, zz, color = 'red', label = 'estimateur du max de vraisemblance')
plt.legend()
plt.show()


teta=13
M=stats.uniform.rvs(scale = teta, size=(1000,1000))
espteta=teta/2
varteta=(teta**2)/12

MM=[np.sqrt(1000)*(2*np.mean(M[i, :])- teta)/(2*np.sqrt(varteta)) for i in range(1000)]

MMM=[-1000*(np.max(M[i, :])-teta) for i in range(1000)]

plt.hist(MM, bins=20, density=True, label ="histogramme pour l'estimateur empirique")

X=np.linspace(-4, 4, 10000)
plt.plot(X, stats.norm.pdf(X, loc = 0, scale = 1), label ="loi normale 0 1")
plt.legend()
plt.show()
plt.clf()

plt.hist(MMM, bins=20, density=True, label ="histogramme pour l'estimateur du maximum de vraissemblance")
plt.plot(X, stats.expon.pdf(X, scale = teta), label ="loi expo de paramètre 1/teta")
plt.legend()
plt.show()

#
#
#
#
#
#
#
#
#
alpha=0.05
zinf=[z[i] - (1.96/np.sqrt(i+1))*(z[i]/np.sqrt(12)) for i in range(1000)]
zsup=[z[i] + (1.96/np.sqrt(i+1))*(z[i]/np.sqrt(12)) for i in range(1000)]

plt.plot(x, z, color = 'blue', label = 'estimateur empirique')

plt.plot(x, zinf, color = 'purple', label ='intervalle de confiance')
plt.plot(x, zsup, color = 'purple')
plt.legend()
plt.show()
#
#
#
#
#
#
#
#
X=stats.norm.rvs(loc =0, scale = 1, size=1000)
X=np.sort(X)
def k1(p):
    return X[np.trunc(p)+1]

def k10(p):
    return X[math.floor(10*p)+1]

def k100(p):
    return X[np.trunc(100*p)+1]

def k500(p):
    return X[np.trunc(500*p)+1]

x=np.linspace(0, 1, 1000)
plt.plot(x, (k10(p) for p in x))

#
#
#
