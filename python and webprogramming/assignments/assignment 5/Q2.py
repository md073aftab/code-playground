k=int(input("Enter the number of cut Alex can make"))

pieces=0

for i in range(1,k+1):
    if i%2==1:
        pieces+=int((i-1)/2)
    else:
        pieces+=int(i/2)    

print(f"Silvia can have {pieces} of cake")       