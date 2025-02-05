number=int(input("enter the number to check:"))

x=0
y=1
a=0

while(number!=a or number<a):
    a=x+y
    y=x
    x=a

if(number==a):
    print(f"{number} is an element of fibonaci series")    
else:
    print(f"{number} is not an element of fibonaci series")    