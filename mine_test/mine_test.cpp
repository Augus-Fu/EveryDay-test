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
		cout << "input the X : ";
		cin >> normal->a->x;
		cout << "input the Y : ";
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

//�ı������е�ĳ���ڵ�
void change_point(listpoint* list, int n, point* ifmation)
{
	listpoint* p;
	p = list;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	p->a = ifmation;
}

//����һ���ڵ�
void insert_point(listpoint* list, int n, point* ifmation)
{
	listpoint* p,*in;
	in = (listpoint*)malloc(sizeof(listpoint));
	in->a = (point*)malloc(sizeof(point));
	in->a = ifmation;
	p = list;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	p->next->pre = in;
	in->next = p->next;
	p->next = in;
	in->pre = p;
}

//�õ���n���ڵ�
listpoint* search_point(listpoint* list, int n)
{
	listpoint* p;
	p = (listpoint*)malloc(sizeof(listpoint));
	p = list;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	return p;
}

//�����n���ڵ�
void output_point(listpoint* point)
{
	cout << "X:" << point->a->x << endl;
	cout << "Y:" << point->a->y << endl;
	cout << "----------------------------------" << endl;
}

//�������
void output_list(listpoint* point)
{
	listpoint* p;
	p = point;
	cout << endl << endl;
	while ((p=p->next) != NULL)
		output_point(p);
}

//��������n~m���ڵ�
void output_list_part(listpoint* list, int n, int m)
{
	listpoint* p;
	p = list;
	for (int i = 1; i < n; i++)
	{
		list = list->next;
	}
	for (int i = n; i < m+1; i++)
	{
		output_point(list);
		list = list->next;
	}
}
int main()
{
	listpoint *head;
	head = create_list(4);
	delete_point(head, 1);
	cout << head->next->a->x << " " << head->next->a->y << endl;
	point* B;
	B = (point*)malloc(sizeof(point));
	B->x = 521;
	B->y = 250;
	change_point(head, 1, B);
	cout << head->next->a->x << " " << head->next->a->y << endl;
	change_point(head, 2, B);
	cout << head->next->next->a->x << " " << head->next->next->a->y << endl;
	output_point(search_point(head, 3));
	output_list(head);
	cout << endl << endl;
	output_list_part(head, 2, 3);
	system("pause");
	return 0;
}