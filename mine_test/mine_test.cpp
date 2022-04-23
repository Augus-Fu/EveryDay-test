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
		/*给新节点分配内存*/
		cout << "input the X :";
		cin >> normal->a->x;
		cout << "input the Y  :";
		cin >> normal->a->y;
		cout << "----------------------------------" << endl;
		/* 往新节点存入数据，注意我们只给后面的节点存入数据，head不存数据*/
		end->next = normal;
		normal->pre = end;
		end = normal;
	}
	end->next = NULL;
	head->pre = NULL;
	return head;
}
//删除链表元素

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