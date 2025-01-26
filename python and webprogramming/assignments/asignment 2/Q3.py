num=int(input("Enter the number:"))
n=num
count=0
while(n>0):
    p=n%10
    if num%p==0:
        count+=1
    n=int(n/10)

print(count)