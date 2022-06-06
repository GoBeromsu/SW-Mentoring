# 9장. 파이썬 스타일 코드(2)

# 9-1. 람다(lambda) 함수

함수의 이름 없이 함수처럼 사용할 수 있는 익명의 함수를 말한다.

(람다 함수는 일반적으로 이름을 지정하지 않아도 사용할 수 있다.)

- 일반적인 함수

```py
def f(x,y):
    return x+y

print(f(1,4))

    #5
```

- 람다 함수

```py
f=lambda x,y:x+y
print(f(1,4))

    #5
```

위의 두 코드는 입력된 x,y의 값을 더하여 그 결과를 반환하는 함수이다.

람다 함수는 별도의 def나 return을 작성하지 않는다.

앞에는 매개변수의 이름을, 뒤에는 매개변수가 반환하는 결과값인 x+y를 작성한 것이다. 기존의 f 함수와 구조는 같고 표현이 다르다.

- 람다 함수를 표현하는 다른 방식

```py
print((lambda x:x+1)(5))

    #6
```

위 코드처럼 이름 없이 사용 가능하다.

일반적으로는 어떤 변수에 람다 함수를 할당하여 함수와 비슷한 형태로 사용한다.

```py
f=lambda x:x/2
f(3)
    #1.5
f(3,5)

Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: <lambda>() takes 1 positional argument but 2 were given
```

매개변수를 1개로 선언했는데 f(3,5)와 같이 2개 이상의 값이 들어와서 오류가 발생했다.

이는 함수에서 매개변수의 개수를 넘어가는 인수가 입력될 때의 결과와 같다.

# 9-2. 맵리듀스

파이썬뿐 아니라, 빅데이터를 처리하기 위한 기본 알고리즘으로도 많이 사용한다.

맵리듀스에는 map() 함수와 reduce() 함수가 있다.

## map() 함수

연속 데이터를 저장하는 시퀸스 자료형에서 요소마다 같은 기능을 적용할 때 사용한다.

일반적으로 리스트나 튜플처럼 요소가 있는 시퀸스 자료형에 사용된다.

```py
ex=[1,2,3,4,5]
f=lambda x:x**2
print(list(map(f,ex)))
    #[1,4,9,16,25]
```

map(f,ex) : 함수 f를 ex의 각 요소에 맵핑(mapping)하라는 뚯이다.

![KakaoTalk_20220523_144951431](https://user-images.githubusercontent.com/102230809/169752118-d05db7e4-0dfd-4884-a601-3ea23b874d16.jpg)

## map() 함수 특징

- 한 개 이상의 시퀸스 자료형 데이터의 처리

```py
ex=[1,2,3,4,5]
f=lambda x,y : x+y
list(map(f,ex,ex))
    #[2,4,6,8,10]
```

위 코드를 리스트 컴프리헨션으로 변경하면 아래와 같다.

```py
[x+y for x,y in zip(ex,ex)]
    #[2,4,6,8,10]
```

- 필터링(filtering) 기능
  - 리스트 컴프리헨션과 달리 else문을 반드시 작성해 해당 경우가 존재하지 않는 경우를 지정해 주어야 한다.

```py
list(map(lambda x:x**2 if x%2==0 else x, ex))   #map() 함수
    #[1,4,3,16,5]
[x**2 if x%2==0 else x for x in ex]         #리스트 컴프리헨션
    #[1,4,3,16,5]
```

## reduce() 함수

기본 문법

```py
from functools import reduce

reduce(함수(일반적 함수 또는 람다 함수),순회 가능한 데이터, 초기값)
```

여기서 함수는 두 개의 인자를 받아야 한다.

첫 번째 인자는 누적자(accumulator), 두 번째 인자는 현재값(current value)가 넘어온다.

예시

```py
from functools import reduce
print(reduce(lambda x,y: x+y,[1,2,3,4,5]))
    #15
```

앞의 x는 기존의 x+y를 적용한 값을 계속 저장하는 변수(accumulator)이다.

뒤의 y는 리스트에 있는 값을 하나씩 할당 받는 변수(current value)이다.

![KakaoTalk_20220523_223732440](https://user-images.githubusercontent.com/102230809/169832425-0966a339-e907-4012-9c0f-d5aa5060a1ed.jpg)

# 9-3. 별표(asterisk)의 활용

별표(asterisk)는 곱하기 기호(*)를 뜻한다.

기본 연산자로, 단순 곱셈이나 제곱 연산에 많이 사용된다.

여기서는 별표를 사용하는 특별한 경우에 대해 알아보자.

## 가변 인수(variable length arguments)를 사용할 때

변수명 앞에 별표를 붙인다.

- 가변 인수

```py
def asterisk_test(a,*args):
    print(a,args)
    print(type(args))

asterisk_test(1,2,3,4,5,6)
    # 1 (2, 3, 4, 5, 6)
    # <class 'tuple'>
```

- 키워드 가변 인수

```py
def asterisk_test(a,**kargs):
    print(a,kargs)
    print(type(kargs))

asterisk_test(1, b=2, c=3, d=4, e=5, f=6)
    # 1 {'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6}
    # <class 'dict'>
```

여러 개의 변수를 담는 container 로서의 속성이 별표(*)에 있다.

- 컨테이너란, 일종의 데이터를 담는 그릇이다. 여러 개의 변수를 한꺼번에 넣는 기능을 한다.

## 별표의 언패킹 기능

여러 개의 데이터를 담는 리스트, 튜플, 딕셔너리와 같은 자료형에서는 해당 데이터를 언패킹하는 기능을 한다.

- 예시

```py
def asterisk_test(a,args):
    print(a,*args)
    print(type(args))

asterisk_test(1,(2,3,4,5,6))
    # 1 2 3 4 5 6
    #<class 'tuple'>
```

```py
def asterisk_test(a,*args):
    print(a,args)
    print(type(args))

asterisk_test(1,*(2,3,4,5,6))
    # 1 (2, 3, 4, 5, 6)
    #<class 'tuple'>
```

```py
a,b,c=([1,2],[3,4],[5,6])
print(a,b,c)
    #[1,2][3,4][5,6]
data=([1,2],[3,4],[5,6])
print(*data)
    #[1,2][3,4][5,6]
```

```py
for data in zip(*[[1,2],[3,4],[5,6]]):
    print(data)
    print(type(data))

#(1,3,5)
#<class 'tuple'>
#(2,4,6)
#<class 'tuple'>
```

```py
def asterisk_test(a,b,c,d,):
    print(a,b,c,d)

data={"b":1, "c":2, "d":3}
asterisk_test(10,**data)

    #10 1 2 3
```

자세한 내용은 교제 p.306~308을 참고하자

# 9-4. 선형대수학

백터(vector)와 행렬(matrix)을 다루는 분야이다.

## 파이썬 스타일 코드로 표현한 벡터

```py
vector_a=[1,2,10]               #리스트로 표현
vector_b=(1,2,10)               #튜플로 표현
vector_c={'x':1,'y':1,'z':10}   #딕셔너리형으로 표현
```

- 데이터의 위치나 순서가 바뀌는 것을 막으려면 튜플로 저장한다.
- 데이터의 이름과 같은 정보를 함께 저장해야 한다면 딕셔너리로 표현한다.

## 벡터의 연산

```py
u=[2,2]
v=[2,3]
z=[3,5]

result = [sum(t) for i in zip(u,v,z)]
print(result)
    #[7,10]
```

## 별표를 사용한 함수화

만약 4개 이상의 변수일 경우에는 별표를 사용하여 아래와 같이 처리 가능하다.

```py
def vector_addition(*args):
    return [sum(t) for t in zip(*args)]

vector_addition(u,v,z)
    #[7,10]
```

- vector_addition함수에서 *args를 사용하여 여러 개의 변수를 입력받는 가변 인수로 사용한 뒤 실제 함수에서 args에 별표( * )를 이용하여 언패킹 하였다.
  - sum(t) for t in zip(u,v,z)와 같은 코드이다.

위 코드에서 변수가 3개이다. 변수의 개수를 줄이기 위해서는 아래와 같이 코드를 짤 수 있다.

```py
row_vectors=[[2,2],[2,3],[3,5]]
vector_addition(*row_vectors)
    #[7,10]
```

이차원 리스트를 만든 후 별표의 언패킹으로 해결했다.

## 스칼라-벡터 연산

```py
u=[1,2,3]
v=[4,4,4]
alpha=2

result=[alpha*sum(t) for t in zip(u,v)]
result
    #[10, 12, 14]
```

## 파이썬 스타일 코드로 표현한 행렬

```py
matrix_a = [[3,6], [4,5]]
#리스트로 표현
matrix_b = [(3,6), (4,5)]
#튜플로 표현
matrix_c = {(0,0): 3, (0,1): 6, (1,0): 4, (1,1): 5}
#딕셔너리로 표현
```

```py
[[첫 번째 행], [두 번째 행], [세 번째 행]]
```

- 행렬은 딕셔너리로 표현할 때, 많은 경우의 수를 표현할 수 있다.
  - 행과 열의 좌표 정보, 이름 정보 등을 넣을 수 있다.

## 행렬의 연산

### 덧셈과 뺄셈

2개 이상의 행렬을 연산하기 위해 각 행렬의 크기(차원)는 같아야 한다.

![KakaoTalk_20220606_221549079](https://user-images.githubusercontent.com/102230809/172168112-89e3d8c9-910f-43fd-b09a-1e21d3b107ec.jpg)

A가 2x2 행렬이면 B도 2x2행렬 이여야 한다.

위 그림을 코드로 표현해 보자

```py
matrix_a=[[3,6],[4,5]]
matrix_b=[[5,8],[6,7]]
result=[[sum(row) for row in zip(*t)] for t in zip(matrix_a,matrix_b)]

print(result)
    #[[8,14],[10,12]]
```

- 위 코드의 핵심은 zip() 함수와 *를 어떻게 사용하는가 이다.

### 행렬의 동치

두 개의 행렬이 같다면 동치라고 한다.

![KakaoTalk_20220606_223003577](https://user-images.githubusercontent.com/102230809/172170299-20b2af1d-d445-40c0-9680-701b29b6d65a.jpg)

- 두 행렬이 동치임을 확인하는 코드를 작성해 보자.(불린형 이용)

```py
matrix_a=[[1,1],[1,1]]
matrix_b=[[1,1],[1,1]]
all([row[0]==value for t in zip(matrix_a,matrix_b) for row in zip(*t) for value in row])
    #True

matrix_b=[[5,8],[6,7]]
all([all([row[0]==value for value in row]) for t in zip(matrix_a, matrix_b) for row in zip(*t)])
    #False
```

- 위 코드의 핵심은 각 요소의 값을 비교하는 row[0] == value 코드이다.

### all(), any() 함수

- all() : 안에 있는 모든 값이 참일 경우에만 True를 반환한다.
  - (and 조건으로 리스트의 값들이 모두 같은지 확인한다.)
- any() : 하나라도 참이 있으면 True를 반환한다.
  - 모두가 거짓일때는 False를 반환한다. (or 조건)

위 코드에서 all() 함수가 중간에 없다면 아래 코드와 같이 출력된다.

```py
[[row[0] == value for value in row] for t in zip(matrix_a, matrix_b) for row in zip(*t)]
    #[[True, False], [True, False], [True, False], [True, False]]
```

### 전치행렬(transpose matrix)

전치행렬은 주어진 m(행) x n(열)의 행렬에서 행과 열을 바꾸어 만든 행렬이다.

![KakaoTalk_20220606_232529881](https://user-images.githubusercontent.com/102230809/172180903-795a46c9-98eb-4ecf-bcc8-e64ed8258e1a.jpg)

- 전치행렬 소스코드

```py
matrix_a=[[1,2,3], [4,5,6]]
result = [[element for element in t] for t in zip(*matrix_a)]
result
    #[[1, 4], [2, 5], [3, 6]]
```

### 행렬의 곱셈

행렬 곱셈을 위한 조건 (적합성 조건)

![KakaoTalk_20220606_233421135](https://user-images.githubusercontent.com/102230809/172182574-79f45839-1070-4379-acf1-fd88eaa2294d.jpg)

- 앞 행렬의 열과 뒤 행렬의 행의 크기가 같아야 한다.

행렬의 곱셈

![KakaoTalk_20220606_233805562](https://user-images.githubusercontent.com/102230809/172183761-7c3b774f-deaa-40f4-a555-5fb2f5560d4d.jpg)

- 앞 행렬 행 x 뒤 행렬 열

코드로 구현

```py
matrix_a=[[1,1,2], [2,1,1]]
matrix_b=[[1,1], [2,1], [1,3]]
result=[[sum(a*b for a, b in zip(row_a, column_b)) for column_b in zip(*matrix_b)] for row_a in matrix_a]
result
    #[[5, 8], [5, 6]]
```

- 전치 행렬의 코드 기법을 사용하여 한 행렬에서는 열의 값을, 다른 행렬에서는 행의 값을 추출하여 곱하는 코드로 구성해야 한다.