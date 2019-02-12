

void counta()
{
	FILE *fp;                                            //defining file pointer
	char ch;                                             //defining character variable
	int alpha = 0, digits = 0, sc = 0, spaces = 0;       //initializing count values
	fopen_s(&fp, "sample.txt", "r");                            //file is opened
	if (fp == NULL)
	{
		printf("\nInvalid file");
	}
	while ((ch = fgetc(fp)) != EOF)                      //file is read char by char
	{
		if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))    //condition for checking if alphabet
		{
			alpha++;
		}
		else if ((ch >= '0') && (ch <= '9'))    //condition for checking if digit
		{
			digits++;
		}
		else if (ch == ' ')                    //condition for checking if space
		{
			spaces++;
		}
		else
		{
			sc++;
		}
	}
	fclose(fp);                                  //file is closed
	printf("\nNumber of alphabets is %d", alpha);
	printf("\nNumber of digits is %d", digits);
	printf("\nNumber of spaces is %d", spaces);
	printf("\nNumber of special characters is %d", sc);

}