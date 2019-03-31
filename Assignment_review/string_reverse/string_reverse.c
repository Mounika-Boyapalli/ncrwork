#include<stdio.h>
#include<string.h>
int main()
{
	//declarations and initializations
	char *string = NULL, *string_rev = NULL;
	int length = 0, index1 = 0, index2 = 0;

	//first string allocations
	printf("\nEnter the length of string");
	scanf_s("%d", &length);
	string = (char *)malloc(length + 1 * sizeof(char));

	//second string allocation
	string_rev = (char *)malloc(length + 1 * sizeof(char));

	printf("\nEnter the string");
	scanf_s("%s", string, strlen(string));

	//reversing first string
	for (index1 = length - 1; index1 >= 0; index1--)
	{
		*(string_rev + index2) = *(string + index1);
		index2++;
	}
	*(string_rev + index2) = '\0';

	printf("\nReversed String is %s", string_rev);
	//free(string_rev);
	//free(string);
	getch();
	return 0;
}