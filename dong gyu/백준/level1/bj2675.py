testcase_num=int(input())
list1=[]

for i in range(testcase_num):
    b=''
    x,y=input().split()
    x=int(x)
    for k in range(len(y)):
        a=y[k]*x
        b=b+a
    list1.append(b)

for h in range(testcase_num):
    print(list1[h])