list1=[]

for i in range(3):
    num=int(input())
    list1.append(num)

new_number=list(str(list1[0]*list1[1]*list1[2]))

for k in range(10):
    a=new_number.count(str(k))
    print(a)