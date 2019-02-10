#include <stdio.h>



void reverse(char *);



int main()

{
    
    char s[50];

    printf("\nEnter the string");

    scanf("%[^\n]s",s);

    reverse(s);

    return 0;

}



void reverse(char *a)

{

    if(*a)

    {

        reverse(a+1);

        printf("%c",*a);

    }

}