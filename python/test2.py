import math
a = int(input("Dame el término a en ax2+bx+c=0: "))
b = int(input("Dame el término b en ax2+bx+c=0: "))
c = int(input("Dame el término c en ax2+bx+c=0: "))
if b*b-4*a*c < 0:
    print("Esta ecuación no tiene solución")
    print("Esta ecuación no tiene solución")
    print("Esta ecuación no tiene solución")
    print("Esta ecuación no tiene solución")
elif a == 0:
    print("Esta ecuación no es de segundo grado, pero la solución sería",-c/b)
else:
    print("Las soluciones de la ecuación",str(a)+"*x^2+"+str(b)+"*x+"+str(c)+"=0","son: ")
    print((-b+math.sqrt(b*b-4*a*c))/(2*a),)
    print((-b-math.sqrt(b*b-4*a*c))/(2*a))




