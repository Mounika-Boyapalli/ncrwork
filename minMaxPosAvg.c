#include <stdio.h>


int main()

{

    int a[20];

    int i, j, temp, avg=0, min=0, max=0, pos=0, sum=0, length=0;

    for(i=0;;i++)

    {

        scanf("%d",&a[i]);

        if(a[i]<=0)

            break;

    }

    
for(i=0;;i++)

    {

        if(a[i]>0)

        {

            length ++;

        }

        else

        {

            break;

        }

    }

    pos = length;

    for(i=0;i<length;i++)

    {

        sum = sum + a[i];

        for(j=i+1;j<length;j++)

        {

            if(a[i]>a[j])

            {

                temp = a[i];

                a[i] = a[j];

                a[j] = temp;

            }

        }

    }

    max  = a[length-1];

    min = a[0];

    avg = sum/length;

    printf("\nNumber of positive values = %d\nMinimum value = %d\nMaximum value = %d\nAverage value = %d",pos,min,max,avg);


    return 0;

}
