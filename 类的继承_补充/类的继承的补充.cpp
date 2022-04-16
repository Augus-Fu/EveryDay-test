#include<iostream>
using namespace std;
class CP_A
{
public:
	int m_a;
	CP_A(int i = 1) :m_a(i) { cout << "m_a=" << m_a << endl; }
};
class CP_B:public CP_A
{
public:
	int m_b;
	CP_B(int i = 10): m_b(i),CP_A(i) {}
};
class CP_C :public CP_A
{
public:
	int m_c;
	CP_C(int i = 3) :m_c(i), CP_A(i) { cout<<"C:m_a=" << m_a << endl; }
};
class CP_D :public CP_A
{
public:
	int m_d;
	CP_D(int i = 4) :m_d(i), CP_A(i) { cout  << "D:m_a=" << m_a << endl; }
	void index(int i)
	{
		m_a = 521;
	}
	void show()
	{
		cout << "D:m_a=" << m_a << endl;
	}
};
class CP_E:private CP_A {  };
int main()
{
	/*CP_A A;
	CP_B B;
	cout << A.a << endl;
	A = B;
	cout << B.a << endl;
	CP_B C;
	CP_A& D = C;
	cout << D.a << endl;
	CP_A* p = &C;
	cout << p->a << endl;
	*/
	CP_C c;
	CP_A& a = c;//用子类的实例对象来初始化父类的对象
	CP_D d;
	CP_A *a1=&d;
	cout << "a1->m_a=" << a1->m_a << endl;
	d.index(521);
	d.show();
	CP_E e;
	::CP_A* pa = (::CP_A*)&e;//显示转换指针
	cout << "pa->m_a=" << pa->m_a << endl;
	system("pause");
	return 0;
}