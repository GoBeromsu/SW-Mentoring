# 예외란

## 예외

- 예외의 정의 : 코드 실행중에 발생하는 오류
  - 오류로 인해 코드 실행에 예외가 발생한다.
  - 예외가 처리되지 않으면 코드 실행은 중단된다.

## 예외의 종류

- ZeroDivisionError : 숫자를 0으로 나누려고 할 때 발생하는 오류
- NameError : 변수가 정의되지 않았을 때, 변수를 사용하려고 한 경우
- IndexError : 리스트에 존재하지 않는 인덱스에 접근하려고 한 경우

파이썬에 내장된 예외는 매우 많다.

참고 : https://docs.python.org/3/library/exceptions.html

# 예외 처리

예외가 발생한 경우, 코드 실행을 중지하는 대신, 우리가 미리 정의한 작업을 수행하도록 하는 방법이다.

## Try Except

- Python은 try 블록의 코드를 실행하려고 시도한다.
- try 블록의 코드에서 예외가 발생하면 except 블록의 코드가 실행된다.

```py
try:
    # code to try to execute
except:
    # code to execute if there is an exception
```

## 특정 Try Except

사용 예시

```py
try:
    # code to try to execute
except (ZeroDivisionError, NameError):
    # code to execute if there is an exception of the given types
```

```py
try:
    # code to try to execute
except ZeroDivisionError:
    # code to execute if there is a ZeroDivisionError
except NameError:
    # code to execute if there is a NameError
```

예기치 않은 예외(우리가 미처 예상하지 못한 오류)를 식별하기 위해서, 끝에 빈 except을 사용할 수 있다.

```py
try:
    # code to try to execute
except ZeroDivisionError:
    # code to execute if there is a ZeroDivisionError
except NameError:
    # code to execute if there is a NameError
except:
    # code to execute if ther is any exception
```

## Else와 Finally

## Else

else를 사용하면 try 블록을 실행할 때 예외가 없는지 확인할 수 있다. 

오류가 없는 경우에만 무언가를 실행하려는 경우에 유용하다.

```py
try:
    # code to try to execute
except ZeroDivisionError:
    # code to execute if there is a ZeroDivisionError
except NameError:
    # code to execute if there is a NameError
except:
    # code to execute if ther is any exception
else:
    # code to execute if there is no exception
```

## Finaly

finally를 사용하면 예외가 있든 없든 항상 무언가를 실행할 수 있다. 

일반적으로 try의 끝을 나타내는 데 사용된다.

```py
try:
    # code to try to execute
except ZeroDivisionError:
    # code to execute if there is a ZeroDivisionError
except NameError:
    # code to execute if there is a NameError
except:
    # code to execute if ther is any exception
else:
    # code to execute if there is no exception
finally:
    # code to execute at the end of the try except no matter what
```