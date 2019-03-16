#include<stdio.h>
int main()
{
	char *color[6] = { "red","green","blue","white","black","yellow" };
	printf("\ncolor is %d", color);
	printf("\n(color+2) is %d", (color + 2));
	printf("\n*color is %s", *color);
	printf("\n*(color+2) is %s", *(color + 2));
	printf("\n*(color+5) is %s", *(color + 5));
	printf("\ncolor[5] is %s", color[5]);
	getch();
	return 0;
}