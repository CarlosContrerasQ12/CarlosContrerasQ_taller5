import numpy as np
import pylab as p
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
arch=open("potencial.txt",'r')

X=np.zeros((512,512))
Y=np.zeros((512,512))

pot=np.zeros((512,512))

for i in range(512):
	for j in range(512):
		line=arch.readline()
		l=line.split(',')
		X[j][i]=float(l[0])
		Y[j][i]=float(l[1])
		pot[j][i]=float(l[2])
arch.close()

camp=open("campo.txt",'r')
X2=np.zeros((512,512))
Y2=np.zeros((512,512))
Ex=np.zeros((512,512))
Ey=np.zeros((512,512))
for i in range(512):
	for j in range(512):
		lin=camp.readline()
		l=lin.split(',')
		X2[j][i]=float(l[0])
		Y2[j][i]=float(l[1])
		Ex[j][i]=float(l[2])
		Ey[j][i]=float(l[3])
		
camp.close()		
fig=plt.figure()

#ax = fig.add_subplot(211, projection='3d')

#ax.plot_wireframe(X,Y,pot,color='r')
ax=fig.add_subplot(211)
ax.imshow(pot,cmap='hot')

ax2 = fig.add_subplot(212)
t=np.linspace(1.5,3.5,100)
s=np.linspace(2,2,100)
s2=np.linspace(3,3,100)
ax2.streamplot(X2, Y2, Ex, Ey,cmap=plt.cm.inferno, density=2, arrowstyle='->', arrowsize=1.5)
ax2.plot(t,s,color='r',linewidth=5)
ax2.plot(t,s2,color='black',linewidth=5)
plt.savefig('placas.pdf')
			
