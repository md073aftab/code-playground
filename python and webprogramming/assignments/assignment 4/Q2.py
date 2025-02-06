import math

a=int(input("Enter the value of A:"))
b=int(input("Enter the value of b:"))

A=int(math.sqrt(a))
B=int(math.sqrt(b))

print(f"Their are {abs(B-A)} sqare integers between {a} and {b}")