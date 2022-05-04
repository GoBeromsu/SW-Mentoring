num=[]

for i in range(9):
    a=int(input())
    num.append(a)

b=max(num)
c=num.index(b)

print(b)
print(c+1)