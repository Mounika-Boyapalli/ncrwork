#include <stdio.h>

#include <string.h>


int main()

{

    char s[50];

    printf("\nEnter the string");

    scanf("%s",s);

    char *a= strtok(s,".");

    while(a!=NULL)

    {

        printf("%s\n", a);
 
       a = strtok(NULL, ".");
 
    }
 
    getch();

    return 0;

}
