import sys

inputs=list(map(int,input().split()))

x=inputs[0]
y=inputs[1]
w=inputs[2]
h=inputs[3]

arr=[x,y,(w-x),(h-y)]

print(sorted(arr)[0])