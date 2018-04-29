import numpy as np
import pylab as p
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
arch=open("potencial.txt",'r')

x=np.linspace(0,5,512)
y=np.linspace(0,5,512)
X,Y=np.meshgrid(x,y)

pot=np.zeros((512,512))
print("creados")

for i in range(512):
	for j in range(512):
		pot[i][j]=float(arch.readline())
arch.close()

camp=open("campo.txt",'r')

Ex=np.zeros((512,512))
Ey=np.zeros((512,512))
for i in range(512):
	for j in range(512):
		lin=camp.readline()
		l=lin.split(',')
		Ex[i][j]=float(l[0])
		Ey[i][j]=float(l[1])
		
camp.close()
print("leido")			
fig=plt.figure()

ax = fig.add_subplot(111, projection='3d')

ax.plot_wireframe(X,Y,pot,color='r')
#plt.imshow(pot)

fig2=plt.figure()
ax2 = fig2.add_subplot(111)
t=np.linspace(1.5,3.5,100)
s=np.linspace(2,2,100)
s2=np.linspace(3,3,100)
ax2.streamplot(X, Y, Ex, Ey,cmap=plt.cm.inferno, density=1.5, arrowstyle='->', arrowsize=1.5)
ax2.plot(t,s,color='r',linewidth=5)
ax2.plot(t,s2,color='r',linewidth=5)
plt.show()
			
