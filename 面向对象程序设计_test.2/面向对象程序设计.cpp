#include <iostream>
using namespace std;

/* 请在这里填写答案 */
/*
1. 声明一个Car类;
2. 三个public成员函数:
(1) disp_welcomemsg()，无返回类型;
(2) get_wheels()，返回一个Car类的数据成员m_nWheels的值；
(3) set_wheels(int)，用指定的形参初始化数据成员m_nWheels的值；
3. 一个私有数据成员m_nWheels，整数类型，代表汽车的车轮数量。
*/
class Car
{
private:
    int m_nWhilees;
public:
    void disp_welcomemsg() { cout << "Welcome to the car world!" << endl; };
    int get_wheels() { return m_nWhilees; };
    void set_wheels(int i) { m_nWhilees = i; };
};

int main()
{
    int n;
    cin >> n;
    Car myfstcar, myseccar;    //定义类对象
    myfstcar.disp_welcomemsg();//访问成员函数，显示欢迎信息
    myfstcar.set_wheels(n);    //访问成员函数，设置车轮数量
    myseccar.set_wheels(n + 4);  //访问成员函数，设置车轮数量
    //访问成员函数，显示车轮数量
    cout << "my first car wheels num = " << myfstcar.get_wheels() << endl;
    cout << "my second car wheels num = " << myseccar.get_wheels() << endl;

    return 0;
}
