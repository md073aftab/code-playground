string=[]
modified_string=[]
string=str(input("enter the word : "))

for i in range(len(string)):
    if i%2!=0:
        modified_string.append(string[i].upper())
    else:
        modified_string.append(string[i])
result = ''.join(modified_string)
print(string)        
print(result)        