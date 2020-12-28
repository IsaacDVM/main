# Open a file
fo = open("data.txt", "r+")
print ("Name of the file: ", fo.name)
lines = fo.readlines()
print(lines)
count = 0
# Strips the newline character 

for i in lines: 
    count += int(i.rstrip())
# Close opened file
print(count)
fo.close()
