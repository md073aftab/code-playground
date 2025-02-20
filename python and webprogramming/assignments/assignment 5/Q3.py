word=str(input("Enter the word :"))
intial=word
length=len(word)
word=list(word)
word=word[::-1]

for i in range(0,length-1):
    if ord(word[i])>ord(word[i+1]):
        word[i], word[i + 1] = word[i + 1], word[i]
        break
word.reverse()
#word=str(word)
word = "".join(word)

if word==intial :
    print("No answer")
else:
    print(word)