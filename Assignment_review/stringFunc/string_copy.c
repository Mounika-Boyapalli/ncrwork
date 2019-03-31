#include<stdio.h>
#include<string.h>
int main()
{
	//declarations and initializations
	char *string = NULL, *string_cpy = NULL;
	int length = 0, index = 0;;

	//input string scanning and memory allocation
	printf("\nEnter the length of string");
	scanf_s("%d", &length);
	string = (char *)malloc(length+1 * sizeof(char));

	//output string memory allocation
	string_cpy = (char *)malloc(length+1 * sizeof(char));

	printf("\nEnter the string");
	scanf_s("%s", string,strlen(string));
	
	//copying string
	for(index=0;*(string+index);index++)
	{
		*(string_cpy + index) = *(string + index);
	}
	*(string_cpy + index) = '\0';

	//printing the string
	printf("\nString copied is %s", string);
	//free(string_cpy);
	//free(string);
	getch();
	return 0;
}