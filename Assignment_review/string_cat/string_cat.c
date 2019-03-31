#include<stdio.h>
#include<string.h>
int main()
{
	//Definitions
	char *string1 = NULL, *string2 = NULL;
	int length_1 = 0, length_2 = 0;

	//Length of first string and the string are taken as input
	printf("\nEnter the length of first string");
	scanf_s("%d", &length_1);
	//Memory allocation for first string
	string1 = (char *)malloc((length_1 + 1) * sizeof(char));
	printf("\nEnter the first string");
	scanf_s("%s", string1, strlen(string1));
	
	//Length of second string and the string are scanned
	printf("\nEnter the length of second string");
	scanf_s("%d", &length_2);
	//Memory allocation for second string
	string2 = (char *)malloc((length_2 + 1) * sizeof(char));
	printf("\nEnter the second string");
	scanf_s("%s", string2, strlen(string2));

	//Reallocating memory of first string to accomadate concatenation
	//string1 = (char *)realloc(string1, length_2);
	realloc(string1, sizeof(char) * (length_1 + length_2 ));
	
	int index_1 = 0, index_2 = length_1;
	
	//concatenation of strings
	for (index_1 = 0; *(string2 + index_1); index_1++)
	{
		*(string1 + index_2) = *(string2 + index_1);
		index_2++;
	}
	*(string2 + index_2) = '\0';

	printf("\nConcatenated String is %s", string1);
	//free(string2);
	//free(string1);
	getch();
	return 0;
}