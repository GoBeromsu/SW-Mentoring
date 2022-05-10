g=int(input())
z=[]

for i in range(g):
    h,w,n=map(int,input().split())
    if n%h!=0:
        z.append(str(n%h)+str(n//h+1).zfill(2))
    elif n%h==0:
        z.append(str(h)+str(n//h).zfill(2))

for k in range(g):
    print(z[k])