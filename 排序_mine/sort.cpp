#include<iostream>
using namespace std;
//��������
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;//�������е����һ��Ԫ�ص��±�
		int key = a[i + 1];//�������Ԫ��
		while (end >= 0)//�����ʼ�Ƚ�
		{
			if (a[end] > key)
			{
				a[end + 1] = a[end];//endλ���ϵ�ֵ�����һλ��Ϊ������Ԫ�ء��ճ�λ�á�
				end--;//ע�����һ��ѭ��ʱ��end+1λ�ò��ǡ���ȱ�ġ�
			}
			else break;
		}
		a[end + 1] = key;
	}
}
int main()
{
	int a[6] = { 1,5,8,3,4,2 };
	InsertSort(a, 6);
	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
	return 0;
}
