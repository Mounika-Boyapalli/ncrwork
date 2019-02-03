#include <stdio.h>


int main()

{

    int num, i, inum=0, rev=0;

    printf("\nEnter a number");
    scanf("%d",&num);

    inum = num;

    while(num!=0)

    {

        i = num%10;

        rev = (rev*10)+i;

        num = num/10;

    }

    if(inum==rev)

    {

        printf("\n%d is a palindrome",inum);

    }

    else

    {

        printf("\n%d is not a palindrome",inum);

    }
    return 0;

}