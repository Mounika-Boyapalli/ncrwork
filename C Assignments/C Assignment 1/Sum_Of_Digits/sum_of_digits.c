#include <stdio.h>
int main()
{
	int input = 0, remainder = 0, sum = 0;
	printf("\nEnter a number");
	scanf_s("%d", &input);
	while (input != 0)
	{
		remainder = input % 10;
		sum = sum + remainder;
		input = input / 10;
	}
	printf("\nSum = %d", sum);
	getch();
	return 0;
}