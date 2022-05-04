num=1
list1=[]

while num!=0:
    x,y=map(int,input().split())
    sum1=x+y
    list1.append(sum1)

    num=sum1

for i in range(len(list1)):
    if list1[i]!=0:
        print(list1[i])
    else:
        break