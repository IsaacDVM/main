num = 100
result = 0
for i in range (1,num + 1):
    for j in range (1, num + 1):
        if i != j:
            result += i*j
print(result)