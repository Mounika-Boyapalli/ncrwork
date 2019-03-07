#include <stdio.h>
int main()
{
	int binary = 0, hexa_from_bin = 0, index = 0, base = 1, remainder = 0, hexa = 0, index2 = 0;
	printf("\nEnter the binary value");
	scanf_s("%d", &binary);
	printf("\nEnter the hexadecimal value");
	scanf_s("%x", &hexa);
	while (binary > 0)
	{
		remainder = binary % 10;
		hexa_from_bin = hexa_from_bin + remainder * base;
		binary = binary / 10;
		base = base * 2;
	}
	printf("\n Given binary in hex is %d\n", hexa_from_bin);
	for (index = 7; index >= 0; index--)
	{
		index2 = hexa >> index;
		if (index2 & 1)
			printf("1");
		else
			printf("0");
	}
	getch();
	return 0;
}