#include <stdio.h>
int main()
{   

    char str[15] = "Hello, World!\n";
    printf("%s", str); // 문자열 인식
    printf(str);       // 형식 지시자를 포함한 포맷 스트링
    return 0;
}