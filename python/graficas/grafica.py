import matplotlib.pyplot as plt
import numpy
dt1 = 5.0
dt2 = 4.0
dt3 = 3.0
dt4 = 2.0
a1 = 1.0
a2 = 0.
a3 = -1.0
a4 = 0.0
vo1 = 1.0
xo1 = 5.0
num = 1000
#estos datos ya son calculados
vo2 = vo1 + a1*dt1
vo3 = vo2 + a2*dt2
vo4 = vo3 + a3*dt3
xo2 = xo1 + vo1*dt1 + 0.5*a1*dt1*dt1
xo3 = xo2 + vo2*dt2 + 0.5*a2*dt2*dt2
xo4 = xo3 + vo3*dt3 + 0.5*a3*dt3*dt3
# intervalo de tiempos
lin1 = numpy.linspace(0.01,dt1,num)
lin2 = numpy.linspace(0.01,dt2,num)
lin3 = numpy.linspace(0.01,dt3,num)
lin4 = numpy.linspace(0.01,dt4,num)
#funciones posición
x1 = xo1 + vo1*lin1 + 0.5*a1*lin1*lin1
x2 = xo2 + vo2*lin2 + 0.5*a2*lin2*lin2
x3 = xo3 + vo3*lin3 + 0.5*a3*lin3*lin3
x4 = xo4 + vo4*lin4 + 0.5*a4*lin4*lin4
#funciones velocidad
v1 = vo1 + a1 * lin1
v2 = vo2 + a2 * lin2
v3 = vo3 + a3 * lin3
v4 = vo4 + a4 * lin4
# Graficar funciones.
plt.plot(lin1, x1)
plt.plot(dt1+lin2, x2)
plt.plot(dt1+dt2+lin3, x3)
plt.plot(dt1+dt2+dt3+lin4, x4)
# Establecer el color de los ejes.
plt.axhline(0, color="black")
plt.axvline(0, color="black")
# Limitar los valores de los ejes.
#plt.xlim(0, (dt1+dt2+dt3+dt4)*1.1)
#plt.ylim(0, x4[-1]*1.01)
plt.xlabel('t (s)')
plt.ylabel('x (m)')
# Guardar gráfico como imágen PNG.
plt.savefig("position.png")
plt.clf()
# Graficar velocidad
plt.plot(lin1, v1)
plt.plot(dt1+lin2, v2)
plt.plot(dt1+dt2+lin3, v3)
plt.plot(dt1+dt2+dt3+lin4, v4)
# Establecer el color de los ejes.

# Limitar los valores de los ejes.
#plt.xlim(0, (dt1+dt2+dt3+dt4)*1.1)
#plt.ylim(0, v4[-1]*1.01)
plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
# Guardar gráfico como imágen PNG.
plt.savefig("speed.png")
plt.clf()
# Graficar a
plt.plot(lin1, lin1*a1/lin1)
plt.plot(dt1+lin2, lin2*a2/lin2)
plt.plot(dt1+dt2+lin3, lin3*a3/lin3)
plt.plot(dt1+dt2+dt3+lin4, lin4*a4/lin4)
# Establecer el color de los ejes.
# Limitar los valores de los ejes.
#plt.xlim(0, (dt1+dt2+dt3+dt4)*1.1)
#plt.ylim(0, v4[-1]*1.01)
plt.xlabel('t (s)')
plt.ylabel('a (m/s^2)')
# Guardar gráfico como imágen PNG.
plt.savefig("aceleration.png")
plt.clf()
