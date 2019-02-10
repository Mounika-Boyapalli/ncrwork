#include <stdio.h>

#include <string.h>


int main()

{

    char s[10];

    int l,i,j;

    printf("\nEnter the string");

    scanf("%s",s);

    for(l=0;s[l];l++);

    char a[2*l];

    strcpy(a,s);

    strcat(a,s);

    for(i=0;i<l;i++)

    {

        for(j=i;j<i+l;j++)

        {

            printf("%c",a[j]);

        }

        printf("\n");

    }

    getch();
    return 0;

}