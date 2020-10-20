def isprime(num):
    mybool = True
    if (num == 1 or num == 2):
        mybool = True
    elif (num <= 0):
        return("I have a negative integrer. You did something wrong")
    else:
        for i in range(2,num):
            if (num%i == 0):
                mybool = False
    return(mybool)
def lastprimediv(num):
    for i in range(num-1,1,-1):
        if (num%i == 0 and isprime(i)==True):
            return(i)
            break
print(lastprimediv(600851475143))
