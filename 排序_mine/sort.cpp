#include<iostream>
using namespace std;
//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;//有序序列的最后一个元素的下标
		int key = a[i + 1];//待插入的元素
		while (end >= 0)//从最大开始比较
		{
			if (a[end] > key)
			{
				a[end + 1] = a[end];//end位置上的值向后退一位，为待插入元素“空出位置”
				end--;//注意最后一次循环时，end+1位置才是“空缺的”
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
