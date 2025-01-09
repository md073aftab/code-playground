number = int(input("enter the number :"))
intial_number=number

sum =0 

while number>0 :
    remainder = number%10
    sum = sum*10 + remainder
    number= number//10

print("reverse of the",intial_number,"is",sum)