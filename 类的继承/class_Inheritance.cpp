#include<iostream>
using namespace std;

class A
{
public:
	int a;
	//A() { a = 0; };//�����湹�췽��һ��Ч��
	A() :a(0) { }
	/*
	A(int i)
	{
		a = i;
	}//�����湹�췽��һ��Ч��
	*/
	A(int i) :a(i) { }
	~A() { }
};
/*
���캯���У�A(){  }��A(int i=0){  }����ͬʱ����
A( int i=0){}�൱��A(){ }+A(int i){ }
*/
class B
{
public:
	int a;
	B();
	B(int i);
	~B() 
	{
	}
	void m_A();
};
B::B():a(0) 
{
}
B::B(int i):a(i)
{
}
void B::m_A()
{
	cout << a << endl;
}
class C :public A
{
protected:
	int i;
public:
	C() { i = 0; }
};
int main()
{
	A i(10);
	cout << i.a<<endl;
	A j(521);
	cout << j.a <<endl;
	B* pa = new B;//һ��ͨ��new��delete�������������͹��캯����һ�㲻��malloc��free
	pa->m_A();
	delete pa;
	return 0;
}