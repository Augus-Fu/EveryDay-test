#include<iostream>
#include<math.h>
using namespace std;
/*
����һ����ʾ�����Point��������ϵķ�ʽ����Բ���ࡣ
Բ���и���Ա����isPointIn�����ж�һ�����Ƿ��ڸ�Բ�ε��ڲ���
��ɶ�Ӧ����룬ʹ��������������ȷ���С�
ע�������ֵ�����ݳ�Ա����Ϊ�����͡�
*/
/* ����������д�� */
class Point
{
public:
    double x;
    double y;
    Point() { x = 0; y = 0; };
    Point(double i, double j) { x = i; y = j; };
};
class Circle
{
public:
    Point* star;
    double R;
    Circle(Point s, double r) 
    { 
        Point* p = &s;
        star = p; R = r; };
    bool isPointIn(Point p)
    {
        Point* s = &p;
        double R0 = pow((star->x) - (s->x),2) +pow((star->y) - (s->y),2);
        return   R0 < pow(R,2);
    };
};
int main(int argc, char const* argv[])
{
    double x, y;
    double r;
    cin >> x >> y >> r;
    Point p(x, y);
    Circle c(p, r);
    cin >> x >> y;
    Point p1(x, y);
    bool b = c.isPointIn(p1);
    cout << b << endl;
    return 0;
}