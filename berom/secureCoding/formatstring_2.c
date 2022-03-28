#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A = 5, B = 7, count_one, count_two;

    //%n 포맷 스트링 예제
    //이 X포인트까지 출력한 바이트 수는 count_one에 저장되고,
    //여기의 X까지의 바이트 수는 count_two에 저장된다.
    printf("The number of bytes written up to this point X%n is being stored in count_one, and the number of bytes up to here X%n is being stored in count_two.\n",
           &count_one, &count_two); //

    printf("count_one : %d\n", count_one);
    printf("count_two : %d\n", count_two);

    return 0;
}