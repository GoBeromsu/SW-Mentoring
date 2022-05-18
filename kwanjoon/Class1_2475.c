#include <stdio.h>

int main(void)
{
	int a[5];
	int sum = 0;
	
	for (int i = 1; i <= 5; i++)
	{
		scanf("%d", &a[i-1]);
		sum += (a[i-1]*a[i-1]);
	}
	printf("%d", sum / 10);

	return 0;
}