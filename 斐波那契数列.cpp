#include<stdio.h>
int fibon(int n)
{
	switch(n)
	{
		case 0:return 0;break;
		case 1:return 1;break;
		default:return fibon(n-1)+fibon(n-2);	
	}
 } 
 int main(void)
 {
 	int n;
 	scanf("%d",&n);
 	int c=fibon(n);
	printf("%d\n",c);
	return 0;
 }
