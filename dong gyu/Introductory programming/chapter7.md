# 7장. 자료구조(data structure)

자료구조 : 데이터의 특징을 고려하여 데이터를 저장하는 방법

![KakaoTalk_20220511_214846696](https://user-images.githubusercontent.com/102230809/167853761-27be6712-061c-4318-bdde-a5fe8b8dde2e.jpg)

- 시스템을 만드는 데 필요한 데이터를 효율적으로 배치하는 것은 '자료구조'
- 시스템을 구현하고 실행 순서 및 방법을 체계적으로 표현하는 것은 '알고리즘'

## 배열(Array)

배열 : 자료형이 같은 데이터를 순서대로 나열한 뒤 메모리에 연속으로 저장해 만든 자료 그룹.

- 2차원 배열 : 인덱스를 2개 사용하는 배열
  - 첫 번째 인덱스는 행을, 두 번째 인덱스는 열을 나타냄.

![KakaoTalk_20220511_215657409](https://user-images.githubusercontent.com/102230809/167855524-360ab1b9-029f-4483-af62-010bcbe01838.jpg)

## 연결 리스트(Linked List)

연결 리스트 : 각 데이터에 저장된 다음 데이터의 주소(링크)에 따라 순서가 연결되는 방식.

- 배열의 문제를 개선함.
- 데이터의 논리적인 순서와 물리적인 순서가 일치하지 않아도 됨.

연결 리스트의 구조

- 노드(Node) : 연결 리스트는 <원소,주소> 단위로 구성되어 있으며 다음에 이어질 데이터에 대한 주소를 포함하는데, 이를 합쳐서 노드라고 한다.
- 노드의 구조 : 데이터 필드와 링크 필드

연결 리스트의 분류

- 단순 연결 리스트(Singly Linked List)
  - 노드의 링크 필드가 하나이며, 링크 필드는 다음 노드와 연결되는 가장 기본 구조.
- 원형 연결 리스트(Circular Linked List)
  - 단순 연결 리스트의 마지막 노드가 리스트의 첫 번째 노드를 가리키게 하여 리스트 구조를 원형으로 만든 구조.
- 이중 연결 리스트(Doubly Liked List)
  - 양쪽으로 모두 순회할 수 있도록 노드를 연결해 단순 연결 리스트와 원형 연결 리스트의 단점을 보완한 구조.

연결 리스트에 데이터를 추가하는 방법

![KakaoTalk_20220511_224351161_01](https://user-images.githubusercontent.com/102230809/167864863-0e625603-0935-4160-b494-9fa35be5f6f9.jpg)

연결 리스트에 데이터를 삭제하는 방법

![KakaoTalk_20220511_224351161](https://user-images.githubusercontent.com/102230809/167865077-1bafba7c-7dc6-4296-a1a6-2d049c20375d.jpg)

## 비선형 자료구조(Non-linear Data Structure)

비선형 자료구조 : 데이터 간의 상관관계를 연결 상태로 표현해야 할 때 사용하는 구조

비선형 자료구조의 종류 : 트리, 그래프

## 트리(Tree)

트리 : 나무를 뒤집어 놓은 모습의 자료구조로, 데이터들이 1:n 관계인 비선형 구조로 놓여 있음

- 트리는 노드와 간선의 집합으로 이루어져 있음.
  - 노드(Node) : 트리의 원
  - 간선(Edge) : 노드와 노드를 연결한 선
- 트리는 계층 관계를 가진다. 트리의 노드를 이용해 부모-자식 관계를 표현할 수 있다.
  - 루트 노드 : 트리 맨 위에 위치한 노드
  - 단말 노드 : 가장 아래에 위치한 노드들

## 이진 트리(Binary Tree)

이진 트리 : 노드의 자식 노드를 2개 이하로 정해 놓은 구조. 왼쪽과 오른쪽, 최대 2개의 자식 노드만 가질 수 있다.

## 그래프(Graph)

그래프 : 연결된 데이터들이 n:n(다:다) 관계를 표현하는 자료구조.

- 연결할 객체를 나타내는 정점과 객체를 연결하는 간선의 집합.
- 그래프(G)는 G=(V,E)로 정의. V는 그래프에 있는 정점의 집합을, E는 정점을 연결하는 간선의 집합을 뜻함.
  - 그래프와 트리의 차이점 : 그래프에는 사이클이 존재

그래프의 분류

- 무방향 그래프 : 두 정점을 연결하는 간선의 방향이 정해져 있지 않은 그래프
- 방향 그래프 : 간선에 방향이 정해져 있는 그래프

# 7-1. 스택과 큐

## 스택(Stack)

스택(Stack) : 데이터를 차곡차곡 쌓아 올린 형태로 구성된 자료구조

- Top으로 정해진 맨 위에서만 데이터의 추가, 삭제 작업이 가능하며, 구조의 중간에서는 데이터 추가와 삭제가 불가능 함.
- LIFO(Last In First Out) : 가장 마지막에 삽입된 데이터가 가장 먼저 삭제 되는 구조

스택에서 데이터 추가 및 삭제

- 푸시(Push) : 스택에서 데이터를 추가(저장)하는 작업.
  - append() 함수 : 리스트 끝에서 새 항목 추가
- 팝(Pop) : 데이터를 삭제(추출)하는 작업.
  - pop() 함수 : 리스트 끝 항목을 삭제하는 함수

![KakaoTalk_20220512_163047442](https://user-images.githubusercontent.com/102230809/168016475-272d01e6-2232-497e-b336-609e83789e29.jpg)

```py
a-[1,3,5,7,9]
a.append(15)
a
  [1,3,5,7,9,15]
a.append(20)
a
  [1,3,5,7,9,15,20]
a.pop()
  20
a.pop()
  15
```

## 큐(Queue)

큐(Queue) : 데이터가 한 방향에서만 삽입되고 반대 방향으로만 삭제되는 자료 구조. (스택의 반대 개념)

- 한쪽 끝을 Front로 정해 삭제 연산만 수행하고, 다른 쪽 끝을 Rear로 정해 삽입 연산만 수행.
- FIFO(First In First Out) : 먼저 삽입된 데이터가 먼저 삭제 되는 구조

큐에서 데이터 추가 및 삭제

- 기본 구조는 스택 구현 방법과 같음.
- pop() 함수는 리스트의 마지막 값을 삭제하는 함수이므로, 인덱스가 0번째인 값을 추출한다는 의미롤 pop(0)을 사용하면 됨.4

![KakaoTalk_20220512_172508093](https://user-images.githubusercontent.com/102230809/168026436-f919ad4f-c2ce-4f19-912c-6441b06e8258.jpg)


```py
a=[1,2,3,4,5]
a.append(10)
a.append(20)
a.pop(0)
  1
a.pop(0)
  2
```

# 7-2. 튜플과 세트

## 튜플(tuple)

튜플 : 값을 변경하는 것이 불가능한 리스트

```py
t=(1,2,3)
print(t+t,t*2)
  (1,2,3,1,2,3) (1,2,3,1,2,3)
```

- 대괄호[]를 이용하는 리스트와 차이가 있다.
- 선언 외에 여러 가지 연산은 리스트와 같다.
  - 리스트에서 사용하는 연산, 인덱싱, 슬라이싱이 모두 동일하게 적용된다.
- 튜플의 값이 하나만 있다면 t=(1)이 아닌 t=(1,)로 선언을 해야한다.
  - 반드시 콤마(,)를 붙여 t가 튜플임을 선언해야 한다.
  - t=(1)은 인터프리터가 t=1로 인식한다.

```py
t[1]=5
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment
```

- 튜플의 값을 변경하려고 하면 위와 같이 오류가 발생한다.

## 세트(set)

세트 : 값을 순서 없이 저장하면서 중복을 불허하는 자료형. 튜플과 다르게 삭제 및 변경이 가능하며, 다양한 집합 연산을 제공한다.

```py
s=set([1,2,3,1,2,3])
#set() 함수를 사용하여 1,2,3을 세트 객체로 생성
s
  {1,2,3}
```

- 세트를 사용하기 위해 set() 함수를 사용하여 리스트나 튜플의 데이터를 넣으면 해당 값이 세트 형태로 변환된다.
- 순서가 없기 때문에 리스트처럼 인데스 번호를 사용하여 특정 값에 접근할 수 없다.

```py
s
  {1,2,3}
s.add(1)               #1을 추가하라는 명령, 중복 불허로 추가X
s
  {1,2,3}
s.remove(1)            #1 삭제
s
  {2,3}
s.update([1,4,5,6,7])  #[1,4,5,6,7] 추가
s
  {1,2,3,4,5,6,7}
s.discard(3)           #3 삭제
s
  {1,2,4,5,6,7}
s.clear()              #모든 원소 삭제
s
  set()
```

- add() : 원소 하나 추가
- remove() / discard() : 원소 하나 제거
- update() : 새로운 리스트를 그대로 추가
- clear() : 모든 변수 지우기

세트의 집합 연산

```py
s1=set([1,2,3,4,5])
s2=set([3,4,5,6,7])

s1.union(s2)        #s1과 s2의 합집합
  {1,2,3,4,5,6,7}
s1|s2
  {1,2,3,4,5,6,7}
s1.intersection(s2) #s1과 s2의 교집합
  {3,4,5}
s1&s2
  {3,4,5}
s1.difference(s2)   #s1과 s2의 차집합
  {1,2}
s1-s2
  {1,2}
```

![KakaoTalk_20220513_102704523](https://user-images.githubusercontent.com/102230809/168193240-ee4ad4a7-c1ef-4721-a4de-c48073fa098d.jpg)

# 7-3. 딕셔너리

딕셔너리(dictionary) : key와 value 형태로 데이터를 저장하는 자료구조

딕셔너리의 선언

```py
딕셔너리 변수={키1:값1, 키2:값2, 키3:값3, ...}
```

![KakaoTalk_20220513_103914207](https://user-images.githubusercontent.com/102230809/168194306-b2fed759-d15a-4dca-a919-de34ade6bfe3.jpg)

위 표의 정보를 파이썬으로 표현해 보자

```py
student_info={20140012:'Janhyeok',20140059:'Jiyong',20140058:'JaeHong'}
```

student_info변수에서 특정 값을 호출하는 방법

```py
student_info[20140012]
  'Janhyeok'
```

- 해당 값의 키를 대괄호 [] 안에 넣어 호출한다.
  - 키는 문자열, 정수형 등으로 호출 할 수 있다.
  - 위 코드는 정수형으로 호출했다.
  - 변수의 자료형을 정확히 모르고 호출하면 리스트로 오해할 수도 있으니 주의하자.

딕셔너리의 재할당과 추가

```py
student_info[20140012]='Sungchul'
student_info[20140012]
  'Sungchul'
student_info[20140039]='Wonchul'
student_info
  {20140012: 'Sungchul', 20140059: 'Jiyong', 20140058: 'JaeHong', 20140039: 'Wonchul'}
```

- 재할당 방식은 리스트와 같다.
- 추가하는 방식은 새로운 키를 사용하여 값을 할당한다.

## 딕셔너리 함수

- keys() : 딕셔너리에서 키만 출력한다
- values() : 딕셔너리에서 값만 출력한다.
- items() : 키-값 쌍을 모두 출력한다.

실제로 딕셔너리를 사용할 때 for문과 함께 사용한다.

```py
country_code={"America":1,"Korea":82,"China":86,"Japan":81,"German":49}

for k,v in country_code.items():
  print("Key:",k)
  print("Value:",v)
```

출력

```
Key: America
Value: 1
Key: Korea
Value: 82
Key: China
Value: 86
Key: Japan
Value: 81
Key: German
Value: 49
```

또한 if문을 사용하여 특정 키나 값이 해당 변수에 포함되어 있는지 확인 가능하다.

# 7-4. collection 모듈

- 파이썬의 내장 자료구조(built-in data structure) 모듈이다.
- 리스트, 튜플, 딕셔너리 등을 확장하여 제작된 파이썬의 내장 모듈이다.
- deque, OrderedDict, defaultdict, Counter, namedtuple 등을 제공한다.

자료구조를 호출하는 코드

```py
from collections import deque
from collections import OrdereDict
from collections import defaultdict
from collections import Counter
from collections import nametuple
```

## deque 모듈

스택과 큐를 모드 지원하는 모듈

- deque 모듈을 사용하려면 리스트와 비슷한 형식으로 데이터를 저장해야 한다.
  - append() 함수를 사용할 수 있다.

```py
from collections import deque

deque_list=deque()
for i in range(5):
  deque_list.append(i)

print(deque_list)
  deque([0,1,2,3,4])
```

- 여기에서 deque_list.pop()를 작성하면 오른쪽 요소부터 하나씩 추출된다.
  - 스택처럼 나중에 넣은 값부터 하나씩 추출 가능하다.

```py
deque_list.pop()
  4
deque_list.pop()
  3
deque_list.pop()
  2
deque_list
  deque([0,1])
```

큐를 실행하려면 pop(0)을 입력하면 안 된다. pop(0)은 deque에서 작동하지 않는다.

대신 appendleft() 함수로 새로운 값을 왼쪽부터 입력되게 하여 먼저 들어간 값부터 출력 가능하도록 한다.

```py
from collections import deque

deque_list=deque()
for i in range(5):
  deque_list.appendleft(i)

print(deque_list)
  deque([4,3,2,1,0])
```

deque 모듈의 장점 : 연결 리스트의 특성을 지원한다.

- 연결 리스트의 특징 때문에 가능한 기능 중 하나가 rotate() 함수이다.
- rotate()는 기존 deque에 저장된 요소들의 값 인덱스를 바꾸는 기법이다.

```py
from collections import deque

deque_list=deque()
for i in range(5):
  deque_list.append(i)

print(deque_list)
  deque([0,1,2,3,4])
deque_list.rotate(2)
print(deque_list)
  deque([3,4,0,1,2])
deque_list.rotate(2)
  deque([1,2,3,4,0])
```

deque 모듈은 다양한 기능을 제공한다.

- reversed() 함수 : 기존과 반대로 데이터를 저장.
- deque 모듈은 기존의 리스트에서 지원하는 함수도 지원한다.

```py
print(deque(reversed(deque_list)))
  deque([0,4,3,2,1])
```

- TIP -> 대용량의 큐나 스택을 처리할 때 deque를 사용하면 좋다.

## OrderedDict 모듈

순서를 가진 딕셔너리 객체.

보통 딕셔너리 파일을 저장하면 키는 저장 순서와 상관없이 저장된다.

```py
d = {}
d['x'] = 100
d['l'] = 500
d['y'] = 200
d['z'] = 300

for k, v in d.items():
    print(k, v)
  
  x 100
  l 500
  y 200
  z 300
```

위 코드의 결과는 컴퓨터 마다 다를 수 있다.

하지만 OrdereDict는 키의 순서를 보장한다. 가장 기본적인 방법으로 입력한 순서대로 결과를 화면에 출력하는 것이다.

```py
from collections import OrderedDict   #OrderedDict 모듈 선언

d=OrderedDict()
d['x']=100
d['y']=200
d['z']=300
d['l']=500

for k,v in d.items():
  print(k,v)

  x 100
  y 200
  z 300
  l 500
```

위 코드를 실행하면 어떤 컴퓨터든 상관없이 x,y,z,l 순서대로 키-쌍 값이 출력된다.

### 추가

입력한 순서와 다른 방식으로 OrderedDict를 사용하는 방법

```py
def sort_by_key(t):
  return t[0]

from collections import OrderedDict

d=dict()
d['x']=100
d['y']=200
d['z']=300
d['l']=500

for k,v in OrderedDict(sorted(d.items(),key=sort_by_key)).items():
  print(k, v)

  l 500
  x 100
  y 200
  z 300
```

위 코드는 key를 기준으로 딕셔너리를 배열하고 OrderedDict를 사용했다.

아래 코드를 조금 더 살펴보자

```py
sorted(d.items(),key=sort_by_key)
```

실행 결과-1

```py
[('l',500),('x',100),('y',200),('z',300)]
```

기존의 딕셔너리 변수들을 key 값을 기준으로 정렬하고 sorted() 함수를 이용하여 리스트로 만든 것을 알 수 있다.

- sort() 함수와 sorted() 함수의 차이점은 google을 통해 알아보자.

여기서 value 값을 기준으로 정렬한다면 함수 정의 부분을 아래와 같이 바꾸면 된다.

```py
def sort_by_value(t):
  return t[1]
```

t[0]과 t[1]은 각각 실행 결과-1의 리스트 안의 튜플 값 중 0번째 인덱스(l,x,y,z)와 1번째 인덱스(500,100,200,300)을 뜻한다.

## defaultdict 모듈

딕셔너리의 변수를 생성할 때 키에 기본 값을 지정하는 방식이다.

새로운 키를 생성할 때 별다른 조치 없이 신규 값을 생성할 수 있다.

실제 딕셔너리에서는 키에 대응하는 값이 없으면 오류가 발생한다.

defaultdict가 작용하는 예시를 살펴 보자.

```py
from collections import defaultdict

d=defaultdict(lambda: 0)      #Default 값을 0으로 설정
print(d["first"])

  0
```

어떤 키가 들어와도 처음 값은 전부 0으로 설정한다는 뜻이다.

```py
from collections import defaultdict

s=[('yellow',1),('blue',2),('yellow',3),('blue',4),('red',1)]
d=defaultdict(list)
for k,v in s:
  d[k].append(v)

print(d.items())
```

출력

```py
dict_items([('yellow',[1,3]),('blue',[2,4]),('red',[1])])
```

- d=defaultdict(list)로 초깃값을 리스트로 선언한다.
- 모든 값이 리스트에 들어가 for문을 사용하여 새로운 값을 추가한다.
- 위와 같은 절차를 따르면 s변수 처럼 같은 이름을 가진 여러 개의 key가 생긴다.

defaultdict모듈은 이런 키의 값들을 하나로 만들 때 사용할 수도 있다.

## Counter 모듈

시퀸스 자료형(리스트, 튜플)의 데이터 요소 개수를 딕셔너리 형태로 반환하는 자료구조이다.

즉, 리스트나 문자열과 같은 시퀸스 자료형 안의 요소 중 값이 같은 것이 몇 개 있는지 반환해 준다.

```py
from collections import Counter

text=list('fallahad')
c=Counter(text)

print(c)
c["a"]

  Counter({'a':3,'l':2,'g':1,'h':1,'d':1})
  3
```

또한 Counter는 딕셔너리 형태나 키워드 형태의 매개변수를 사용하여 Counter를 생성할 수 있다.

- 딕셔너리 형태로 Counter 객체를 생성하는 방법
  - elements() 함수 : 각 요소의 개수만큼 리스트형의 결과를 출력한다.

```py
from collections import Counter

c=Counter({'red':4,'blue':2})
print(c)
  #Counter({'red':4,'blue':2})
print(list(c.elements()))
  #['red','red','red','red','blue','blue']
```

- 키워드 형태의 미개변수를 사용하여 Counter를 생성하는 방법
  - 매개변수의 이름을 key로, 실제 값을 value로 한다.

```py
from collections import Counter

c=Counter(cats=4, dogs=8)
print(c)
  #Counter({'dogs:8','cats':4})
print(list(c.elements()))
  #['cats','cats','cats','cats','dogs','dogs','dogs','dogs','dogs','dogs','dogs','dogs',]
```

Counter는 기본 사칙연산을 지원한다.

- 덧셈, 뺄셈, 논리연산 등이 가능하다.

뺄셈

```py
from collections import Counter

c=Counter(a=4,b=2,c=0,d=-2)
d=Counter(a=1,b=2,c=3,d=4)
c.subtract(d)
c
  #Counter({'a':3,'b':0,'c':-3,'d':-6})
```

논리연산

```py
from collections import Counter

c=Counter(a=4,b=2,c=0,d=-2)
d=Counter(a=1,b=2,c=3,d=4)
print(c+d)              # Counter 객체에 있는 각 요소를 더함
  #Counter({'a':5,'b':4,'c':3,'d':2})
print(c&d)              # 교집합
  #Counter({'b':2,'a':1})
print(c|d)            
  #Counter({'a':4,'d':4,'c':3,'b':2})
```

- | 기호는 두 Counter 객체에서 하나가 포함되어 있다면, 그리고 좀 더 큰 값이 있다면 그 값으로 합집합을 적용하였다.

## namedtuple 모듈

튜플의 형태로 데이터 구조체를 저장하는 방법이다.

```py
from collections import namedtuple

Point=namedtuple('Point',['x','y'])
p=Point(11,y=22)
p.x,p.y
  #(11,22)
print(p[0]+p[1])
  #33
```

- Point=namedtuple('Point',['x','y']) : Point 객체의 이름을 Point로 지정했다.
  - 저장되는 요소의 이름을 x,y로 지정했다.
- p=Point(11,y=22) : Point 객체에서 x와 y를 변수로 사용하므로, 각각 차례로 사용되어 값 저장이 가능하다.
  - 입력된 값은 p변수에 저장 할 수 있다.
- p[0], p[1] : Point 객체에서 각각 x,y 값에 대응된다.
  - 덧셈 연산이나 unpacking 연산 등이 모두 가능하다.

## collection 모듈은 난도가 올라갈수록 많이 사용하므로 다양한 사용법과 사용 사례를 잘 익혀두는 연습을 하자.