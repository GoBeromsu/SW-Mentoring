#define _CRT_SECURE_NO_WARNINS
#include <stdio.h>

int main(void)
{
	int amount1, amount2;// 1: 진우꺼, 2: 선우꺼
	int days[100], D = 0;

	printf("진우꺼 선우꺼를 입력하시오.\n");
	scanf_s("%d %d", &amount1, &amount2);
	printf("원하는 날짜를 입력하시오.\n");
	scanf_s("%d", &D);

	int sum = amount1 + amount2; //총량

	for (int i = 1; i <= 100; i++)
	{
		if (amount1 >= amount2)
		{
			if (amount1 % 2 == 1)
				amount2 += ((amount1 / 2) + 1);
			else amount2 += (amount1 / 2);
		}
		else
		{
			if (amount2 % 2 == 1)
				amount1 += ((amount2 / 2) + 1);
			else amount1 += (amount2 / 2);
		}
		days[i] = amount1;
	}

	printf("진우 %d개, 선우 %d개", days[D], sum - days[D]);

	return 0;
}