# 프로그래밍 입문 실습 과제 #1

# 문제1

## 다음 print 함수가 실행될 수 있도록 프로그램을 완성하세요

```py
# 문제 1

#아래는 검증을 위한 코드로, 프로그램이 정상동작 하면 print가 실행됩니다.
assert play_to_Python == True
print("코드가 정상적으로 실행되었습니다.")
```

## 풀이

```py
# 문제 1

#아래는 검증을 위한 코드로, 프로그램이 정상동작 하면 print가 실행됩니다.
play_to_Python = True
assert play_to_Python == True
print("코드가 정상적으로 실행되었습니다.")
```

- 풀이 당시 상황
  - assert 함수가 무엇인지 구체적으로 잘 몰랐다.
  - 하지만 문제 그대로 돌려보니 play_to_Python 정의가 필요하다는 메시지가 떠서 play_to_Python = True라고 정의해 주었다.

## assert 함수란?

- assert는 뒤의 조건이 True가 아니면 AssertError를 발생한다.

예시
```py
>>> a = 3
>>> assert a == 2

#결과
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AssertionError
```

- 나중에 기회가 되면 assert함수에 대해 더 구체적으로 알아보자.

# 문제2

## 문자를 입력받으면 아스키 코드 값을 출력하는 프로그램을 작성하세요

<입력 예시>

문자를 입력하세요 : a

<출력 예시>

a는 아스키코드 97입니다.

## 풀이

```py
#문제 2
print('문자를 입력하세요 : ')
letter=input()
result=ord(letter)

print(letter,'는 아스키코드', result, '입니다.')
```

- 풀이 당시 상황
  - 문자를 아스키코드 값으로 바꿔주는 함수를 몰라서 찾아보니 ord함수를 찾았다.

## ord() 함수란?

- ord() 함수 : 특정한 한 문자를 아스키 코드 값으로 변환해 주는 함수

# 문제3

## 자연수를 인수로 받고, 홀수이면 True를, 짝수이면 False를 반환하는 odd_even 이라는 함수를 작성하세요

```py
# 문제 3

#아래는 함수 검증을 위한 코드로, 함수를 올바르게 정의하면, print가 실행됩니다. 

assert odd_even(1) == True
assert odd_even(2) == False

print("코드가 정상적으로 실행되었습니다.")
```

## 풀이

```py
# 문제 3

#아래는 함수 검증을 위한 코드로, 함수를 올바르게 정의하면, print가 실행됩니다. 

def odd_even(natural_number):
  if natural_number%2 == 1:
    return(True)

  elif natural_number%2 == 0:
    return(False)

print('자연수를 입력하세요 : ')
natural_number=int(input())
print(odd_even(natural_number))

assert odd_even(1) == True
assert odd_even(2) == False

print("코드가 정상적으로 실행되었습니다.")
```

- 풀이 당시 상황 : 함수의 반환값을 설정할때 시간이 많이 들었다. 반환 값을 return(natural_number)로 설정해서 3을 입력했는데 False가 나왔었는데 return(True)로 설정해서 올바른 값이 나왔다.

# 문제4

## 다음과 같이 주어진 리스트에서, 가장 큰 수와 가장 작은수를 제거하는 프로그램을 작성하세요

```py
#문제 4
number_list = [0, 11, 23, -9, 12, 16, 32, -2, -4, 29, 22, 23, 15, 31]
```

## 풀이

```py
#문제 4
number_list = [0, 11, 23, -9, 12, 16, 32, -2, -4, 29, 22, 23, 15, 31]
maximum=max(number_list)
minimum=min(number_list)
print('number_list내 최댓값:',maximum)
print('number_list내 최솟값:',minimum)

number_list.remove(maximum)
number_list.remove(minimum)
print('최댓값과 최솟값을 제거한 후 number_list:',number_list)
```

- 풀이 당시 상황 : max() 함수와 min() 함수를 잘 몰랐었다.

## max() 함수와 min() 함수

- max() 함수 : 인수로 받은 자료형 내에서 최소값을 찾아서 반환하는 함수
- min() 함수 : 인수로 받은 자료형 내에서 최소값을 찾아서 반환하는 함수

#  문제5

## 문자를 입력받으면, 대소문자를 반전시키는 프로그램을 작성하세요

<실행 결과>

문자를 입력하세요 : Hello Python

hEELO pYTHON

## 풀이

```py
#문제 5
print('문자를 입력하세요 : ')
sentence=input()
sentence.swapcase()
```

- 풀이 당시 상황 : swapcase() 함수를 잘 몰랐었다.

## swapcase() 함수

- a.swapcase() : 문자열 a의 대문자는 소문자로, 소문자는 대문자로 각각 바꾸어 준다.
  - a : 문자열 변수

# 문제6

## 다음과 같이 외화의 환율이 주어졌을때, 원화를 환전하는 프로그램을 작성하세요

1유로(EUR) = 1,345.24원(KWR)

1달러(USD) = 1,219.88원(KWR)

1루피(INR) = 16.05원(KWR)

<입력 예시>

환전할 금액(KWR) : 10000

<출력 예시>

EUR : 7.43

USD : 8.20

INR : 623.05

## 풀이

```py
print("환전할 금액(KWR) : ")
money=float(input())

EUR=money/1345.24
USD=money/1219.88
INR=money/16.05

print('EUR:','%.2f'%EUR)
print('USD:','%.2f'%USD)
print('INR:','%.2f'%INR)
```

- 풀이 당시 상황 : 소수점 자리를 내가 원하는 자리까지 반환하는 방법을 잘 몰라 Google에서 찾아 봤다.

## 소수점을 내가 원하는 자리만큼 나타내는 방법

- round() 함수와 format() 함수가 있다.
  - 구체적인 사용법은 필요할때 교재나 Google을 통해 알아보자

# 문제7

## 숫자를 입력받고, 숫자의 자릿수를 출력하는 프로그램을 작성하세요

단, 자연수만 입력을 받고 자연수가 아니라면, 오류 메시지를 출력하세요

출력 예시)

숫자를 입력하세요 : 11

11은 2자리수 입니다.

------------------------------------------

숫자를 입력하세요 : -19

잘못된 입력입니다.

## 풀이

```py
#문제 7

print("숫자를 입력하세요:")
a=input()

try:
  int(a)
  b=int(a)
  if b>0:
    print(b,'은', len(str(b)),'자리수 입니다.')

  elif b<=0:
    print('잘못된 입력입니다.')
 
except ValueError:
  print('잘못된 입력입니다.')
```

- 풀이 당시 상황 : 입력값이 정수일때는 조건문을 통해 쉽게 문제를 풀 수 있겠다는 생각이 들었지만 소수점이 포함된 숫자가 입력 되었을 때 '잘못된 입력입니다'를 띄울려고 하니 그동안 배운 것으로는 풀 수가 없겠다는 생각이 들었다.

- 그래서 Google을 통해 알아보니 try, except를 이용해서 정수와 실수형 자료를 구분 할 수 있는 방법을 찾았다.

- 아직 예외 처리를 배우지 않아서 나중에 배우면 그때 이 풀이를 다시 봐아겠다.

# 문제8

## 문자 한개를 입력 받고, 다음과 같은 리스트에서 해당 문자가 존재하는 과일의 이름과, 총 갯수를 출력하는 프로그램을 작성하세요

<입력 예시> 문자를 입력하세요 : a

<출력 예시>

tomato

strawberry

mango

guava

banana

carrot

cauliflower

eggplant

총 8개 입니다.

```py
#문제 8

fruits_and_veggies == ['tomato', 'strawberry', 'mango', 'kiwi', 'guava', 'banana', 'broccoli', 'carrot', 'cauliflower', 'eggplant', 'zucchini']
```

## 풀이

```py
fruits_and_veggies = ['tomato', 'strawberry', 'mango', 'kiwi', 'guava', 'banana', 'broccoli', 'carrot', 'cauliflower', 'eggplant', 'zucchini']
print('문자를 입력하세요 :')
alphabet=input()
fruits=[]

for word in fruits_and_veggies:
  if alphabet in word:
    print(word)
    fruits.append(word)
print('총',len(fruits),'개 입니다.')
```

- 풀이 당시 상황 : for문에 대한 이해와 len() 함수에 대한 이해가 부족해서 시간이 꽤 소요됬지만 이 문제를 통해 이해를 했다.
  - 위 코드는 len() 함수를 이용해서 fruits 리스트 개수를 출력했다.

# 문제9

## 디지털 시계는 다음과 같이 시:분(00:00)으로 표시됩니다.

디지털 시계에 하루(00:00 ~ 23:59)동안 2가 표시되어 있는 시간은 하루 중 총 몇 초인지 계산하는 프로그램을 작성하세요

## 풀이

```py
#문제 9
sum_hour=0
sum_min=0

for hour in range(0,24):
  if hour==2 or hour==12 or hour>=20:
    sum_hour=sum_hour+(60*60)

  elif hour!=2 or hour!=12 or hour<=20:

    for min in range(0,60):
      if min==2 or min==12 or min==32 or min==42 or min==52 or min>=20 and min<30:
        sum_min=sum_min+60

print('답:',sum_hour+sum_min)
```

- 풀이 당시 상황 : 2가 들어 있는 숫자를 컴퓨터가 자동으로 고르게 하는 코드를 짜지 못해 직접 고르는 코드를 짰다.
  - 사실 지금도 아직 모르겠다...

- or과 and를 반복해서 사용해봤는데 or이 들어가면 인접해 있는 것들끼리의 조건은 개별적으로 생각하고 and가 들어가면 인접해 있는 것들끼리의 조건을 한 묶음으로 인식하는 것 같았다.
  - 이건 개인적인 추측이다...

# 문제10

## 생년월일을 다음과 같이 입력받고, 입력받은 값을 통해 만 나이를 계산하는 프로그램을 작성하세요

단, 생년월일 입력은 다음과 같은 형식을 따릅니다. (월 일이 두자리가 아닌 경우 0을 포함)

연도(4자리).월(2자리).일(2자리) : 2007.04.03

<입력 예시>

생년월일을 입력하세요 : 2005.12.15

<출력 예시>

만 나이는 16세 입니다.

## 풀이

```py
#문제 10
from datetime import datetime
now_year=datetime.today().year
now_month=datetime.today().month
now_day=datetime.today().day

birthday=input('생년월일을 입력하세요 :').split('.')
birthday[0]=int(birthday[0])
birthday[1]=int(birthday[1])
birthday[2]=int(birthday[2])

standard=now_year-birthday[0]
if now_month>birthday[1]:
  print('만 나이는', standard,'세 입니다.')

elif now_month==birthday[1] and now_day<=birthday[2]:
  print('만 나이는', standard-1,'세 입니다.')

elif now_month==birthday[1] and now_day>birthday[2]:
  print('만 나이는', standard,'세 입니다.')

elif now_month<birthday[1]:
  print('만 나이는', standard-1,'세 입니다.')
```

- 풀이 당시 상황1 : 만 나이를 계산하려면 현재 날짜를 불러와야 하는데 방법을 몰라서 Google에 찾아보니 datetime 모듈을 이용하는 방법을 찾았다.
  - 아직 모듈에 대해 구체적으로 배우지 않아 정확한 작동 방식은 이해하지 못했다. (그냥 복붙했다.)
  - 이것도 나중에 모듈에 대해 배우면 위 풀이를 다시 살펴봐야 할 것 같다.

- 풀이 당시 상황2 : split() 함수에 대해 잘 몰랐다. 
  - split() 함수도 아직 배우지 않아 수업에서 배우면 위 풀이를 다시 살펴봐야 할 것 같다.

- 추가 사항 : now_year의 자료형은 int()형이다.

# 과제를 마치고...

프로그래밍입문 수업의 첫 실습 과제였다.

학교에서 다른 할 일이 많아 복습을 잘 하지 못하다 보니 과제하는데 시간이 많이 걸렸다.

특히 문제3 오류 찾기랑 

문제7에서 실수형 자료가 입력되었을 때 ValueError가 나와 코드가 실행되지 않는 것이 아닌 

'잘못된 입력입니다.'를 띄워야하는 코드를 짤때 시간이 많이 소요됬다.