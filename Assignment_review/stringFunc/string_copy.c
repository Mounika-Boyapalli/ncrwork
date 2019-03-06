#include<stdio.h>
#include<string.h>
int main()
{
	char *string = NULL, *string_cpy = NULL;
	int length;
	printf("\nEnter the length of string");
	scanf_s("%d", &length);
	string = (char *)malloc(length+1 * sizeof(char));
	string_cpy = (char *)malloc(length+1 * sizeof(char));
	printf("\nEnter the string");
	scanf_s("%s", string,strlen(string));
	while (*string = *string_cpy)
	{
		if (*string == '\0')
			break;
		string++;
		string_cpy++;
	}
	printf("\nString copied is %s", string_cpy);
	getch();
	return 0;
}