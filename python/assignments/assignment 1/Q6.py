#Consider a 3-D co-ordinate space. Input 10 3-D points. Find the nearest neighbour for each
#of the points in your 3-D space and store them in a list. The final output is a list with each
#consisting of a point and its nearest neighbour. [Hint: Use distance between two points
#formula]
points=[]
L=[]
for i in range(1,4):
    print("point .",i)
    a=float(input("x-coordinate:"))
    b=float(input("y-coordinate:"))
    c=float(input("z-coordinate:"))
    points.append((a,b,c))
min=float("inf")
print(points)
for i in points:
    for j in points:
        if (i!=j):
            d=(((i[0]-j[0])**2)+((i[1]-j[1])**2)+((i[2]-j[2])**2))**0.5
            if min>d:
                min=d
                index=j
        else:
            continue
    L.append((i,index))
    index=j
    min=float("inf")
print(L)
    