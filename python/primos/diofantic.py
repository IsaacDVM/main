import math
import sys
lim = int(input("Dame el límite superior: "))
testa = []
testb = []
testc = []
treala = []
trealb = []
trealc = []
for x in range(0,math.floor(math.sqrt(lim))):
    for y in range (0,math.floor(math.sqrt(lim))):
        testa.append(4*x*x+y*y)
        testb.append(3*x*x+y*y)
        if x > y:
            testc.append(3*x*x-y*y)
print("Paso 0 ok")
foa = open("adata.txt", "w")
fob = open("bdata.txt","w")
foc = open("cdata.txt","w")
for k in range(0,lim+1):
    treala.append(testa.count(k))
    trealb.append(testb.count(k))
    trealc.append(testc.count(k))
    print(k)
for k in range (0,lim+1):
    print (treala[k], file=foa)
    print (treala[k], file=fob)
    print (treala[k], file=foc)
foa.close
fob.close
foc.close