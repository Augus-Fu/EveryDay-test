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
 		printf("�������ţ�");
		scanf("%d",&con[i].code) ;
		printf("����������: "); 
		scanf("%s",&con[i].name);
		printf("������绰���룺");
		scanf("%s",&con[i].tel);
		printf("\n"); 
	}
	for(int i=0;i<100;i++)
		printf("���:%d\t ����:%s\t �绰����:%s\n",con[i].code,con[i].name,con[i].tel);
 	return 0;
 }
