num=int(input())
score=list(map(int,input().split()))
mv=max(score)
list1=[]

for i in range(num):
    after_score=score[i]/mv*100
    list1.append(after_score)

sum_list=sum(list1)/num
print(sum_list)