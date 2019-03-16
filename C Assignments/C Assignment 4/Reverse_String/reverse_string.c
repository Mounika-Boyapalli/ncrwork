#include <stdio.h>
void reverse(char *);
int main()
{
	char input_string[50];
	printf("\nEnter the string");
	scanf_s("%[^\n]s", input_string);
	reverse(input_string);
	getch();
	return 0;
}
void reverse(char *temp_string)
{
	if (*temp_string)
	{
		reverse(temp_string + 1);
		printf("%c", *temp_string);
	}
}