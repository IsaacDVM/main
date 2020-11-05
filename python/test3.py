miBoole = True
miLst = []
miErr = []
while miBoole == True:
	miEntr = input("Dame números y no pares. Cuando quieras parar pulsa intro vacío: ")
	if miEntr == '':
		miBoole = False
	else:
		miLst.append(float(miEntr))
print(miLst)
media = 0
for j in miLst:
	media = media + j
media = media / len(miLst)
print(media)
for k in miLst:
	miErr.append(k-media)
print(miErr)
a = 0
while True:
	a += 1
	print(a)
