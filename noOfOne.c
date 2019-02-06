#include<stdio.h>
int main()
{
	int n, i,count=0;
	printf("\nEnter the binary number");
	scanf_s("%d", &n);

	while (n > 0)
	{
		i = n % 10;
		if (i == 1)
		{
			count++;
		}
		n = n / 10;
	}
	printf("\nNumber of ones is %d", count);
	getch();
	return 0;
}