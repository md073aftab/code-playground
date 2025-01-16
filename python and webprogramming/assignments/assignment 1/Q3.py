#Write a program that asks the user to enter a length in feet. The program should then give
#the user the option to convert from feet into inches, yards, miles, millimeters, centimeters,
#meters, or kilometers. Say if the user enters a 1, then the program converts to inches, if they
#enter a 2, then the program converts to yards, etc. While this can be done with if statements,
#it is much shorter with lists and it is also easier to add new conversions if you use lists.

length_feet= int(input("enter the length in feet : "))

print("Choice 1:feet to inches convertion")
print("Choice 2:feet to yards convertion")
print("Choice 3:feet to miles convertion")
print("Choice 4:feet to millimeter convertion")
print("Choice 5:feet to centimeter convertion")
print("Choice 6:feet to meter convertion")
print("Choice 7:feet to kilometer convertion")

choice =int(input("enter your choice :"))
if choice>7 :
    print("enter valid choice")


a = [
        0,                       
        length_feet*12,        # Feet to Inches
        length_feet/3,         # Feet to Yards
        length_feet/5280,      # Feet to Miles
        length_feet*304.8,     # Feet to Millimeters
        length_feet*30.48,     # Feet to Centimeters
        length_feet*0.3048,    # Feet to Meters
        length_feet*0.0003048  # Feet to Kilometers
    ]

a[0]=0
a[1]=12*length_feet
a[2]=length_feet/3
a[3]=length_feet/5280
a[4]=length_feet*304.8
a[5]=length_feet*30.48
a[6]=length_feet*0.3048
a[7]=length_feet*0.0003048

print(a[choice])



#def switch_example(choice):
#    match choice:
#        case 1:
#            print(12*length_feet,"inches")
#        case 2:
 #           print(length_feet/3,"yard")
#        case 3:
 #           print(length_feet/5280,"miles")
#        case 4:
#            print(length_feet*304.8,"millimeter")
# #      case 5:
#            print(length_feet*30.48,"centimeter")
#        case 6:
#            print(length_feet*0.3048,"meter")
#        case 7:
#            print(length_feet*0.0003048,"kilometer")
#        case _:
#            print("enter valid choice")

#switch_example(int(input()))