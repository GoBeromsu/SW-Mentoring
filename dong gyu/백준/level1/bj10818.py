num=int(input())
numbers=list(map(int,input().split()))
numbers.sort()

print(numbers[0],numbers[num-1])