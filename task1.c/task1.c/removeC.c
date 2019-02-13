#include <stdio.h>
void removeC()
{
	FILE *fp1,*fp2;                                 //defining file pointers
	char ch,ch1;                                    //defining character variables
	int flag = 0;                                   //flag variable is defined and initialized
	fp1 = fopen("abc.c", "r");                      //file abc.c is opened in read mode
	fp2 = fopen("xyz.c", "w");                      //file xyz.c is opened in write mode
	if (fp1 == NULL)
	{
		printf("\nInvalid file");
	}
	if (fp2 == NULL)
	{
		printf("\nInvalid file");
	}
	while ((ch = getchar(fp1)) != EOF)
	{
		ch1 = getchar(fp1++);                       //to get the next character in file
		if ((ch == '/') && (ch1 == '*'))            
		{
			flag == 1;
		}
		if ((ch == '*') && (ch1 == '/'))
		{
			flag == 0;
		}
		if (flag == 0)
		{
			fputc(ch, fp2);
		}
	}
	fclose(fp1);                                         //file abc.c is closed
	fclose(fp2);                                         //file xyz.c is closed
}