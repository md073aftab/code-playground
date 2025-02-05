# 1 . rindex function

def rindex(string,substring,start=0,end=float('inf')):
    if (end==float('inf')):
        end=len(string)
    index=-1
    for i in range(start,end-len(substring)+1):
        sub=string[i:i+len(substring)]
        if(sub==substring):
            index=i
    if(index==-1):
        #raising error if no substring found
        raise ValueError("Not found")
    else:
        return index
string=input("Enter string:")
sub=input("enter substring to find:")
try:
    index=rindex(string,sub)
    print(f"last occurence of {sub} is at index {index}")
except ValueError as e:
    print(f"Error:{e}")

# 2 . rspilt function
def rsplit(string,sep=' ',end=float('inf')):
    string=string[::-1]
    l=[]
    str=""
    count,index=0,0
    for i in string:
        if (i==sep and string[index+1]!=sep and count<end):
            str=str[::-1]
            l.append(str)
            str=""
            count+=1
        else:
            str+=i
        index+=1
    str=str[::-1]
    l.append(str)
    l=l[::-1]
    return l
L=[]
string=input("enter string:")
sep=input("enter separator:")
print(rsplit(string,sep,2))

# 3 . rfind function
def rfind(string,substring,start=0,end=float('inf')):
    if (end==float('inf')):
        end=len(string)
    index=-1
    for i in range(start,end-len(substring)+1):
        sub=string[i:i+len(substring)]
        if(sub==substring):
            index=i
    return index
string=input("Enter string:")
sub=input("enter substring to find:")
index=rfind(string,sub,3,7)
print(index)

# 4 . replace function

def replace(string,substring,new,cnt=float('inf')):
    count=0
    str=""
    i=0
    while (i<len(string)-len(substring)+1 and count<cnt):
        sub=string[i:i+len(substring)]
        if (sub==substring):
            str+=new
            count+=1
            i+=len(substring)
        else:
            str+=string[i]
            i+=1
    str+=string[i:len(string)]
    return str
a=replace(input("Enter string:"),input("Enter string to replace:"),input("Enter new string:"),1)
print(a)

# 5 . count function

def count(string,substring,start=0,end=float('inf')):
    count=0
    if end==float('inf'):
        end=len(string)
    for i in range(start,end-len(substring)+1):
        sub=string[i:i+len(substring)]
        if (sub==substring):
            count+=1
    return count
count1=count(input("Enter string:"),input("Enter substring:"))
print(count1)