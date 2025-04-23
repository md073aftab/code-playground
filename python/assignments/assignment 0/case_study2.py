heights=[]
total_person= int(input("enter total number of people in line"))

print("enter heights of person standing in line")
count=0

for i in range(1,total_person+1):
    heights.append(int(input()))

for i in range(0,total_person):
    if heights[i]!=i+1:
        heights[heights[i]-1]=heights[i] 
        count+=1
print(count)
    