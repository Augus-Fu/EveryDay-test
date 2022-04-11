#include<iostream>
using namespace std;
int add(int a, int b) //不用加减乘数完成加法运算 
{
    while(b)
    {
        int index=a & b;//按位与运算，相同位都是1时为1，求进位 
        a=a^b;//按位异或，相同为0，不同为1
        b=(unsigned)index<<1;//左移运算 
    }
    return a;
}
int main()
{
	int a,b;
	cin >> a >>b; 
	cout <<add(a,b)<<endl; 
	return 0;
 } 
