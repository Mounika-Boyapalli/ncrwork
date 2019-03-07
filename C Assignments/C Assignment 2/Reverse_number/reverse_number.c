#include <stdio.h>
int main()
{
	int input = 0, index = 0, rev_num = 0;
	printf("\nEnter a number");
	scanf_s("%d", &input);
	while (input > 0)
	{
		input = input % 10;
		rev_num = rev_num * 10 + index;
		input = input / 10;
	}
	printf("Reversed number is %d", rev_num);
	getch();
	return 0;
}