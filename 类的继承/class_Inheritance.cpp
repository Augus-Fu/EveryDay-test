#include<iostream>
using namespace std;

class A
{
public:
	int a;
	//A() { a = 0; };//与下面构造方法一致效果
	A() :a(0) { }
	/*
	A(int i)
	{
		a = i;
	}//与下面构造方法一致效果
	*/
	A(int i) :a(i) { }
	~A() { }
};
/*
构造函数中：A(){  }与A(int i=0){  }不能同时出现
A( int i=0){}相当于A(){ }+A(int i){ }
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
	B* pa = new B;//一般通过new和delete调用析构函数和构造函数；一般不用malloc和free
	pa->m_A();
	delete pa;
	return 0;
}