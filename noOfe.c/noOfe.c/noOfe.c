#include<stdio.h>
int main()
{
	char *s[] = { "we will teeach you how to","Move a mountain","Level a building","Erase the past","Make a million" };
	int i,j,count = 0;
	for (i = 0; i<5; i++)
	{
		char *a = *(s + i);
		for (j = 0; a[j] != '\0'; j++)
		{
			if (a[j] == 'e' || a[j] == 'E')
			{
				count++;
			}
		}
	}
	printf("\nNumber of e is %d", count-1);
	getch();
	return 0;
}