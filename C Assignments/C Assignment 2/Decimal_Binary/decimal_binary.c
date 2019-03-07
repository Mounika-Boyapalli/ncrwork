#include<stdio.h>
long int bintodec(int);
long int dectobin(int);
int main()
{
	long int binary = 0, decimal = 0;
	long int dec_from_bin = 0, bin_from_dec = 0;
	printf("\nEnter binary number");
	scanf_s("%ld", &binary);
	printf("\nEnter decimal number");
	scanf_s("%ld", &decimal);

	dec_from_bin = bintodec(binary);
	bin_from_dec = dectobin(decimal);

	printf("\n %ld is %ld", binary, dec_from_bin);
	printf("\n %ld is %ld", decimal, bin_from_dec);

	getch();
	return 0;

}

long int bintodec(int bin)
{
	int index = 0, remainder = 0;
	long int dec = 0;
	for (index = 0; bin > 0; index++)
	{
		remainder = bin % 10;
		if (remainder == 1)
			dec = dec + (2 ^ index);
		bin = bin / 10;
	}
	return dec;
}

long int dectobin(int dec)
{
	int bin = 0, base = 1, remainder = 0;
	while (dec > 0)
	{
		remainder = dec % 2;
		bin = bin + remainder * base;
		dec = dec / 2;
		base = base * 10;
	}
	return bin;
}