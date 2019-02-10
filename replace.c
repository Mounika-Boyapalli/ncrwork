#include <stdio.h>

void delete(char *,char);


int main()

{

    char s[50];

    char c = 'a';

    printf("\nEnter the string");

    
scanf("%[^\n]s",s);

    
delete(s,c);

    getch();
    return 0;
}


void delete(char *a,char c)

{

    int i,l;

    for(l=0;a[l];l++);

    for(i=0;i<l;i++)

    {

        if(a[i]!=c)

        {

            printf("%c",a[i]);

        }

    }

}