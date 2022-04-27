# Chapter3 실습에서 새롭게 알게 된 내용

## 리스트 복사 및 복제

## 복사

하나의 변수 B 를 A와 동일하게 저장하면 두 변수 모두 메모리에서 동일한 리스트를 참조한다.

```py
A = ["hard rock", 10, 1.2]
B = A
print('A:', A)
print('B:', B)
```

<img width="1482" alt="리스트" src="https://user-images.githubusercontent.com/102230809/163502022-eb2c3006-a601-44e0-baa0-d4dffab1e5e0.png">

- 위 사진 처럼 'B=A'이라고 표현하는 경우 변수 A, B 모두 동일한 리스트를 참조한다.

처음에는 변수 B의 첫 번째 값이 "hard rock"으로 저장되었다. 변수 A의 첫 번째 값을 'banana'로 변경해 보자

```py
print('B[0]:', B[0])
A[0] = "banana"
print('B[0]:', B[0])
```

출력
```
B[0]: hard rock
B[0]: banana
```
그 이유는 아래 사진과 같다.

![ListsRefGif](https://user-images.githubusercontent.com/102230809/163502516-32a20dd8-f797-465c-b824-7c6cf9ce45aa.gif)

## 복제

다음과 같은 구문을 사용해서 리스트 A를 복제할 수 있다.

```py
B = A[:]
```

A를 복제한 변수 B는 원본과 동일한 값이지만, 서로 다른 주소를 참조한다.

![ListsVal](https://user-images.githubusercontent.com/102230809/163502702-7a05c53c-581e-4e4c-8e70-d791a4cabe0f.gif)

이렇게 되면, A를 변경해도 B는 변경되지 않는다.

```py
print('B[0]:', B[0])
A[0] = "hard rock"
print('B[0]:', B[0])
```

출력
```
B[0]: banana
B[0]: banana
```

# 개인적으로 느낀 복사와 복제의 차이점

- 복사는 A라는 리스트 주소를 B에 할당하여 A와 B가 같은 주소를 쓴다.
- 복제는 A라는 리스트를 출력하고 그 출력한 값을 B라는 리스트에 할당한다.
(이때 리스트 A와 B의 주소는 다르다.)