#include<stdio.h>
int invert(int, int, int);
int main()
{
	int x, p, n, r;
	int invert(int, int, int);
	printf("Enter integer, start position, invert length \n");
	scanf_s("%d %d %d", &x, &p, &n);
	printf("Coverted binary value of %d is\t", x);
	r = invert(x, p, n);
	getch();
	return 0;
}

int invert(int X, int P, int N)
{
	int I, Y, LIMIT, LEN, BIN[15];
	LEN = 0;
	while (X > 0)
	{
		BIN[LEN] = X % 2;
		X = X / 2;
		LEN++;
	};

	for (I = LEN - 1; I > -1; I--)
	{
		printf("%d ", BIN[I]);
	}
	printf("\n");
	LIMIT = P + N;
	if (LIMIT < LEN)
	{
		for (I = P + N - 1; I > P - 1; I--)
		{
			if (BIN[I] == 0)
				BIN[I] = 1;
			else
				BIN[I] = 0;
		}
	}
	else
	{
		printf("YOU HAVE ENTERED LARGE VALUE FOR P AND N");
	}

	printf("Inverted integer in binary form is \t");
	for (I = LEN - 1; I > -1; I--)
	{
		printf("%d ", BIN[I]);
	}

}