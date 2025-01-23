#Take numbers from 1 to 10000. Create equivalence classes for modulo 5 on this set of
#numbers. Check the validity of your equivalence classes. [Hint: the union of all equivalence
#classes should be the original set/list.]
R=list()
for i in range (0,5):
    L=list()
    for j in range(i,10001,5):
        L.append(j)
    R.append(L)
del(R[0][0])
print(R)
Original=[]
for i in range(1,5):
    Original+=R[i]
print(Original)
