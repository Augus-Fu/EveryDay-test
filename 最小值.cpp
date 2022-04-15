#include<stdio.h>
#define N 4
#define M 4
int SumColumMin(int a[M][N],int *min)
{
	int sum=0;
	for(int i=0;i<N;i++)
	{
		int k=0;
		for(int j=0;j<M;j++)
		{
			if(a[k][i]>a[j][i])	k=j;	
		}
		*min=a[k][i];
		sum+=a[k][i];
		min++;
	}
	return sum;
} 
int main(void)
{
	int a[M][N],min[10];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	int s=SumColumMin(a,min);
	for(int i=0;i<=N-1;i++)
		printf("%d ",min[i]);
	printf("%d\n",s); 
	return 0;
}

