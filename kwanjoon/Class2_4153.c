#include <stdio.h>

int main(void)
{
	int a, b, c;
	int i = 0;
	char count[100];

	for (;;)
	{
		scanf("%d%d%d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;
		else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
		{
			count[i] = "right";
			i++;
		}
		else {
			count[i] = "wrong";
			i++;
		}
	}
	for (int k = 0; k < i; k++)
	{
		printf("%c", count[k]);
	}
	return 0;
}
// 컴파일 성공 하지만 계속해서 논리오류