#(c) The list ['a','bb','ccc','dddd', ...] that ends with 26 copies of the letter z.
A=[]
for i in range(0,26):
    A.append(chr(i+97))

    for j in range(0,i):
        A[i]=A[i]+chr(i+97)

for i in range(0,26):
    print(A[i])
