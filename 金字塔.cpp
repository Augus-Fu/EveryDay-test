#include<stdio.h>
void draw(int n)
{	
	for(int b=1;b<=n;b++)
		{
			for(int i=12-b;i>0;i--)
				printf(" ");
			{
				for(int a=1;a<=2*b-1;a++)
					printf("*");
					printf("\n");
			} 
		}
}
int main(void)
{
	int i;
	scanf("%d",&i);
	draw(i); 
	return 0;	
 } 
