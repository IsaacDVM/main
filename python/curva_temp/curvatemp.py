import matplotlib.pyplot as plt
import numpy
print ("Programa para imprimir la curva de temperatura de un material")
print ("Introduce los datos en SI")
csol = float(input("Capacidad calorífica del sólido (J/Kg*K) = "))
cliqu = float(input("Capacidad calorífica del líquido (J/Kg*K) = "))
cpgas = float(input("Capacidad calorífica del gas a presión constante (J/Kg*K) = "))
potencia = float(input("Potencia del calentador (W) = "))
pfus = float(input("Punto de fusión (K) = "))
pebull = float(input("Punto de ebullición (K) = "))
masa = float(input("masa del material (kg) = "))
lfus = float(input("Calor latente fusión (J/kg) = "))
lvapor = float(input ("Calor latente de vaporización (J/kg) = "))
Tini = float(input("Temperatura inicial (K) = "))
Tfinal = float(input("Temperatura final (K) = "))
num = 400
# definir los tiempos
t1 = (pfus - Tini) * masa * csol / potencia
t2 = t1 + masa * lfus / potencia
t3 = t2 + (pebull - pfus) * masa * cliqu / potencia
t4 = t3 + masa * lvapor / potencia
t5 = t4 + (Tfinal-pebull) * masa * cpgas / potencia
# definir los espacios de tiempos
lin1 = numpy.linspace(0,t1,num)
lin2 = numpy.linspace(t1,t2,num)
lin3 = numpy.linspace(t2,t3,num)
lin4 = numpy.linspace(t3,t4,num)
lin5 = numpy.linspace(t4,t5,num)
# definición funciones; es importante que f2 y f4 sean arrays
f1 = Tini + lin1 * potencia / (masa * csol)
f2 = pfus * numpy.ones(num)
f3 = pfus + (lin3 - numpy.ones(num) * t2) * potencia / (masa * cliqu)
f4 = pebull * numpy.ones(num)
f5 = pebull + (lin5 - numpy.ones(num) * t4)* potencia / (masa * cpgas)
# Graficar funciones.
plt.plot(lin1, f1)
plt.plot(lin2, f2)
plt.plot(lin3, f3)
plt.plot(lin4, f4)
plt.plot(lin5, f5)
# Establecer el color de los ejes.
plt.axhline(0, color="black")
plt.axvline(0, color="black")
# Limitar los valores de los ejes.
plt.xlim(0, t5)
plt.ylim(0, Tfinal)
plt.xlabel('Tiempo (s)')
plt.ylabel('Temperatura (K)')
# Guardar gráfico como imágen PNG.
plt.savefig("output.png")
# Mostrarlo.
plt.show()
