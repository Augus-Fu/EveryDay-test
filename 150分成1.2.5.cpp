#include <stdio.h>
int main(void)
{ 
	int a,b,c,d=0;
	for(a=1;a<30;a++)
		for(b=1;b<73;b++)
		{	c=100-a-b;
			 if(a*5+b*2+c==150)
			 	{
				printf("a=%d,b=%d,c=%d\n",a,b,c);
				d++; 
				}
		}
		printf("%d\n",d);
     return 0;
}


