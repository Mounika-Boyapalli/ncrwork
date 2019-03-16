#include<stdio.h>
int replace(char []);
int main()
{
	char *cat = "The cat sat";
	int n;
	n = replace(cat);
	printf("\nNumber of spaces is %d", n);
	getch();
	return 0;
}

int replace(char a[])
{
	int x = 0, i, l;
	for (l = 0; a[l]; l++)
		for (i = 0; i < l; i++)
		{
			if (a[i] == ' ')
			{
				a[i] = '-';
				x++;
			}
		}
	printf("\n%s", a);
	return x;
}