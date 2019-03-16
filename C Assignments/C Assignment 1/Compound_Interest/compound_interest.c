#include<stdio.h>
#include<math.h>
int main()
{

	float interest_rate = 0, simple_int = 0, annually_comp = 0, half_yearly_comp = 0, quaterly_comp = 0, monthly_comp = 0, daily_comp = 0;
	printf("\nEnter the rate of interest");
	scanf_s("%f", &interest_rate);
	simple_int = (500000 * 10 * interest_rate) / 100;
	printf("\nSimple interest is %lf", simple_int);
	annually_comp = 500000 * (pow((1 + interest_rate / 100), 10));
	printf("\nInterest compounded annually is %lf", annually_comp);
	half_yearly_comp = 500000 * (pow((1 + interest_rate / 200), 20));
	printf("\nInterest compounded semi-annually is %lf", half_yearly_comp);
	quaterly_comp = 500000 * (pow((1 + interest_rate / 400), 40));
	printf("\nInterest compounded quaterly is %lf", quaterly_comp);
	monthly_comp = 500000 * (pow((1 + interest_rate / 1200), 120));
	printf("\nInterest compounded monthly is %lf", monthly_comp);
	daily_comp = 500000 * (pow((1 + interest_rate / 36500), 3650));
	printf("\nInterest compounded daily is %lf", daily_comp);
	getch();
	return 0;
}