#include <stdio.h>
#include <string.h>
int main()
{
	char input_string[50];
	printf("\nEnter the string");
	scanf_s("%s", input_string);
	char *token_string = strtok(input_string, ".");
	while (token_string != NULL)
	{
		printf("%s\n", token_string);
		token_string = strtok(NULL, ".");
	}
	getch();
	return 0;
}
