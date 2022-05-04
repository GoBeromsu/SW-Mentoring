num=[]

for i in range(10):
    a=int(input())
    b=str(a%42)
    if b in num:
        continue
    else:
        num.append(b)

print(len(num))