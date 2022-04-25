#include<iostream>
using namespace std;
/* 请在这里填写答案 */
class Circle
{
public:
    float R;
    Circle(float r)
    {
        R = r;
        cout << "Constructor called" << endl;
    };
    Circle(Circle& a)
    {
        R = a.R;
        cout << "Copy constructor called" << endl;
    };
    ~Circle() { cout << "Destructor called" << endl; };
    float area() { return R * R * 3.14; };
    float perimeter() { return R * 2 * 3.14; };
};
int main()
{
    float r;
    cin >> r;
    Circle c1(r);
    Circle c2(c1);
    cout << c1.area() << endl;//计算圆面积
    cout << c2.perimeter() << endl;//计算圆周长
    return 0;
}
