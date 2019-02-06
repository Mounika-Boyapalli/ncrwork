#include<stdio.h>

long int bintodec(int);
long int dectobin(int);
int main()
{
	long int b, d, nd;
	long int nb;
	printf("\nEnter binary number");
	scanf_s("%ld", &b);
	printf("\nEnter decimal number");
	scanf_s("%ld", &d);
	
	nd = bintodec(b);
	nb = dectobin(d);

	printf("\n %ld is %ld", b, nd);
	printf("\n %ld is %ld", d, nb);

	getch();
	return 0;

}

long int bintodec(int n)
{
	int i, r;
	long int z = 0;
	for(i=0;n>0;i++)
	{
		r = n % 10;
		if (r == 1)
			z = z + (2 ^ i);
		n = n / 10;
	}
	return z;
}

long int dectobin(int n)
{
	int x = 0, base = 1, rem;
	while (n > 0)
	{
		rem = n % 2;
		x = x + rem*base;
		n = n / 2;
		base = base * 10;
	}
	return x;
}