# 8장. 파이썬 스타일 코드(1)

파이썬 스타일 코드(pythonic code) : 파이썬 스타일의 코드 작성 기법

파이썬 스타일 코드가 익숙해지면 코드 자체도 간결해지고 코드 작성 시간도 줄일 수 있다.

- split(), join(), list comprehension, enumerate(), zip(), map(), reduce()와 같은 것들이 있다.
- 딕셔너리나 collection 모듈도 대표적인 파이썬 스타일 코드의 하나이다.

# 8-1. 문자열의 분리 및 결합

## 문자열의 결합 : join() 함수

문자열로 구성된 리스트를 합쳐 하나의 문자열로 반환할 때 사용한다.

- 사용법 : 구분자.join(리스트형)

예시

```py
colors=['red','blue','green','yellow']
result=''.join(colors)              
result
    #'redbluegreenyellow'
result=' '.join(colors)             #연결 시, 1칸을 띄고 연결
result
    #'red blue green yellow'
result=','.join(colors)             #연결 시, ','로 연결
result
    #'red,blue,green,yellow'
result='-'.join(colors)             #연결 시, '-'로 연결
result
    #'red-blue-green-yellow'
```

### 문자열의 분리는 split() 함수를 이용하면 된다.

# 8-2. 리스트 컴프리헨션(list comprehension)

다른 말로

'포괄형 리스트', '포함형 리스트', '지능형 리스트', '축약형 리스트'라고도 한다.

기존 리스트형을 사용하여 간단하게 새로운 리스트를 만드는 기법이다.

리스트와 for문을 한 줄에 사용할 수 있다.

예시

- 일반적인 반복문 + 리스트

```py
result=[]
for i in range(10):
    result.append(i)

result
    #[0,1,2,3,4,5,6,7,8,9]
```

- 리스트 컴프리헨션

```py
result=[i for i in range(10)]
result
    #[0,1,2,3,4,5,6,7,8,9]
```

[i for i in range(10)]에서 for i in range(10)은 range() 함수에서 값을 뽑아 i에 할당한다는 의미를 가지고 있으며 [i...] 부분은 i의 값이 리스트에 추가된다는 의미를 가지고 있다.

## 리스트 컴프리헨션 용법

다양한 용법이 있지만 대표적으로 필터링, 중첩 반복문, 이차원 리스트가 있다.

## 리스트 컴프리헨션의 기본 문법

```py
[<transformer_expression> for <iterator_variable> in <sequence> if <filteration_expression>]
```

## 필터링

if문과 함께 사용하는 리스트 컴프리헨션

예시

- 일반적인 반복문 + 리스트

```py
result=[]
for i in range(10):
    if i%2==0:
        result.append(i)

result
    #[0,2,4,6,8]
```

- 리스트 컴프리헨션

```py
result=[i for i in range(10) if i%2==0]
result
    #[0,2,4,6,8]
```

기존 리스트 컴프리헨션문 끝에 if i%2==0을 삽입하여 해당 조건을 만족할 때만 i를 추가한다.

만약 해당 조건을 만족하지 않아 else문을 사용하여 다른 값을 할당하려면 아래와 같이 하면 된다.

```py
result=[i if i%2==0 else 10 for i in range(10)]
result
    #[0,10,2,10,4,10,6,10,8,10]
```

if문을 앞으로 옮겨 else문과 함께 사용하면 조건을 만족하지 않을 때 else 뒤에 i 값을 할당하는 코드를 작성할 수 있다.

## 중첩 반복문(nested loop)

리스트 2개를 섞어 사용 가능하다.

2개의 for문을 만들 수 있다.

```py
word_1="Hello"
word_2="World"
result=[i+j for i in word_1 for j in word_2]    #중첩 반복문
result
    #['HW', 'Ho', 'Hr', 'Hl', 'Hd', 'eW', 'eo', 'er', 'el', 'ed', 'lW', 'lo', 'lr', 'll', 'ld', 'lW', 'lo', 'lr', 'll', 'ld', 'oW', 'oo', 'or', 'ol', 'od']
```

word_1에서 나오는 값을 먼저 고정한 후, word_2의 값을 하나씩 가져와 결과를 생성한다.

- 중첩 반복문에서의 필터링
  - 아래 코드처럼 반복문 끝에 if문을 추가하면 된다.

```py
case_1=['A','B','C']
case_2=['D','E','A']
result=[i+j for i in case_1 for j in case_2 if not(i==j)]
result
    #['AD', 'AE', 'BD', 'BE', 'BA', 'CD', 'CE', 'CA']
```

## 이차원 리스트(two-dimensional list)

하나의 정보를 열(row) 단위로 저장하는 이차원 리스트의 예시

- 방법1 - 대괄호 2개 사용하기

```py
words='The quick brown fox jumps over the lazy dog'.split()
stuff=[[w.upper(),w.lower(),len(w)] for w in words]

for i in stuff:
    print(i)

    #['THE', 'the', 3]
    #['QUICK', 'quick', 5]
    #['BROWN', 'brown', 5]
    #['FOX', 'fox', 3]
    #['JUMPS', 'jumps', 5]
    #['OVER', 'over', 4]
    #['THE', 'the', 3]
    #['LAZY', 'lazy', 4]
    #['DOG', 'dog', 3]
```

- 방법2 - for문 2개를 붙여서 사용
  - 주의 사항 : 대괄호의 위치에 따라 for문의 실행이 달라진다.

코드1

```py
case_1=['A','B','C']
case_2=['D','E','A']
result=[i+j for i in case_1 for j in case_2]
result
    #['AD', 'AE', 'AA', 'BD', 'BE', 'BA', 'CD', 'CE', 'CA']
```

- 앞에 있는 for문이 먼저 실행된 후, 뒤의 for문이 실행 됨.

코드2

```py
case_1=['A','B','C']
case_2=['D','E','A']
result=[[i+j for i in case_1] for j in case_2]
result
    #[['AD', 'BD', 'CD'], ['AE', 'BE', 'CE'], ['AA', 'BA', 'CA']]
```

- 뒤에 있는 for문이 먼저 실행 됨.

아래 있는 두 코드는 꼭 구분해야 한다.

```py
[i+j for i in case_1 for j in case_2]
[[i+j for i in case_1] for j in case_2]
```

- 코드1은 일차원 리스트를 만들고, 앞의 for문이 먼저 실행된다.
- 코드2는 이차원 리스트를 만들고, 뒤의 for문이 먼저 실행된다.

## 리스트 컴프리헨션의 성능

- 문법적으로 간결성이 높다.
- 기존 for문보다 시간 면에서 효율적인 연산 수행이 가능하다.

# 8-3. 다양한 방식의 리스트값 출력

## enumerate() 함수

리스트의 값을 추출할 때 인덱스를 붙여 함께 출력하는 방법이다.

(주로 for문과 함께 사용된다.)

```py
for i,v in enumerate(['tic','tac','toe']):
    print(i,v)

    #0 tic
    #1 tac
    #2 toe
```

- 인덱스와 리스트의 값이 언패킹되어 추출되는 것을 볼 수 있다.

enumerate() 함수는 주로 딕셔너리형으로, 인덱스를 key로, 단어를 value로 하여 쌍으로 묶어 결과를 출력하는 방식을 사용한다.

```py
{i:j for i,j in enumerate('TEAMLAB is an academic institute located in South Korea.'.split())}

    #{0: 'TEAMLAB', 1: 'is', 2: 'an', 3: 'academic', 4: 'institute', 5: 'located', 6: 'in', 7: 'South', 8: 'Korea.'}
```

## zip() 함수

1개 이상의 리스트값이 같은 인덱스에 있을 때 병렬로 묶는 함수이다.

```py
alist=['a1','a2','a3']
blist=['b1','b2','b3']
for a,b in zip(alist,blist):    #병렬로 값을 추출
    print(a,b)

    #a1 b1
    #a2 b2
    #a3 b3
```

두 리스트 모두 3개의 값이 있어, 같은 인덱스의 값을 묶어 출력한다.

- 주의 사항

  - zip() 함수로 넘기는 인자의 길이가 다를 때는 주의해야 한다. 가장 짧은 인자를 기준으로 데이터가 엮이고, 나머지는 버려지기 때문이다.

```py
num = ["1", "2", "3"]
letter = ["A"]
list(zip(num, letter))
    #[('1', 'A')]
```

## zip() 함수, enumerate() 함수 응용

예시1

```py
a,b,c=zip((1,2,3),(10,20,30),(100,200,300))
print(a,b,c)
    #(1,10,100)(2,20,200)(3,30,300)
[sum(x) for x in zip((1,2,3),(10,20,30),(100,200,300))]
    #[111,222,333]
```

예시2

```py
alist=['a1','a2','a3']
blist=['b1','b2','b3']
for i, (a,b) in enumerate(zip(alist,blist)):
    print(i,a,b)    #(인덱스,alist[인덱스],blist[인덱스]) 표시
    
    #0 al bl
    #1 a2 b2
    #2 a3 b3
```