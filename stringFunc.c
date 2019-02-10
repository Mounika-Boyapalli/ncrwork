#include <stdio.h>

#include <string.h>


int main()

{

    char a[10], s[10];

    int n;

    printf("\nEnter a string");

    scanf("%s",s);

    printf("\nReversed string is %s",strrev(s));

    strcpy(a,s);

    strcat(a,s);

    printf("\nConcatenated string is %s",a);

    n=strcmp(a,s);

    if(n==0)

    {

        printf("\na and s are same");

    }

    else

    {

        printf("\na and s are not same");

    }

    getch();

    return 0;

}
