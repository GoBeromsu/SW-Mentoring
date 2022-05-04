n,x=map(int,input().split())
num=list(map(int,input().split()))
list1=[]

for i in range(n):
    if num[i]<x:
        list1.append(num[i])
    else:
        continue

list1=map(str,list1)
print(' '.join(list1))