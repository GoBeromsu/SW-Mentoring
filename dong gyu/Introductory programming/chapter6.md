# 6장. 문자열(string)

애플리캐이션을 만들거나 데이터를 분석할때 매우 중요하게 다루는 자료형이다.

# 6-1. 문자열의 이해

## 문자열의 개념

- 문자열은 시퀸스 자료형(sequence data type)이다.
  - 시퀸스 자료형 : 리스트와 같이 데이터를 순차적으로 메모리에 저장하는 형식
  - 정확히 표현하면 메모리에 물리적인 순서대로 저장되는 것이 아닌, 단지 우리 눈이 보기에 차례차례 저장되는 것처럼 보이는 것임.

## 문자열과 메모리 공간

- 영문자 한 글자당 1byte메모리 공간 사용
- 컴퓨터가 숫자를 인식하는 최소 단위는 1bit
- 1bit는 0과 1만을 표현할 수 있다
- 1byte=8bit

문자열이 저장된 공간의 크기를 확인하는 방법

```python
import sys          #sys 모듈 호출
print(sys.getsizeof('a'),sys.getsizeof('ab'),sys.getsizeof('abc'))
    50 51 52        #'a','ab','abc' 각각의 메모리 크기 출력 
```

- 50byte, 51byte, 52byte의 공간에 각각 a, ab, abc가 저장된 것임.

인코딩(encoding) <-> 디코딩(decoding)

- 인코딩 : 문자를 처리하기 위해 문자가 이진수로 변환되는 표준 규칙
  - 예시 : ASCII, CP949, MS949, UTF-8
- 인코딩에 대해 기억해야 할 것
  - 컴퓨터는 문자를 직접 인식하지 못한다.
  - 컴퓨터는 문자를 숫자로 변환하여 인식한다.
  - 사람들은 문자를 숫자로 변환하기 위한 규칙을 만들었다.
  - 일반적으로 이 규칙은 1개의 영문자를 1byte 정도의 공간에 저장될 수 있도록 정하였다.
    - 1byte는 2의 8승(2^8) 정도의 공간을 의미함.

위와 같은 규칙을 이용하여 숫자와 문자를 맵핑하는 것이 운영체제와 인터프리터의 역할 중 하나이다.

## 문자열의 인덱싱

문자열은 시퀸스 자료형이다. 시퀸스 자료형은 리스트와 특징이 거의 같다.

문자열의 특징 중 하나가 인덱싱(indexing)이다.

- 예시

```py
a='abcde'
print(a[0],a[4])      #a 변수의 0번째, 4번째 주소에 있는 값
  a e
print(a[-1],a[-5])    #a 변수의 오른쪽에서 0번째, 4번째 주소에 있는 값
  e a
```

## 문자열의 슬라이싱

슬라이싱(slicing) : 문자열의 주소값을 기반으로 문자열의 부분값을 반환하는 기법

```py
a='TEAMLAB MOOC, AWESOME Python'
print(a[0:6],'AND',a[-9:])  
#a 변수의 0부터 5까지, -9부터 끝까지
  TEAMLA AND ME Pyhon
print(a[:])                 
#a 변수의 처음부터 끝까지
  TEAMLAB MOOC, AWESOME Python
print(a[-50:50])            
#범위를 넘어갈 경우 자동으로 최대 범위 지정
  TEAMLAB MOOC, AWESOME Python
print(a[::2], 'AND', a[::-1])
#변수[시작 인덱스:종료 인덱스:증가값]
  TALBMO,AEOEPto AND nohtyP EMOSEWA ,COOM BALMAET
```

## 문자열의 연산

가장 기본적인 연산은 리스트의 연산과 같다.

문자열 'a'와 정수형인 2의 'a+2'와 같은 연산은 동작하지 않는다.

하지만'a*2'와 같은 연산은 지원한다.

```py
a='TEAM'
b='LAB'
print(a+' '+b)      #덧셈으로 a와 b 변수 연결하기
  TEAM LAB
print(a*2+' '+b*2)  #곱하기로 반복 연산 가능
  TEAMTEAM LABLAB
if 'A' in a: print(a) #'A'가 a에 포함되었는지 확인
  else: print(b)

  TEAM
```

## 문자열 함수

문자열 함수 사용법 : 문자열 변수.문자열 함수

Ex. a.upper()

- len() : 문자열의 문자 개수를 반환
- upper() : 대문자로 변환
- lower() : 소문자로 변환
- title() : 각 단어의 앞글자만 대문자로 변환
- capitalize() : 첫 문자를 대문자로 변환
- count('찾을 문자열') : '찾을 문자열'이 몆 개 들어 있는지 개수 반환
- find('찾을 문자열') : '찾을 문자열'이 왼쪽 끝부터 시작하여 몇 번째에 있는지 반환
- rfind('찾을 문자열') : find() 함수와 반대로 '찾을 문자열'이 오른쪽 끝부터 시작하여 몆 번째에 있는지 반환
- startswith('찾을 문자열') : '찾을 문자열'로 시작하는지 여부 반환
- endswith('찾을 문자열') : '찾을 문자열'로 끝나는지 여부 반환
- strip() : 좌우 공백 삭제
- rstrip() : 오른쪽 공백 삭제
- lstrip() : 왼쪽 공백 삭제
- split() : 문자열을 공백이나 다른 문자로 나누어 리스트로 반환
- isdigit() : 문자열이 숫자인지 여부 반환
- islower() : 문자열이 소문자인지 여부 반환
- isupper() : 문자열이 대문자인지 여부 반환

예시

```python
title='TEAMLAB X /Inflearn'
title.isdigit()      #title 변수의 문자열이 숫자인지 여부 반환
  False
```

+추가

문자열 표현과 특수문자에 대해 더 알면 좋은 사항은 본 책 p.209~211을 참고 할 것.

# 6-2. 문자열 서식 지정

## 서식 지정의 개념

print() 함수를 사용하다 보면 어떤 형식에 맞추어 결과를 출력해야 할 일이 발생하기도 한다.

특히 엑셀을 사용할 때 통화 단위, 세 자리 숫자 단위 띄어쓰기, %출력 등 다양한 형식에 맞추어 출력할 일이 생기는데, 이를 서식지정(formatting)이라고 한다.

## %서식과 format()함수

```py
print("a"+" "+"b"+" "+"c")
print('%s %s'%('one','two'))    #서식 지정
print('%d %d'%(1,2))            #서식 지정
  a b c
  one two
  1 2
```

위와 같은 방법으로 서식을 지정하여 출력하면 장점이 있다.

- 데이터와 출력 형식을 분류할 수 있다. print()문에 띄어쓰기를 넣어 + 기호로 문자열 형태를 붙여 주는 것보다 시각적으로 이해하기 쉽다.
- 데이터를 형식에 따라 다르게 표현할 수 있다. 서식 지정은 각 변수의 자료형에 맞게 다른 서식으로 지정한다.

변수의 자료형에 따른 서식

- %s : 문자열(string)
- %c : 문자 1개(character)
- %d : 정수(integer)
- %f : 실수(floating-point)
- %o : 8진수
- %x : 16진수
- %% : 문자 %자체

## %서식의 다양한 쓰임

- %는 1개 이상의 값도 할당이 가능하다. 아래 코드처럼 % 뒤에 괄호를 쓰고, 그 안에 순서대로 값을 입력하면 된다.

```py
print("Product:%s, Price per unit:%f."%("Apple",5.243))
  Product:Apple, Price per unit:5.24300.
```

- 직접 값을 넣지 않고 number와 day 같은 변수명을 넣어도 문제없이 실행된다.

```py
number=3
day="three"
print("I ate %d apples. I was sick for %s days."%(number,day))
  I ate 3 apples. I was sick for three days.
```

## format() 함수

- format() 함수 : % 서식과 거의 같지만, 문자열 형태가 있는 함수를 사용한다는 차이점이 있다.

format() 함수의 형식

```py
"{자료형}".format(인수)
```

예시

```py
print("I'm {0} years old.".format(20))
  I'm 20 years old. 
```

- 숫자 20이 {0}에 할당되어 출력됨
- 기존 %서식과 비교하면 자료형을 바로 지정해 주지 않고 순서대로 변수가 할당 된다는 장점이 있다.

format() 함수는 %서식처럼 변수의 이름을 사용하거나 변수의 자료형을 따로 지정하여 출력한다.

예시

```py
age=40; name='Sungchul Choi'
print("I'm {0} years old.".format(age))
print("My name is {0} and {1} years old.".format(name,age))
print("Product: {0}, Price per unit:{1:.2f}".format("Apple",5.243))
```

출력

```
I'm 40 years old.
My name is Sungchul and 40 years old.
Product: Apple, Price per unit:5.24
```

- 예시의 4행에서 {1:.2f}는 기존 format() 함수의 쓰임과 다르게 .2f라는 구문이 추가되었다. 2는 소수점 둘째 자리까지 출력하라는 뜻이다.

## 패딩(padding)

- 패딩 : 파이썬의 서식 지정 기능 중 여유 공간을 지정하여 글자 배열을 맞추고 소수점 자릿수를 맞추는 기능
  - %서식과 format()함수 모두 패딩 기능을 제공한다.

### % 서식의 패딩

```py
print("%10d"%12)
        12
print("-10d"%12)
12
```

- 첫 번째 줄의 의미는 10자리의 공간을 확보하고 우측 정렬로 12를 출력하라는 명령이다. 아홉 번째 칸부터 12가 출력된다.
  - 기본 정렬이 우측 정렬이다.
  - 좌측 정렬을 하기 위해서는 세 번째 줄처럼 -부호를 붙이면 된다.

```py
print("%10.3f"%5.94343)
     5.943
#10자리를 확보하고 소수점 셋째 자리까지 출력
print("%10.2f"%5.94343)
      5.94
#10자리를 확보하고 소수점 둘째 자리까지 출력
print("%-10.2f"%5.94343)
5.94
```

- 첫 번째 줄의 print("%10.3f"%5.94343)은 10자리의 공간을 확보하고 소수점 셋째 자리까지 출력하라는 뜻이다.
  - 이때 10자리 안에는 소수점이 포함된다.

### format() 함수의 패딩

```py
print("{0:>10s}".format("Apple"))
     Apple
print("{0<:10s}".format("Apple"))
Apple
```

- 첫 번째줄의 print("{0:>10s}".format("Apple"))은 10자리의 공간을 확보하고 우측 정렬로 문자열 'Apple'을 출력하라는 명령이다.
  - 좌측 정렬을 하기 위해서는 '{0:<10s}' <부호를 사용하면 된다.

```py
"{1:10.5f}.".format("Apple",5.243)
'  5.24300.'
"{1:>10.5f}.".format("Apple",5.243)
'  5.24300.'
"{1:<10.5f}.".format("Apple",5.243)
'5.24300  .'
```

- 실수에서도 자릿수와 소수점 자릿수를 지정할 수 있다.
- 첫 번째 줄의 "{1:10.5f}.".format("Apple",5.243)은 10자리의 공간을 확보하고, 소수점 다섯 번째 자리까지 실수를 출력한다.
  - 10자리 안에는 소수점이 포함된다.
  - 우측 정렬이 기준이다.
  - 좌측 정렬을 하기 위해서는 <부호를 사용한다.

## 네이밍(naming)

```py
print("Product:%(name)5s, Price per unit:%(price)5.5f."%{"name":"Apple","price":5.243})
  Product:Apple, Price per unit:5.24300.
print("Product:{name:>5s},Price per unit:{price:5.5f}.".format(name="Apple",price=5.243))
  Product:Apple, Price per unit:5.24300.
```

- 소스 코드 설명 : %(name)5s, {name:>5s}에서 5는 5자리의 공간을 확보하라는 뜻이다.
  - 만약 문자열이나 숫자열이 확보한 공간보다 많으면 공간이 추가 된다.

네이밍

- 변수명을 서식에 할당할 수 있는 기능이다.
  - 위 소스 코드에서 name이나 price처럼 특정 변수명을 사용하여 출력값에 할당이 가능하다.
  - 한 번에 출력해야 하는 변수가 많을 때 변수의 순서를 햇갈리지 않고 사용할 수 있다는 장점이 있다.