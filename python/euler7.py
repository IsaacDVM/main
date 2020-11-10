import math
lim = 5000000
primo = [2,3,5]
criba = []
num = []
for i in range(1,lim+1):
    criba.append(False)
    num.append(i)
testa = []
testb = []
testc = []
for x in range(0,math.floor(math.sqrt(lim))):
    for y in range (0,math.floor(math.sqrt(lim))):
        testa.append(4*x*x+y*y)
        testb.append(3*x*x+y*y)
        if x > y:
            testc.append(3*x*x-y*y)
print("Paso 1 ok")
for j in num:
    mod = j % 60
    print(j)
    if mod == 1 or mod == 13 or mod == 17 or mod == 29 or mod == 37 or mod == 41 or mod == 49 or mod == 53:
        if testa.count(j)%2 != 0:
            criba[j-1]=True
    elif mod == 7 or mod == 19 or mod == 31 or mod == 43:
        if testb.count(j)%2 != 0:
            criba[j-1]=True
    elif mod == 11 or mod == 23 or mod ==  47 or mod == 59:
        if testc.count(j)%2 != 0:
            criba[j-1]=True
    else:
        pass
print("Paso 2 ok")
for i in num:
    if criba[i-1] == False or i == 1:
        pass
    else:
        primo.append(i)
        n = i*i
        mult = 1
        while n*mult < lim:
           criba[n*mult-1] = False
           mult += 1
sum = 0
for i in range(0,2000001):
    sum += primo[i]
print(sum)
print(len(primo))
print(primo[10000])