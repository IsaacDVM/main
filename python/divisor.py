def divisors(num):
    a = []
    for i in range(1,num):
        if (num%i == 0):
            a.append(i)
    return(a)
num = int(input("Dame el número del que quieres hayar divisores "))
print(divisors(num))