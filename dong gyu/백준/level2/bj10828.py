num=int(input())
list1=[]
list2=[]

for i in range(num):
    inputs=input()
    list1.append(inputs)

for k in list1:
    list3=list(k.split())
    if 'push' in list3:
        list2.append(list3[1])
    
    elif 'pop' in list3:
        if len(list2)!=0:
            print(list2.pop())
        elif len(list2)==0:
            print('-1')
    
    elif 'size' in list3:
        print(len(list2))
    
    elif 'empty' in list3:
        if len(list2)==0:
            print('1')
        else:
            print('0')
    
    elif 'top' in list3:
        if len(list2)!=0:
            print(list2[-1])
        else:
            print('-1')