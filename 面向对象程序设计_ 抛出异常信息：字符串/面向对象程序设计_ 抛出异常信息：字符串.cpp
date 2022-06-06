/*
本题要求实现一个函数，知道三边边长，可计算三角形的面积
如果给出的三条边不能构成一个三角形则抛出异常信息“Not is triangle!”
统计任一整数中某个位数出现的次数。
否则显示三角形的面积（取整后显示）

输入示例一：3 4 5
输出示例一：area=6

输入示例二：1 1 3
输出示例二：Not is triangle!

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

/* 请在这里填写答案 */
int triangle(double a, double b, double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)  throw "Not is triangle!";
    double p;
    p = (a + b + c)/2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
