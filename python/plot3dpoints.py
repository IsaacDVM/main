import numpy as np
import numpy.linalg as la


# for plots in a window
# %matplotlib qt

import matplotlib.pyplot as pt
from mpl_toolkits.mplot3d import Axes3D

fig = pt.figure()
ax = fig.gca(projection='3d')
ax.set_xlim3d([-3, 3])
ax.set_ylim3d([-3, 3])
ax.set_zlim3d([-3, 3])
ax.set_xlabel('$X$')
ax.set_ylabel('$Y$')
ax.set_zlabel('$Z$')

a = [2,-1,0]

ax.scatter3D(a[0], a[1], a[2], label='A')
ax.scatter3D(a[0], 0, 0,color='#C0C0C0')
ax.scatter3D(0, a[1], 0,color='#C0C0C0')
ax.scatter3D(0, 0, a[2],color='#C0C0C0')

pt.show()
