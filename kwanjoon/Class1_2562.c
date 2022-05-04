#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int c = 0, MAX = 0;
	int index;
	for(int i=1;i<=9;i++)
	{
		scanf("%d", &c);
		if (c > MAX)
		{
			MAX = c;
			index = i;
		}
	}
	printf("%d\n%d", MAX, index);

	return 0;
}