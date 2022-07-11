# 배열

배열: 동일한 타입의 데이터가 여러 개 저장되어 있는 데이터 저장 장소이다. 배열을 사용하면 같은 종류의 대량의 데이터를 효율적이고 간편하게 처리할 수 있다.

## 배열의 선언

    int scores[10]; // 자료형 int, 배열이름 scores, 요소의 개수 10

배열의 각 요소들에는 0부터 시작하는 번호가 매겨져 있다. 첫 번째 요소의 번호는 0이고 두 번째 요소는 1, 마지막 요소의 번호는 9가 된다.

### 배열 선언할 때 주의할 점

    int scores[]; // 배열의 크기를 지정해야한다.
    int scores[size]; // 배열의 크기를 변수로 할 수 없다.(배열 인덱스는 변수 사용 가능)
    int scores[-2]; // 배열의 크기가 음수이면 안 됨
    int scores[2.4] // 배열의 크기가 실수이면 안 됨

위와 같은 방식으로 배열을 선언하면 오류가 발생하게 된다. 통상적으로 배열의 크기를 선언 할 때는 다음과 같이 기호 상수를 이용해서 선언한다.

    #define SIZE 10
    int scores[SIZE];

## 배열 요소 접근

배열 요소는 변수와 100% 동일하다. 배열 요소에 값을 저장할 수 있고 배열 요소에 저장된 값을 꺼낼 수도 있따.

    scores[0] = 80; // 0번째 요소에 80을 저장
    scores[1] = scores[0]; // 0번째 요소의 값을 1번째 요소로 복사

인덱스는 위의 예처럼 정수 상수가 될 수 있다. 그러나 많은 경우, 변수나 수식 등도 인덱스로 사용된다. for 반복문을 이용하여 순차적으로 배열요소를 처리할 때 유용하다.

    scores[i] = 10; // i는 정수 변수
    scores[i+2] = 20; // 수식이 인덱스가 된다.
    scores[index[3]]  = 30; // index[]는 정수 배열

## 인덱스의 범위

    int scores[5];
    printf("%d", scores[5]); // 인덱스 5는 적합한 범위가 아니다.

scores[5]의 값을 출력하면 전혀 의미 없는 쓰레기 값이 출력될 것이다. 그러나 컴퓨터 시스템이 정지하거나 프로그램이 중단되지는 않는다.

    int scores[5];
    scores[5] = 50; // 엉뚱한 메모리 위치에 50이 저장되게 된다.

이 경우에는 최악의 경우, 컴퓨터 시스템 자체가 중단될 수 있다. 존재하지 않는 곳에 데이터를 저장하면 안된다.

## 배열의 초기화

배열을 초기화 하려면 초기값들을 콤마로 부리하여 중괄호 {}로 감싼 후에, 배열을 선언 할 때 대입해주면 된다.

    int scores[5] = {10, 20, 30, 40, 50}; // scores[0] = 10, scores[1] = 20, ...

만약 초기값의 개수가 요소들의 개수보다 적은 경우에는 앞에 있는 요소들만 초기화 되고 나머지 배열들은 모두 0으로 초기화 된다.

    int scores[5] = {10, 20, 30}; // scores[3] = 0; scores[4] = 0이 된다.

따라서 이러한 성질을 이용하여 배열의 모든 요소를 0으로 초기화하려면 다음과 같은 문장을 사용할 수 있다.

    int scores[5] = {0}; // 모든 요소들이 0으로 초기화

만약 초기화만 하고 배열의 크기를 비워 놓으면 컴파일러가 자동으로 초기값들의 개수만큼의 배열 크기를 잡는다. 아래의 그림에서는 초기값이 5개 이므로 크기가 5인 scores 배열이 만들어 진다.

    int scores[] = {10, 20, 30, 40, 50}; // 컴파일러가 배열의 크기를 5로 잡는다.

만약 초기값이 주어지지 않고 지역변수로 선언된 배열이라면, 일반적인 지역 변수와 마찬가지로 쓰레기값이 들어가게 된다.

    int scores[5]; // 초기화가 이루어 지지 않음

### 배열 초기화할 때 주의점

배열에서 초기화할 때를 제외하고는 중괄호로 값을 묶어서 대입할 수 없다. 즉 다음과 같이 사용하면 오류가 된다.

    #define SIZE 3
    int main(void){
        int scores[5];
        scores = {1, 2, 3}; // 컴파일 오류!
    }

## 배열의 요소의 개수 계산법

만약 배열의 크기를 명시적으로 지정하지 않고 주어진 초기값의 개수로 결정하는 경우, 초기값의 개수를 매번 세어보아야 한다. 그러나 초기값의 개수가 많아지게 되면 정확한 개수를 센다는 게 어려울 수도 있다.

### sizeof 연산자

sizeof 연산자: 자료형이나 변수의 크기를 바이트 단위로 계산하는 연산자이다.

sizeof 연산자를 이용하여 배열 전체의 크기를 구하고 이것을 배열요소의 크기로 나누게 되면 배열 요소가 몇개나 있는지 쉽게 알 수 있다.

    int size = sizeof(scores) / sizeof(scores[0]);

## 배열의 복사

1. 잘못된 방법

        int a[SIZE] = {1, 2, 3, 4, 5};
        int b[SIZE];

        b = a;

2. 올바른 방법

        int i;
        int a[SIZE] = {1,2,3,4,5};
        int b[SIZE];

        for(i = 0; i < SIZE; i++)
            b[i] = a[i];

하나의 배열을 다른 배열로 복사하기 위해서는 각각의 요소를 복사해주어야 한다.

## 배열의 비교

1. 잘못된 방법

        int a[SIZE] = {1, 2, 3, 4, 5};
        int b[SIZE] = {1, 2, 3, 4, 5};

        if(a == b)
            printf("같다.\n");
        else
            printf("다르다.\n");

    배열의 이름은 배열이 저장된 메모리의 주소와 같다. 따라서 배열 요소들의 값이 일치해도 항상 같지 않다는 메시지가 출력된다.

2. 올바른 방법

        int a[SIZE] = {1, 2, 3, 4, 5};
        int b[SIZE] = {1, 2, 3, 4, 5};

        for(int i = 0; i < SIZE; i++)
        {
            if(a[i] != b[i])
            {
                printf("다르다.");
                break;
            }
        }

    a[i]가 b[i]와 같지 않으면 for 루프는 중단된다.

## Ex1) 최소값 찾기

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define SIZE 10

    int main(void) {
     int prices[SIZE] = { 0 };
     int minimum;

     printf("------------------------------\n");
     printf("1  2  3  4  5  6  7  8  9  10\n");
     printf("------------------------------\n");

     srand((unsigned)time(NULL));
     for (int i = 0; i < SIZE; i++) {
      prices[i] = (rand() % 100) + 1;
      printf("%d ", prices[i]);
     }

     printf("\n\n");

     minimum = prices[0];

     for (int i = 1; i < SIZE; i++) {
      if (prices[i] < minimum)
       minimum = prices[i];
     }
     printf("최소값은 %d 입니다.", minimum);

     return 0;
    }

## 배열과 함수

배열을 함수로 전달할 수 있으면 많은 작업들을 함수로 작성하여 편리하게 사용할 수 있다. 배열도 함수로 전달할 수 있다. 하지만 변수를 전달할 때와는 다른데 함수는 호출 시에 "값에 의한 호출(Call by value)" 이 이루어 지는데 반해 배열이 인수인 경우에는 배열의 원본이 매개 변수를 통하여 전달된다.

"~에 의한 호출" 이란 함수를 호출할 때 인수의 값이 매개 변수로 복사되는 것을 의미한다.

### Ex2) 배열을 이용한 평균 계산

    #include <stdio.h>
    #define STUDENTS 5

    int get_average(int scores[], int size); // 배열을 받는 매개변수는 크기를 지정하지 않아도 된다.

    int main(void) {
     int scores[STUDENTS] = { 1,2,3,4,5 }; // 성적이 들어있는 배열
     int avg;

     avg = get_average(scores, STUDENTS);
     printf("평균은 %d 입니다.", avg);
 
     return 0;
    }

    int get_average(int scores[], int size) {
     int sum = 0;

     for (int i = 0; i < STUDENTS; i++)
      sum += scores[i];

     return sum / size;
    }

### 원본 배열의 변경

함수 안에서 매개 변수를 통하여 배열 요소를 변경한다면 이것은 원본 배열을 변경시키는 결과를 가져온다.

배열 요소를 인수로 하여서 함수를 호출하면 복사본이 전달된다. 배열은 원본이 전달되지만 배열 요소는 복사본이 전달되므로 착각하면 안된다.

### 원본 배열의 변경을 금지하는 방법

const 지정자를 배열 매개 변수 앞에 붙이면 그 배열 요소는 변경이 불가능해진다. 따라서 배열의 내용을 변경하지 않는 함수의 경우에는 const를 붙이는 것이 권장된다.

    void print_array(const int a[], int size){
        ...
        a[0] = 100; // 컴파일 오류, 함수 안에서 a[] 변경 불가
    }

## 정렬

정렬: 물건을 크기순으로 오름차순(ascending order)이나 내림차순(descending order)으로 나열하는 것을 의미한다.예를 들어 책들은 제목순이나 저자순, 또는 발간연도순으로 정렬이 가능하다.

### 선택 정렬

먼저 왼쪽 배열과 오른쪽 배열, 두 개의 배열이 있다고 가정하자. 왼쪽 배열에는 정렬이 완료된 숫자들이 들어가게 되며 오른쪽 배열에는 정렬되지 않은 숫자들이 들어있다. 초기 상태에서 왼쪽 배열은 비어 있고 정렬되어야 할 숫자들은 모두 오른쪽 배열에 들어 있다. 선택정렬은 오른쪽 배열에서 가장 작은 숫자를 선택하여 왼쪽 배열로 이동하는 작업을 되풀이 한다. 선택 정렬은 오른쪽 배열이 공백 상태가 될 때까지 이 과정을 되풀이 하는 정렬 기법이다.

<img width="424" alt="image" src="https://user-images.githubusercontent.com/102643841/178183755-7eac801a-c2a5-4f18-923c-e7be38b2a428.png">

메모리 절약을 위해 하나의 배열만을 사용할 수도 있다. 배열에서 최소값을 찾아서 배열의 첫 번째 자리로 이동시킨다. 첫 번째 자리에 있었던 값은 최소값이 있었던 자리로 이동한다.

![image](https://user-images.githubusercontent.com/102643841/178184154-6934879c-7e0e-47e1-9b31-3e6b12cb04ed.png)

    #include <stdio.h>
    #define SIZE 10

    int main(void) {
     int list[SIZE] = { 3,2,9,7,1,4,8,0,6,5 };

     int temp, least; // 임시, 최소값 저장

     for (int i = 0; i < SIZE - 1; i++) {
      least = i;
      for (int j = i + 1; j < SIZE; j++)
       if (list[j] < list[least])
        least = j;
      temp = list[i]; // 첫번째 배열 원소를 옮긴다.
      list[i] = list[least]; // 첫번째 배열 자리에 최소값을 넣는다.
      list[least] = temp; // 최소값 자리에 첫번째 배열 원소를 넣는다.
     }
      for (int i = 0; i < SIZE; i++)
       printf("%d ", list[i]);
  
      return 0;
    }

## 탐색

### 순차 탐색

배열의 원소를 순서대로 하나씩 꺼내서 탐색키와 비교하여 원하는 값을 찾아가는 방법이다. 순차 탐색은 일치하는 항목을 찾을 때까지 비교를 계속한다. 순차 탐색은 첫 번째 원소에서 성공할 수도 있고 마지막 원소까지 가야되는 경우도 있다. 평균적으로는 절반 정도의 배열 원소와 비교하여야 할 것이다.

![image](https://user-images.githubusercontent.com/102643841/178187022-c430770b-7394-491d-9269-178afe7962cd.png)

    #include <stdio.h>
    #define SIZE 10

    int main(void) {
     int key;
     int list[SIZE] = { 1,2,3,4,5,6,7,8,9 };

     printf("탐색할 값을 입력하시오: ");
     scanf_s("%d", &key);

     for (int i = 0; i < SIZE; i++) {
      if (list[i] == key)
       printf("탐색 성공 인덱스 = %d\n", i);
     }

    printf("탐색종료\n");
    return 0;
    }

### 이진 탐색

이진 탐색은 아주 속도가 빠른 탐색 기법이다. 대신에 탐색하려는 배열이 정렬이 되어있어야 한다.

이진 탐색은 배열의 중앙에 있는 값을 탐색키와 비교한다. 만약 일치하면 탐색키를 찾은 것이므로 성공이다. 만약 탐색키가 중앙 원소의 값보다 작으면 우리가 찾고자하는 값은 배열의 전반부에 있을 것이다. 따라서 배열의 후반부는 탐색의 범위에서 제외할 수 있다. 이처럼 이진 탐색에서는 한번 비교할 때마다 탐색의 범위가 절반으로 줄어든다.

![image](https://user-images.githubusercontent.com/102643841/178187994-73db2c01-fcd6-4688-9866-246be4e3eda7.png)

    #include <stdio.h>
    #define SIZE 16

    int binary_search(int list[], int n, int key);

    int main(void) {
     int key;
     int grade[SIZE] = { 2,6,11,13,18,20,22,27,29,30,34,38,41,42,45,47 };

     printf("탐색할 값을 입력하시오 ");
     scanf_s("%d", &key);
     printf("탐색 결과 = %d\n", binary_search(grade, SIZE, key));

     return 0;
    }

    int binary_search(int list[], int n, int key) {
     int low, high, middle;

     low = 0;
     high = n - 1;

     while (low <= high) {
      printf("[%d %d]\n", low, high);
      middle = (low + high) / 2;
      if (key == list[middle])
       return middle;
      else if (key > list[middle])
       low = middle + 1;
      else
       high = middle - 1;
     }

    return -1;
    }

## 2차원 배열

2차원 배열에서는 요소들이 2차원적으로 배열되어 있다.

2개의 대괄호를 이용하여 2차원 배열을 선언할 수 있다. 첫 번째 대괄호 안에는 행(row)의 개수, 두 번째 대괄호 안에는 열(column)의 개수를 적는다.

![image](https://user-images.githubusercontent.com/102643841/178190470-9c2d3cf0-c770-4936-a77b-dd8bfbda8b62.png)

### 2차원 배열에서 요소 참조

2차원 배열에서 하나의 요소를 참조하려면 2개의 인덱스가 필요하다. 일반적으로 numArr[i][j]는 배열 numArr의 i번째 행과 j번째 열의 요소이다. 여기서 첫 번째 인덱스를 행번호라고 하고 두 번째 인덱스를 열번호라고 한다.

### Ex3) 2차원 배열에 난수 저장

    #include <stdio.h>
    #include <stdlib.h>
    #define ROWS 3
    #define COLS 5

    int main(void) {
     int s[ROWS][COLS]; // 2차원 배열 선언
 
     for (int i = 0; i < ROWS; i++) { // 행에 따라
      for (int j = 0; j < COLS; j++) { // 열에 따라
       s[i][j] = rand() % 100;
      }
     }

     for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
       printf("%d ", s[i][j]);
      }
      printf("\n");
     }
     return 0;
    }

### 2차원 배열의 초기화

2차원 배열도 1차원과 마찬가지로 선언과 동시에 초기화할 수 있다. 다만 같은 행에 속하는 초기값들을 중괄호 {}로 묶어주어야 한다.

    int s[3][5] = {
        {0, 1, 2, 3, 4}, // 첫 번째 행
        {10, 11, 12, 13, 14}, // 두 번째 행
        {20, 21, 22, 23, 24} // 세 번째 행
    };

만약 선언과 동시에 초기화하는 경우, 행의 개수는 지정하지 않을 수 있다. 이 경우 컴파일러가 자동으로 행의 개수를 결정한다.

    int s[][5] = {
        {0, 1, 2, 3, 4}, // 첫 번째 행
        {10, 11, 12, 13, 14}, // 두 번째 행
        {20, 21, 22, 23, 24} // 세 번째 행
    };

2차원 배열을 초기화할 때 안쪽의 중괄호는 생략될 수도 있다. 위의 2차원 배열은 다음과 같이 초기화될 수도 있다. 이때는 컴파일러가 행의 크기에 따라서 초기값을 자동으로 분류한다.

    int s[3][5] = {0, 1, 2, 3, 4, 10, 11, 12, 13, 14, 20, 21, 22, 23, 24};

1차원 배열과 마찬가지로 배열의 크기보다 초기값이 적게 주어진다면 나머지 요소들은 모두 0이 된다. 초기값을 전혀 지정해 주지 않은 경우는 배열이 전역변수냐 지역변수냐에 따라서 0 또는 쓰레기값이 저장된다.

### Ex4) 행렬의 덧셈

    #include <stdio.h>
    #define ROWS 3
    #define COLS 3

    int main(void) {
     int A[ROWS][COLS] = {
      {2,3,0},
      {8,9,1},
      {7,0,5}
     };
     int B[ROWS][COLS] = {
      {1,0,0},
      {1,0,0},
      {1,0,0}
     };
     int C[ROWS][COLS];

     /* 두개의 행렬을 더한다. */
     for (int r = 0; r < ROWS; r++)
      for (int c = 0; c < COLS; c++)
       C[r][c] = A[r][c] + B[r][c];

     for (int r = 0; r < ROWS; r++) { // 행렬 출력
      for (int c = 0; c < ROWS; c++)
       printf("%d", C[r][c]);
      printf("\n");
     }
     return 0;
    }

## 2차원 배열을 함수로 전달하기

2차원 배열도 1차원 배열과 마찬가지로 함수에 인수로 전달할 수 있다. 2차원 배열도 원본이 전달된다. 모든 것은 1차원 배열과 비슷하다. 함수에서 2차원 배열을 받을 때 행의 크기는 적지 않아도 된다. 그러나 열의 개수는 반드시 적어야 한다.

### Ex5) 총매출 구하기

    #include <stdio.h>
    #define YEARS 3
    #define PRODUCTS 5

    int sum(int sales[YEARS][PRODUCTS]);

    int main(void) {
     int sales[YEARS][PRODUCTS] = {
      {1,2,3},
      {4,5,6},
      {7,8,9}
     };
     int total_sale;

     total_sale = sum(sales);
     printf("총매출은 %d 입니다.", total_sale);

     return 0;
    }

    int sum(int sales[YEARS][PRODUCTS]) { // YEARS는 생략 가능
     int total = 0;
     for (int y = 0; y < YEARS; y++)
         for (int p = 0; p < PRODUCTS; p++)
       total += sales[y][p];

     return total;
    }

### Tik-tak-toe 게임

    #include <stdio.h>

    int main(void) {
     char board[3][3];
     int x, y, k, i;

     for (x = 0; x < 3; x++)
      for (y = 0; y < 3; y++)
       board[x][y] = ' ';

     for (k = 0; k < 9; k++) {
      printf("(x,y)좌표: ");
      scanf_s("%d %d", &x, &y);
      board[x][y] = (k % 2 == 0) ? 'x' : '0';

      for (i = 0; i < 3; i++) {
       printf("---|---|---\n");
       printf("%c  | %c |  %c\n", board[i][0], board[i][1], board[i][2]);
      }
      printf("---|---|---|\n");
     }
     return 0;
    }
