cycle=int(input("enter the number of input cycle :\n"))

height=1

for i in range(1,cycle+1):
    if(i%2==1):
        height*=2
    else:
        height+=1

print(f"height of sampling after{cycle} cycle is {height} meters")           