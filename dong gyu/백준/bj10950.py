a=int(input())
list_sum=[]

for i in range(a):
    x,y=map(int,input().split())
    c=x+y
    list_sum.append(c)

for k in range(a):
    print(list_sum[k])