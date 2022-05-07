# 반복문

- 반복문은 헤더(Header)와 몸체(Body)로 구성
- 반복문을 루프(Loop)라고도 하며, 루프중 1회 작업을 단계(Iteration)라고 한다.
- Loop 구성의 3요소
  - 초기화
  - Loop Body
  - 반복조건

## for 문

### for 문의 구조

    for(Initialization(초기문); BooleanExpression(조건식); UpdateStatement(반복 후 작업)){}

### for 문의 실행순서

<img width="494" alt="image" src="https://user-images.githubusercontent.com/102643841/161423736-87a73ebf-ce15-46f4-95af-b75f660f49a8.png">

### for 문의 초기작업

- for 문을 실행할 때 맨 먼저 오직 한번만 실행된다.
- 번수를 선언하거나 초기화 한다.
- 0 ~ n개의 문장으로 구성된다.

### for 문의 조건식

- 여러가지 형태의 조건식
  - boolean 변수
  - boolean 리터럴
  - boolean 식
- 조건식이 true이면 몸체를 실행, false이면 반복문 종료
- 조건식에 리터럴 true를 사용하면 무한반복
- 조건식이 비어 있으면 true로 간주
  
        ex) for(;;) 

### for 문의 반복후 작업

- Loop 몸체 실행 후 다음 단계로 넘어가기 전에 처리해야할 작업

## while 문

### while 문의 구조

    while(조건식){}
<img width="320" alt="image" src="https://user-images.githubusercontent.com/102643841/161425908-7f5fd1a0-67c6-4d20-bf8c-87ea324f2ae0.png">

- 조건식이 true이면 몸체 실행 그리고 다시 조건식 검사, false이면 반복문 종료

## do while 문

### do while 문의 구조

    do{

    }(조건식)

## 반복문의 선택

- 반복 횟수가 명확하다면 for
- 적어도 한 번은 실행된다는 확신이 있으면 do while
- 나머지 경우에는 while이 가장 적합

## continue 문

- 당해iteration 종료
- 반복문 자체를 빠져나가지는 않고 다음 단계를 진행

## break 문

- 반복문을 마친다.
- 중첩반복문 일때 break 문은 하나의 반복문만 벗어난다.
- 바깥 루프에도 적용을 시키고 싶다면 OUTER 레이블을 붙여야 한다.
  
        ex) 
        continue OUTER;
        break OUTER;
