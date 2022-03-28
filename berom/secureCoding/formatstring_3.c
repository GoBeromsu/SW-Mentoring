#include <stdio.h>

int main()
{
    int pos=3;
    int x = 235;
    int y = 93;
    printf("%d %n%d\n", x, &pos, y); //%n 지시자 사용
    printf("The offset was %d\n", pos);
}