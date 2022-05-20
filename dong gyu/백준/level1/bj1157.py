from collections import Counter

inputs=input().upper()
a=Counter(inputs)
a2=sorted(a.items(),key=lambda x:x[1],reverse=True)

max_key=max(a,key=a.get)

if len(inputs)!=1:
    if a2[0][1]==a2[1][1]:
        print('?')
    else:
        print(max_key)
else:
    print(inputs)