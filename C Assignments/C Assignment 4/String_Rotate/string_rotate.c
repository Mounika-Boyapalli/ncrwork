#include <stdio.h>
#include <string.h>
int main()
{
	char input_string[10];
	int string_length = 0, index1 = 0, index2 = 0;
	printf("\nEnter the string");
	scanf_s("%s", input_string);
	string_length = strlen(input_string);
	int new_length = 2 * string_length;
	char a[new_length];
	strcpy(a, input_string);
	strcat(a, input_string);
	for (index1 = 0; index1 < string_length; index1++)
	{
		for (index2 = index1; index2 < index1 + string_length; index2++)
		{
			printf("%c", a[index2]);
		}
		printf("\n");
	}
	getch();
	return 0;
}