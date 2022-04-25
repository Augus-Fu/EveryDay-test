#include<iostream>
#include<math.h>
using namespace std;
/*
创建一个表示点的类Point，运用组合的方式创建圆形类。
圆形有个成员函数isPointIn用于判断一个点是否在该圆形的内部。
完成对应类代码，使得主函数可以正确运行。
注意类的数值型数据成员类型为浮点型。
*/
/* 请在这里填写答案 */
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