#include "stdio.h"
#include<math.h>
int main()
{
	float a, b, c, i, j, k, Sab, Sac, Sbc;
	scanf_s("%f %f %f", &a, &b, &c);
	i = (float)sqrt(pow(a, 2) + pow(b, 2));//求根下a2+b2
	j = (float)sqrt(pow(a, 2) + pow(c, 2));//求根下a2+c2
	k = (float)sqrt(pow(b, 2) + pow(c, 2));//求根下b2+c2
	Sab = ((float)((int)(i * 1000) / 1000));//保留三位小数
	Sac = ((float)((int)(i * 1000) / 1000));	
	Sbc = ((float)((int)(i * 1000) / 1000));
	if (a + b <= c || a + c <= b || b + c <= a)//根据定义判断是否是三角形
		printf("不能构成三角形\n");
	else
	{
		if (a == b && a == c)
			printf("该三角形是等边三角形\n");
		else if (a == b || b == c || a == c)
		{
			if (Sab = c || Sbc == a || Sac == b)
				printf("该三角形是等腰直角三角形\n");
			else
				printf("该三角形是等腰三角形\n");
		}
		else if (Sab = c || Sbc == a || Sac == b)
			printf("该三角形是直角三角形\n");
		else
			printf("该三角形是一般三角形\n");
	}
	return 0;
}
