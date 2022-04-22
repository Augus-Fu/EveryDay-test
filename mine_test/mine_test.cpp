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
		/*给新节点分配内存*/
		cout << "input the X :";
		cin >> normal->a->x;
		cout << "input the Y  :";
		cin >> normal->a->y;
		cout << "----------------------------------" << endl;
		/* 往新节点存入数据，注意我们只给后面的节点存入数据，head不存数据*/
		end->next = normal;/*往end后增添新节点*/
		normal->pre = end;/*新节点的上一个节点就是end*/
		end = normal;/*最后一个节点变成新节点*/
	}
	end->next = NULL;/*链表的最后指向一个新地址*/
	head->pre = NULL;/*链表最开始的节点没有上一个节点*/
	return head;
}
int main()
{
	listpoint *a;
	a = create_list(3);
	system("pause");
	return 0;
}