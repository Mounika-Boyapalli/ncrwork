#include <stdio.h>
void replaceT()
{
	FILE *fp1, *fp2;                          //file pointers are defined
	char ch;                                  //character is defined
	fp1 = fopen("abc.c", "r");                //file abc.c is opened in read mode
	fp2 = fopen("xyz.c", "w");                //file xyz.c is opened in write mode
	if (fp1 == NULL)
	{
		printf("\nInvalid file");
	}
	if (fp2 == NULL)
	{
		printf("\nInvalid file");
	}
	while ((ch=getchar(fp1)) != EOF)          //file is read char by char
	{
		if (ch == '	')                        //condition for checking whether character is tab
		{
			fputc('\\', fp2);                //replacing tab with \t in another file
			fp2++;
			fputc('t', fp2);
		}
		else
		{
			fputc(ch, fp2);                 //copying character into another file
		}
	}
	fclose(fp1);                           //file abc.c is closed
	fclose(fp2);                           //file xyz.c is closed
}