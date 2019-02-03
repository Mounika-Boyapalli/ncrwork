#include <stdio.h>


int main()

{

    int num, i, inum=0, sum=0;

    printf("\nEnter a number");
    scanf("%d",&num);

    inum = num;

    while(num!=0)

    {

        i = num%10;

        sum = sum + i*i*i;

        num = num/10;

    }

    if(inum==sum)

    {

        printf("\n%d is an armstrong number",inum);

    }

    else

    {

        printf("\n%d is not an armstrong number",inum);

    }

    return 0;

}