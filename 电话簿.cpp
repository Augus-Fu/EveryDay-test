#include<stdio.h>
typedef struct con
{
	int code;
	char name[101];
	char tel[16];
 } CON;
 int main (void)
 {
 	CON con[100];
 	for(int i=0;i<100;i++)
 	{
 		printf("ÇëÊäÈë±àºÅ£º");
		scanf("%d",&con[i].code) ;
		printf("ÇëÊäÈëÐÕÃû: "); 
		scanf("%s",&con[i].name);
		printf("ÇëÊäÈëµç»°ºÅÂë£º");
		scanf("%s",&con[i].tel);
		printf("\n"); 
	}
	for(int i=0;i<100;i++)
		printf("±àºÅ:%d\t ÐÕÃû:%s\t µç»°ºÅÂë:%s\n",con[i].code,con[i].name,con[i].tel);
 	return 0;
 }
