#include <stdio.h>
#include <string.h>
void rotateS(char *a)
{
	int l=0,i;
	char ch;
	FILE *fp1, *fp2;
	fp1 = fopen("abc.c", "r");
	fp2 = fopen("abc.c", "w");
	if (fp1 == NULL)
	{
		printf("\nInvalid file");
	}
	if (fp2 == NULL)
	{
		printf("\nInvalid file");
	}
	for (l = 0; a[l]; l++);
	char b[20];
	strcpy(b, a);
	strcat(b, a);
	for (i = 0; i < l; i++)           //rotating the given word
	{
		a[i] = b[i + 1];
	}
	while ((ch=getchar(fp1)) != EOF)
	{
		
	}
}