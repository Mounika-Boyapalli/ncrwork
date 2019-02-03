#include <stdio.h>

int itob( int n, int s);

int itoh(int n, int s);

int main()

{

    long int n,b,h,s=0;

    printf("\nEnter a decimal number");
    scanf("%ld",&n);

    b = itob (n,s);

    itoh (n,s);

    printf("\nBinary = %ld",b);

    return 0;

}


int itob(int n,int s)

{

    int remainder, base = 1;

    while(n>0)

    {

        remainder = n%2;

        s = s + remainder*base;

        n = n/2;

        base = base *10;

    }

    return s;

}


int itoh(int n, int s)

{

    printf("\nHexa Decimal = %x",n);

}