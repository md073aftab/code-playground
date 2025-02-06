Alphabets=("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z")

pangram=str(input("enter the string : "))
pangram=pangram.lower()
flag=0

for alphabet in Alphabets:
    if alphabet not in pangram:
        print("not pangram")
        flag=1
if flag!=1:
    print("pangram")
