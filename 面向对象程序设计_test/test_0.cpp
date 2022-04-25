#include<iostream>
using namespace std;
/* ����������д�� */
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
    cout << c1.area() << endl;//����Բ���
    cout << c2.perimeter() << endl;//����Բ�ܳ�
    return 0;
}
