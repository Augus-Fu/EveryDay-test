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
	listpoint* head, * end, * normal;
	head = (listpoint*)malloc(sizeof(listpoint));
	head->a = (point*)malloc(sizeof(point));
	end = head;
	for(int i = 0; i < n; i++)
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
		end->next = normal;
		normal->pre = end;
		end = normal;
	}
	end->next = NULL;
	head->pre = NULL;
	return head;
}
//ɾ������Ԫ��

void delete_point(listpoint* list, int n)
{
	listpoint* p;
	p = list;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}
int main()
{
	listpoint *head;
	head = create_list(3);
	delete_point(head, 1);
	system("pause");
	return 0;
}