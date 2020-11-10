M = 600851475143
num = int(M)
n = 1


def isprime(numero):
  if numero < 1:
    return False
  elif numero == 2:
    return True
  for i in range(2, (numero//2)):
    if numero%i == 0:
      return False
  return True

numlt = []
while (n<(num//2)):
  if num%n != 0:
    n+=2
    pass
  else:
    if isprime(n):
      numlt.append(n)
    n+=2

print(numlt)


numlt.reverse()
'''f = 1
for i in ltnum:
  if i%f != 0:
    f+=2
    pass
  else:
'''