""" Write a program that repeatedly asks the user to enter product names and prices. Store all
of these in a dictionary whose keys are the product names and whose values are the prices.
When the user is done entering products and prices, allow them to repeatedly enter a
product name and print the corresponding price or a message if the product is not in the
dictionary. """
my_dictionary={}

n= int(input("enter number of key you want in library :"))

for i in range(n):
    key = input(f"Enter key {i + 1}: ") 
    value = input(f"Enter value for '{key}': ")  
    my_dictionary[key] = value

flag=1
while(flag==1):
    key=input("input key of value you want to excess :")
    if key in my_dictionary:
        print("corresponding value is ",my_dictionary[key])
    flag=int(input("enter 1 if u want to continue excessing value or else enter 0:"))
    
