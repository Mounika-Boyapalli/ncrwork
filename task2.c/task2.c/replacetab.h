#include<stdio.h>
void replacetab()
{
	FILE *fp1, *fp2;                          //file pointers are defined
	char ch,ch2;                                  //character is defined
    fopen_s(&fp1,"sample.txt", "r");                //file sample.txt is opened in read mode
	fopen_s(&fp2,"xyz.txt", "w");                //file xyz.txt is opened in write mode
	if (fp1 == NULL)
	{
		printf("\nInvalid file");
	}
	if (fp2 == NULL)
	{
		printf("\nInvalid file");
	}
	while ((ch = fgetc(fp1)) != EOF)          //file is read char by char
	{
		if (ch == '\t')                        //condition for checking whether character is tab
		{
			ch2 = '\\';
			fputc(ch2, fp2);                //replacing tab with \t in another file
			ch2 = 't';
			fputc(ch2, fp2);
		}
		else
		{
			fputc(ch, fp2);                 //copying character into another file
		}
		
	}
	fclose(fp1);                           //file sample.txt is closed
	fclose(fp2);                           //file xyz.txt is closed
	printf("\nTabs are replaced in new file");
}