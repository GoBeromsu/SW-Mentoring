# Format String

## What is Format String Attack

### Format String

- 일반적으로 사용자로부터 입력을 받아들이거나 결과를 출력하기 위하여 사용하는 방식
- format string을 사용하는 함수에 대해 형식이나 형태를 지정해주는 문자열

```c
printf("This is our %d th presentation ")
```

위의 printf()안의 문자열과 같은 형식을 format string이라 한다.

### 함수 호출 규약

함수를 선언하게 되면 아래 순서대로 스택에 쌓이게 된다

1. 인자
2. 다시 돌아갈 주소 (RET)
3. 다시 돌아갈 EBP 주소
4. 그 함수 안에 있는 버퍼들

## 취약점

## Code && Attack

## Solution

## Reference

- [함수 호출 규약](https://s1m0hya.tistory.com/19)