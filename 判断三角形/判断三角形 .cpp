#include "stdio.h"
#include<math.h>
int main()
{
	float a, b, c, i, j, k, Sab, Sac, Sbc;
	scanf_s("%f %f %f", &a, &b, &c);
	i = (float)sqrt(pow(a, 2) + pow(b, 2));//�����a2+b2
	j = (float)sqrt(pow(a, 2) + pow(c, 2));//�����a2+c2
	k = (float)sqrt(pow(b, 2) + pow(c, 2));//�����b2+c2
	Sab = ((float)((int)(i * 1000) / 1000));//������λС��
	Sac = ((float)((int)(i * 1000) / 1000));	
	Sbc = ((float)((int)(i * 1000) / 1000));
	if (a + b <= c || a + c <= b || b + c <= a)//���ݶ����ж��Ƿ���������
		printf("���ܹ���������\n");
	else
	{
		if (a == b && a == c)
			printf("���������ǵȱ�������\n");
		else if (a == b || b == c || a == c)
		{
			if (Sab = c || Sbc == a || Sac == b)
				printf("���������ǵ���ֱ��������\n");
			else
				printf("���������ǵ���������\n");
		}
		else if (Sab = c || Sbc == a || Sac == b)
			printf("����������ֱ��������\n");
		else
			printf("����������һ��������\n");
	}
	return 0;
}
