def listaDiv(num):
  div=[1,num]
  for i in range(2,round(num/2)):
    if (num%i==0):
     div.append(i)
  div.sort()
  long=len(div)
  return(long)
n=2
trig=1
while(listaDiv(trig)<500):
  trig+=n
  n+=1
print(trig)