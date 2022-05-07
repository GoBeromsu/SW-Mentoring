#include <stdio.h>

int main(void)
{
	int a[5];
	int sum = 0;
	
	for (int i = 1; i <= 5; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	printf("%d", sum / 10);

	return 0;
}