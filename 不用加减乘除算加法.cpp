#include<iostream>
using namespace std;
int add(int a, int b) //���üӼ�������ɼӷ����� 
{
    while(b)
    {
        int index=a & b;//��λ�����㣬��ͬλ����1ʱΪ1�����λ 
        a=a^b;//��λ�����ͬΪ0����ͬΪ1
        b=(unsigned)index<<1;//�������� 
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
