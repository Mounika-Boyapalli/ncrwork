#include <stdio.h>
void delete(char *, char);
int main()
{
	char input_string[50];
	char char_to_be_deleted = 'a';
	printf("\nEnter the string");
	scanf_s("%[^\n]s", input_string);
	delete(input_string, char_to_be_deleted);
	getch();
	return 0;
}
void delete(char *a, char c)
{
	int index = 0, length = 0;
	for (length = 0; a[length]; length++);
	for (index = 0; index < length; index++)
	{
		if (a[index] != c)
		{
			printf("%c", a[index]);
		}
	}
}