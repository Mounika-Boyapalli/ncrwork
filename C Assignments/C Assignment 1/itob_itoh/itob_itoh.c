#include <stdio.h>
int itob(int n, int s);
int itoh(int n, int s);
int main()
{
	long int int_num = 0, bin_output = 0, return_output = 0;
	printf("\nEnter an integer");
	scanf_s("%ld", &int_num);
	bin_output = itob(int_num, return_output);
	itoh(int_num, return_output);
	printf("\nBinary = %ld", bin_output);
	getch();
	return 0;
}

int itob(int n, int s)
{
	int remainder, base = 1;
	while (n > 0)
	{
		remainder = n % 2;
		s = s + remainder * base;
		n = n / 2;
		base = base * 10;
	}
	return s;
}

int itoh(int n, int s)
{
	printf("\nHexa Decimal = %x", n);
	return 0;
}