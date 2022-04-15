#include<stdio.h>
#include<string.h>
#define SIZE 51
#define N 100
int main(void)
{
	int n,index=0;
	char a[N][SIZE];
	printf("请输入字符串个数：");
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		printf("请输入第%d个字符串：",i+1) ;
		scanf("%s",&a[i]);
	}
	for(int i=1;i<n;++i)
		if(strcmp(a[i],a[index])<0)
			index=i;
	printf("%s\n",a[index]);
	return 0;
 } 
