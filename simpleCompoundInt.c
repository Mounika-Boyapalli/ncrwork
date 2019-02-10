#include<stdio.h>
#include<math.h>
int main()
{

	float r, in, cin, cins, cinq, cinm, cind;
	printf("\nEnter the rate of interest");
	scanf_s("%f", &r);

	in = (500000 * 10 * r) / 100;

	printf("\nSimple interest is %lf", in);

	cin = 500000 * (pow((1 + r / 100), 10));

	printf("\nInterest compounded annually is %lf", cin);
	cins = 500000 * (pow((1 + r / 200), 10));

	printf("\nInterest compounded semi-annually is %lf", cins);
	cinq = 500000 * (pow((1 + r / 400), 10));

	printf("\nInterest compounded quaterly is %lf", cinq);
	cinm = 500000 * (pow((1 + r / 1200), 10));

	printf("\nInterest compounded monthly is %lf", cinm);
	cind = 500000 * (pow((1 + r / 36500), 10));

	printf("\nInterest compounded daily is %lf", cind);
	getch();
	return 0;
}