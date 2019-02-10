#include <stdio.h>


int main()

{

    char s[50];

    int i, l;

    printf("\nEnter the string");

    scanf_s("%[^\n]s",s);

    for(l=0;s[l];l++);

    for(i=0;i<l;i++)

    {

        if((s[i]>='A')&&(s[i]<='Z'))

        {

            s[i] = s[i] + 32;

        }

        else if((s[i]>='a')&&(s[i]<='z'))

        {

            s[i] = s[i] - 32;
   
      }

    }

    printf("%s",s);

 

   getch();
    return 0;

}