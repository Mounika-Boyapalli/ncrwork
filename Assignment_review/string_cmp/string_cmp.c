#include<stdio.h>
#include<string.h>
int main()
{
	//declarations and initializations
	char *string1 = NULL, *string2 = NULL;
	int length_1 = 0, length_2 = 0, index = 0, count = 0;

	//first string allocation
	printf("\nEnter the length of first string");
	scanf_s("%d", &length_1);
	string1 = (char *)malloc(length_1 + 1 * sizeof(char));
	printf("\nEnter the first string");
	scanf_s("%s", string1, strlen(string1));

	//second string allocation
	printf("\nEnter the length of second string");
	scanf_s("%d", &length_2);
	string2 = (char *)malloc(length_2 + 1 * sizeof(char));
	printf("\nEnter the first string");
	scanf_s("%s", string2, strlen(string2));

	//if lengths are not equal then strings are not equal
	if (length_1 == length_2)
	{
		while (*(string1 + index) != '\0' || *(string2 + index) != '\0')
		{
			if (*(string1 + index) != *(string2 + index))
				count++;
			index++;
		}
		if (count == 0)
			printf("\nBoth strings are same");
		else
		{
			printf("\nBoth strings are not same. They differ by %d characters", count);
		}
	}
	else
	{
		printf("\nBoth strings are not same");
	}
	//free(string2);
	//free(string1);
	getch();
	return 0;
}