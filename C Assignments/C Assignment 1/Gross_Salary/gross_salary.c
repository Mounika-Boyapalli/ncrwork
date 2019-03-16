#include <stdio.h>
int main()
{
	int basic = 0, hra = 0, da = 0, total = 0;
	printf("\nEnter basic salary");
	scanf_s("%d", &basic);
	if ((basic >= 1) && (basic <= 4000))
	{
		hra = (10 * basic) / 100;
		da = (50 * basic) / 100;
	}
	else if ((basic >= 4001) && (basic <= 8000))
	{
		hra = (20 * basic) / 100;
		da = (60 * basic) / 100;
	}
	else if ((basic >= 8001) && (12000))
	{
		hra = (25 * basic) / 100;
		da = (70 * basic) / 100;
	}
	else
	{
		hra = (30 * basic) / 100;
		da = (80 * basic) / 100;
	}
	total = basic + hra + da;
	printf("\nGross Salary = %d ", total);
	getch();
	return 0;
}