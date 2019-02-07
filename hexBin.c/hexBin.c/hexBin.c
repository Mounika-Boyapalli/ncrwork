#include <stdio.h>
int main()
{
	int b, hb = 0, i, base = 1, r, h, k;
	printf("\nEnter the binary value");
	scanf_s("%d", &b);
	printf("\nEnter the hexadecimal value");
	scanf_s("%x", &h);
	while (b > 0)
	{
		r = b % 10;
		hb = hb + r*base;
		b = b / 10;
		base = base * 2;
	}
	printf("\n Given binary in hex is %d\n", hb);
	for (i = 7; i >= 0; i--)
	{
		k = h >> i;
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	getch();
	return 0;
}