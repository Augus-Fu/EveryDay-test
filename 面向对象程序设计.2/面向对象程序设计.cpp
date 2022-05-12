#include<iostream>
using namespace std;
template<class T>
T add(T a, T b)
{
	return a + b;
}
int main()
{
	double a=1.000, b=4.200;
	float c=2.320, d=2.880 ;
	int e=27, f=25;
	cout << add(a, b) << endl<<add(c, d) << endl<<add(e, f)<<endl;
	system("pause");
	return 0;
}