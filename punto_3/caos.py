import numpy as np
import matplotlib.pyplot as plt
q2,p2=np.genfromtxt('caos.txt',delimiter=',',unpack=True,dtype=float)
plt.plot(q2,p2)
plt.savefig('caos.pdf')
