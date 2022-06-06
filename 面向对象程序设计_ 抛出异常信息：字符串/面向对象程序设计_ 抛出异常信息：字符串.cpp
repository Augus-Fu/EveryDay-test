/*
����Ҫ��ʵ��һ��������֪�����߱߳����ɼ��������ε����
��������������߲��ܹ���һ�����������׳��쳣��Ϣ��Not is triangle!��
ͳ����һ������ĳ��λ�����ֵĴ�����
������ʾ�����ε������ȡ������ʾ��

����ʾ��һ��3 4 5
���ʾ��һ��area=6

����ʾ������1 1 3
���ʾ������Not is triangle!

*/
#include <iostream>
#include <cmath>
using namespace std;
int triangle(double a, double b, double c);
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    try
    {
        int s = (int)triangle(a, b, c);
        cout << "area=" << s << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    return 0;
}

/* ����������д�� */
int triangle(double a, double b, double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)  throw "Not is triangle!";
    double p;
    p = (a + b + c)/2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
