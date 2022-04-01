#include <stdio.h>

int main()
{
    _set_printf_count_output(1);
    int pos, x = 235, y = 93;
    printf("%d %n%d\n", x, y, &pos);
    printf("The offset was %d\n", pos);
}