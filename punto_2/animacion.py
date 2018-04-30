import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

ar=open('datos.txt','r')
fig, ax = plt.subplots()
x=np.linspace(0,100,300)


    
def leerlinea():
	y=np.linspace(0,0,300)
	l1=ar.readline()
	l=l1.split(',')
	for i in range(300):
		y[i]=float(l[i])
	return y

line, = ax.plot(x, leerlinea())	
def animate(i):
    line.set_ydata(leerlinea())  # update the data
    return line,
    
def init():
    line.set_ydata(np.ma.array(x, mask=True))
    return line,

plt.ylim(-1,1)
ani = animation.FuncAnimation(fig, animate, init_func=init,frames=100, interval=10 ,blit=True)
ani.save('cuerda.gif', writer='imagemagick', fps=60)


