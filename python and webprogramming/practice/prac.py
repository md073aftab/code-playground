def decorator(func):
    def inner():
        phonenumber=func()
        phno = str(phonenumber)
        phno="+91-"+phno
        print("The phone number is: ",phno)
    return inner




@decorator
def phoneno():
    phno = str(input("Enter the phone number"))
    phno=phno[-10:]
    print("The phone number is: ",phno)
    return phno
 
phoneno()