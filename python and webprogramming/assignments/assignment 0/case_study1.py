boxes=int(input("enter no of boxes : "))
int_pos= int(input("enter initial position of the coin : "))
total_swap = int(input("enter the number of swap to perform : "))

list=[]

for i in range(1,boxes+1):
    if i==int_pos :
        list.append(1)
    else:
        list.append(0)


for i in range(1,total_swap+1):  # swaping postion

    a=int(input("enter the value of a:"))
    b=int(input("enter the value of b:"))
    
    temp=list[a-1]
    list[a-1]=list[b-1]
    list[b-1]=temp

for i in range(0,boxes):
    if list[i]==1 :
        print( "coin is present in",i+1,"box")
        
    
