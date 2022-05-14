inputs=int(input())
list1=[]
result=[]
a=1

for i in range(inputs):
    inputs2=input()
    list1.append(inputs2)

list2=list(set(list1))
list2.sort(key=lambda x: len(x))
b=len(str(list2[len(list2)-1]))
list2.sort()


for j in range(b):
    for k in range(len(list2)):
        if len(list2[k])==a:
            result.append(list2[k])
    a=a+1

for s in range(len(result)):
    print(result[s])