# 5장. 함수

프로그램을 작성해야 하는 부분을 나누는 방법 중 파이썬에는 함수, 객체, 모듈이 있다.

이번 장에서는 함수의 개념을 먼저 배운다.

# 5-1. 함수 기초

## 함수의 개념

- 함수(function) : 어떤 일을 수행하는 코드의 덩어리, 또는 코드의 묶음
- 함수의 장점
  - 필요할 때마다 호출 가능
  - 논리적인 단위로 분할 가능
  - 코드의 캡슐화

## 캡슐화란?

- 캡슐화는 함수의 인터페이스만 잘 정의되면 다른 사람이 자신의 코드를 쉽게 가져다가 사용할 수 있는 특징이다.
- 인터페이스를 정의한다는 것은 코드에 입력되는 입력값과 코드의 수행 결과인 출력값을 명확히 한다는 것이다.
  - 흔히 블랙박스라고도 하는데, 인터페이스가 잘 정의된 코드라면 코드의 내부 구조를 몰라도 함수를 굉장히 쉽게 사용할 수 있다.

## 함수의 선언

```py
def 함수 이름 (매개변수#1 ...):
    수행문1
    수행문2
    return <반환값>
```

- def : definition의 줄임말로, 함수를 정의하여 시작한다는 의미
- 함수 이름 : 개발자가 마음대로 지정 가능하지만, 파이썬에서 일반적으로 아래와 같은 규칙을 따른다.
  - 소문자로 입력한다
  - 띄어쓰기를 할 경우 _ 기호를 사용한다.
  - 행위를 기록하므로 동사와 명사를 함께 사용하는 경우가 많다.
  - 외부에 공개하는 함수의 경우, 줄임말을 지양하고 짧고 명료한 이름을 정한다.
- 매개변수(parameter) : 함수에서 입력값으로 사용하는 변수를 의미하며, 1개 이상의 값을 적을 수 있다.
- 수행문 : 반드시 들여쓰기한 후 수행문을 입력해야한다.
  - 수행해야 하는 코드는 일반적으로 작성하는 코드와 같다.

예시

```python
def calculate_rectangle_area(x,y)
    return x*y
```

- 함수 이름 : calculate_rectangle_area
- 매개변수 : x, y
- return의 의미 : 값을 반환한다는 뜻으로, x와 y를 곱한 값을 반환하는 함수로 이해하면 된다.

## 함수의 실행 순서

```Python
def calculate_rectangle_area(x, y):
    return x * y

rectangle_x = 10
rectangle_y = 20
print("사각형 x의 길이:", rectangle_x)
print("사각형 y의 길이:", rectangle_y)

# 넓이를 구하는 함수 호출
print("사각형의 넓이:", calculate_rectangle_area(rectangle_x, rectangle_y))
```

- 1행에서 함수가 정의된 def부분은 실행하지 않는다.
  - 사실은 해당 코드를 메모리에 업로드하여 다른 코드를 호출해 사용할 수 있도록 준비 과정을 거친다.
  - 만약 함수의 선언 부분을 코드의 맨 끝에 둔다면 해당 코드 호출에 오류가 발생한다.

## 매개변수와 인수

- 매개변수(parameter) : 함수의 인터페이스 정의에 있어 어떤 변수를 사용하는지를 정의하는 것.
- 인수(argument) : 실제 매개변수에 대입되는 값

예시

```py
def f(x):
    return 2*x+7

print(f(2))
```

위 예시에서 매개변수 -> x

인수 -> 2

## 함수의 형태

![KakaoTalk_20220416_210852558](https://user-images.githubusercontent.com/102230809/163674420-a30128f1-275a-4b9b-8b78-41377f3fab20.jpg)

- 반환(return)이 없으면 해당 함수는  none으로 치환된다.
- 반환(return)이 있으면 해당 함수는  출력값으로 치환된다.
  - 반환(return)이 있으면 함수를 호출한 곳에서 함수의 반환 값을 변수에 할당하여 사용할 수 있다.

# 5-2. 함수 심화

## 함수의 호출 방식

```Python
def f(x):
    y=x
    x=5
    return y*y

x=3
print(f(x))
print(x)
```

출력

```Python
9
3
```

함수 f(x)의 x에는 3이라는 값이 입력된다.

그렇다면 함수 밖에서의 x와 함수 안에서의 x는 같은 변수일까, 다른 변수일까?

함수 밖에 있는 변수 x의 메모리 주소와 함수 안에 있는 변수 x의 메모리 주소가 같은지 다른지 확인할 필요가 있다.

함수 안에 변수가 인수로 들어가 사용될 때, 변수를 호출하는 방식을 전통적인 프로그래밍에서는 다음과 같이 크게 두 가지로 나눈다.

- 값에 의한 호출(call by value)
  - 함수에 인수를 넘길 때 값만 넘김
  - 함수 안의 인수값 변경 시, 호출된 변수에 영향을 주지 않음
- 참조 호출(call by reference)
  - 함수에 인수를 넘길 때 메모리 주소를 넘김
  - 함수 안의 인수값 변경 시, 호출된 변수값도 변경됨

하지만 파이썬은 전통적인 두 가지 방식을 혼합한, 특이한 방식을 사용한다.

파이썬은 객체 호출(call by object reference) 방식을 사용한다.

- 객체 호출(call by object reference)
  - 객체의 주소가 함수로 넘어감
  - 새로운 값을 할당하거나 해당 객체를 지울 때는 영향을 주지 않음.
  - 해당 객체에 값을 추가할 때 영향을 줌
  - 새로운 값을 할당하기 전까지는 기존에 넘어온 인수 객체의 주소값을 쓰는 방식이라고 이해하면 된다.

내용을 더 알고 싶다면 교재 p.169~171을 참고하자

## 변수의 사용 범위

- 변수의 사용 범위(scooping rule) : 변수가 코드에서 사용되는 범위
- 지역 변수(local variable) : 함수 안에서만 사용
- 전역 변수(global variable) : 프로그램 전체에서 사용

예시-1

```py
def test(t):
    print(x)
    t = 20
    print("In Function:", t)

x = 10
test(x)
print("In Main:", x)
print("In Main:", t)
```

- 전역 변수 : x
- 지역 변수 : t
- 위 코드를 실행하면 print("In Main:", t) 때문에 오류가 발생한다.
  - t가 지역 변수이기 때문이다.

예시-2

```py
def f():
    s='I love London!'
    print(s)

s='I love Paris!'
f()
print(s)
```

출력
```
I love London!
I love Paris!
```

- 함수 안과 밖의 s는 같은 이름을 가졌지만, 다른 메모리 주소를 가진 전혀 다른 변수이다.
- 함수 안의 s는 함수가 실행되는 동안에만 메모리에 있다가 함수가 종료되면 사라진다.
  - 함수 밖 s와는 메모리 주소가 달라 서로 영향을 주지 않는다.
- 변수 이름이 같다고 다 같은 함수가 아니다.

## global 키워드

- 예시-2 코드에서 함수 안과 밖의 변수가 같은 이름을 사용하려면 global이라는 키워드를 사용하면 된다.

예시

```py
def f():
    global s
    s='I love London!'
    print(s)

s='I love Paris!'
f()
print(s)
```

출력

```
I love London!
I love London!
```

## 재귀 함수(recursive function)

함수가 자기 자신을 다시 부르는 함수이다.

팩토리얼(factorial) 함수로 예를 들어보자

```Python
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)

print(factorial(int(input("Input Number for Factorial Calculation: "))))

```

- else: 실행 명령 부분에 factorial() 함수가 들어있는 것을 볼 수 있다.

# 5-3. 함수의 인수(argument)

## 파이썬에서 인수를 사용하는 방법

- 키워드 인수
- 디폴트 인수
- 가변 인수
- 키워드 가변 인수

## 키워드 인수 (keyword arguments)

함수에 입력되는 매개변수의 변수명을 사용하여 함수의 인수를 지정하는 방법

```py
def print_something(my_name, your_name):
  print("Hello {0}, My name is{1}".format(your_name,my_name))

print_something("Sungchul","TEAMLAB")
print_something(your_name="TEAMLAB",my_name="Sungchul")   #키워드 인수
```

## 디폴트 인수 (default arguments)

매개변수에 기본값을 지정하여 사용하고, 아무런 값도 인수로 넘기지 않으면 지정된 기본값을 사용하는 방식

```py
def print_something_2(my_name,your_name=""TEAMLAB):
  print("Hello{0}, My name is {1}".format(your_name, my_name))

print_something_2("Sungchul","TEAMLAB")
print_something_2("Sungchul")       #디폴트 인수
```

## 가변 인수 (variable-length arguments)

- 함수의 매개변수 개수가 정해지지 않고 진행해야 하는 경우가 있다. 이때 사용하는 것이 가변 인수다.
- 가변 인수는 *(asterisk라고 부름)로 표현할 수 있다.
  - *는 파이썬에서 곱셈 또는 제곱 연산 외에도 변수를 묶어 주는 가변 인수를 만든다.
- (사용 사례) 고객이 물건을 얼마나 구매할지 모르는 마트 계산기에서 합산을 수행하는 연산

```python
def asterisk_test(a,b,*args):
  return a+b+sum(args)

print(asterisk_test(1,2,3,4,5))
```

- asterisk_test()함수는 변수 a,b를 받고 나머지 변수는 *args로 받고 있다.
  - *args를 가변 인수라고 한다.
  - asterisk_test(1,2,3,4,5)에서 1,2는 각각 a,b에 할당된다.
  - 나머지 인수인 3,4,5는 모두 *args에 할당된다.
  - 가변인수 *는 반드시 일반적인 키워드 인수가 모두 끝난 후 넣어한다.

## 키워드 가변 인수 (keyword variable-length arguments)

- 매개변수의 이름을 따로 지정하지 않고 입력하는 방법으로, *를 2개 사용하여 함수의 매개변수를 표시한다.
- 입력된 값은 튜플 자료형이 아닌 dictionary type으로 사용 가능하다.
- 반드시 모든 매개변수의 맨 마지막, 즉 가변 인수 다음에 선언되어야 한다.

```py
def kwargs_test(**kwargs):
  print(kwargs)
  print('First value is {first}'.format(**kwargs))
  print('Second value is {second}'.format(**kwargs))
  print('Third value is {third}'.format(**kwargs))

kwargs_test(first=3, second=4, third=3)
```

출력

```py
{'first':3, 'second':4, 'third':5}
First value is 3
Second value is 4
Third value is 5
```

# 5-4. 좋은 코드를 작성하는 방법

코딩은 team play이므로 다른 사람이 내가 작성한 코드를 이해하기 쉽도록 프로그램을 작성해야 한다.

즉, 가독성이 좋아야 한다.

## 코딩 규칙 (책 p.186~188 보기)

## 함수 개발 가이드라인 (책 p.188~191 보기)
