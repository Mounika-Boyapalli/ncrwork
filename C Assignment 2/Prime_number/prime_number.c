#include <stdio.h>
int main()
{
	int low_limit = 0, high_limit = 0, index = 0, num = 0, count = 0;
	printf("\nEnter the limits");
	scanf_s("%d %d", &low_limit, &high_limit);
	for (index = low_limit; num <= high_limit; num++)
	{
		for (index = 1; index <= num; index++)
		{
			if (num%index == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			printf("\n%d", num);
		}
		count = 0;
	}
	getch();
	return 0;
}