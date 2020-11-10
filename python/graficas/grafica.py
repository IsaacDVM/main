import matplotlib.pyplot as plt
import numpy
t1 = 5.0
t2 = 5.0
t3 = 5.0
t4 = 5.0
a1 = -1.0
a2 = 0.0
a3 = 2.0
a4 = -1.0
vo1 = 5.0
xo1 = 10.0
num = 1000
#estos datos ya son calculados
vo2 = vo1 + a1*t1
vo3 = vo2 + a2*t2
vo4 = vo3 + a3*t3
xo2 = xo1 + vo1*t1 + 0.5*a1*t1*t1
xo3 = xo2 + vo2*t2 + 0.5*a2*t2*t2
xo4 = xo3 + vo3*t1 + 0.5*a3*t3*t3
# intervalo de tiempos
lin1 = numpy.linspace(0.0,t1,num)
lin2 = numpy.linspace(t1,t2,num)
lin3 = numpy.linspace(t2,t3,num)
lin4 = numpy.linspace(t3,t4,num)
#funciones
x1 = xo1 + vo1*lin1 + a1*lin1*lin1
x2 = xo2 + vo2*lin2 + a2*lin2*lin2
x3 = xo3 + vo3*lin3 + a3*lin3*lin3
x4 = xo4 + vo4*lin4 + a4*lin4*lin4
# Graficar funciones.
plt.plot(lin1, x1)
plt.plot(lin2, x2)
plt.plot(lin3, x3)
plt.plot(lin4, x4)
# Establecer el color de los ejes.
plt.axhline(0, color="black")
plt.axvline(0, color="black")
# Limitar los valores de los ejes.
plt.xlim(0, t4+1)
plt.ylim(0, x4[-1]+1)
plt.xlabel('t (s)')
plt.ylabel('x (m)')
# Guardar gráfico como imágen PNG.
plt.savefig("output.png")
# Mostrarlo.
plt.show()