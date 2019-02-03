#include <stdio.h>


int main()

{

    int num, i, sum=0;

    printf("\nEnter a number");
    scanf("%d",&num);

    while(num!=0)

    {

        i = num%10;

        sum = sum+i;

        num = num/10;

    }

    printf("\nSum = %d",sum);

    return 0;

}