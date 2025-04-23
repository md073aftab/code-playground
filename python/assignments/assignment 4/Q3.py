Alphabets = "abcdefghijklmnopqrstuvwxyz"

pangram=str(input("enter the string : ")).lower()
flag=0

for alphabet in Alphabets:
    if alphabet not in pangram:
        print("not pangram")
        flag=1
        break

if flag!=1:
    print("pangram")
