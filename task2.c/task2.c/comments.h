#include <stdio.h>
void comments()
{
	FILE *fp1, *fp2;                          //file pointers are defined
	char ch, ch2;                                  //character is defined
	fopen_s(&fp1, "sample.txt", "r");                //file sample.txt is opened in read mode
	fopen_s(&fp2, "nocomments.txt", "w");                //file xyz.txt is opened in write mode
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
		if (ch == '/')
		{
			ch = fgetc(fp1);

			if (ch == '/')
			{
				while (ch != '\n')
				{
					ch = fgetc(fp1);

				}
			}

			if (ch == '*')
			{
				ch = fgetc(fp1);
				while (ch != '*')
				{
					ch = fgetc(fp1);
					if (ch == '/')
					{
						ch = fgetc(fp1);
						break;
					}

				}
			}

		}
		fputc(ch, fp2);
	}
    
	fclose(fp1);
	fclose(fp2);

	printf("\nComments are removed in the new file");
}