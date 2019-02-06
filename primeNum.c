#include <stdio.h>


int main()

{

    int l,h,i,n,count=0;

    printf("\nEnter the limits");

    scanf("%d %d",&l,&h);

    for(n=l;n<=h;n++)

    {

        for(i=1;i<=n;i++)

        {

            if(n%i==0)

            {

                count++;

            }

        }

        if(count==2)

        {

            printf("\n%d",n);

        }

        count=0;

    }
 
    return 0;
}