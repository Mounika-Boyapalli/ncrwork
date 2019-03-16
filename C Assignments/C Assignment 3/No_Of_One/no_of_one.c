#include<stdio.h>
int main()
{
	int bin_num = 0, remainder = 0, count = 0;
	printf("\nEnter the binary number");
	scanf_s("%d", &bin_num);

	while (bin_num > 0)
	{
		remainder = bin_num % 10;
		if (remainder == 1)
		{
			count++;
		}
		bin_num = bin_num / 10;
	}
	printf("\nNumber of ones is %d", count);
	getch();
	return 0;
}