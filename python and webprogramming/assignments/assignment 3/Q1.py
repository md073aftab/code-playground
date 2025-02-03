def digital(n):
    if(n//10!=0):
        sum=0
        num=n
        while(num!=0):
            sum+=num%10
            num=num//10
        n=sum
        n=digital(n)
    return n
k=int(input("Enter number:"))
m=digital(k)
print(f"digital root of {k} is {m}")