# 1. Maximizing XOR

l=int(input("enter value of L:"))
r=int(input("enter value of R:"))

mx_xor=0
for i in range(l,r+1):
    for j in range(i,r+1):
        xor=i^j
        mx_xor=max(mx_xor,xor)
print(f"Maximum Value Of XOR Is {mx_xor}")       