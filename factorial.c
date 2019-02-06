#include <stdio.h>


int main()

{

    int n,i,p=1;

    printf("\nEnter the number");

    scanf("%d",&n);

    for(i=n;i>=1;i--)

    {

        p=p*i;

    }

    printf("\n%d is the factorial of %d",p,n);


    return 0;

}