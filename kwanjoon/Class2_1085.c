#include <stdio.h>

int main(void)
{
	int x, y, w, h;
	int length = 0, width = 0;
	scanf("%d %d %d %d", &x,&y, &w, &h);

	if (x > w - x)
		length = w - x;
	else length = x;

	if (y > h - y)
		width = h - y;
	else width = y;

	if (length > width)
		printf("%d", width);
	else printf("%d", length);

	return 0;
}