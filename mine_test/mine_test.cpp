#include<iostream>
using namespace std;
typedef struct piont
{
	int x;
	int y;
}point;
typedef struct listpoint
{
	point* a;
	listpoint* pre;
	listpoint* next;
}listpoint;
listpoint* create_list(int n)
{
	listpoint* head, * normal, * end;
	head = (listpoint*)malloc(sizeof(listpoint));
	head->a = (point*)malloc(sizeof(point));
	end = head;
	for (int i = 0; i < n; i++)
	{
		normal = (listpoint*)malloc(sizeof(listpoint));
		normal->a = (point*)malloc(sizeof(point));
		/*���½ڵ�����ڴ�*/
		cout << "input the X :";
		cin >> normal->a->x;
		cout << "input the Y  :";
		cin >> normal->a->y;
		cout << "----------------------------------" << endl;
		/* ���½ڵ�������ݣ�ע������ֻ������Ľڵ�������ݣ�head��������*/
		end->next = normal;/*��end�������½ڵ�*/
		normal->pre = end;/*�½ڵ����һ���ڵ����end*/
		end = normal;/*���һ���ڵ����½ڵ�*/
	}
	end->next = NULL;/*��������ָ��һ���µ�ַ*/
	head->pre = NULL;/*�����ʼ�Ľڵ�û����һ���ڵ�*/
	return head;
}
int main()
{
	listpoint *a;
	a = create_list(3);
	system("pause");
	return 0;
}