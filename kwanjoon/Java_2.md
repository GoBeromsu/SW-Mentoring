# 배열

: 타입과 이름이 같은 변수들의 모임

## 배열 사용 단계

### 배열 선언

    ex) int[] a, char[] season

### 배열객체 생성

    ex1) int[] numOfStudent = new int[10];
    ex2) int[] numOfStudent; // 배열선언
    numOfStudent = new int[10] // 배열객체 생성

- 참고: 배열원소의 수는 항상 정수 리터럴 또는 정수식

### 배열객체에 데이터 수록
    int[] square = {2,3,5,7}; // 배열선언, 배열객체생성, 초기화가 동시에 이루어짐.

## 2차원 배열

### 2차원 배열 선언

    int[][] intArray;
    char[][] charArray;
    float[][] floatArray;
### 2차원 배열 생성
    intArray = new int[2][5];
    charArray = new char[5][5];
    floatArray = new float[5][2];
### 2차원 배열 선언, 생성, 초기화
    int intArray[][]={{0,1,2},{3,4,5},{6,7,8}};
