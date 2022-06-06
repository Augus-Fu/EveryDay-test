/*
本题要求实现一个函数，可以求出一次方程和二次方程的实数根
若不满足求根的条件则抛出相应的异常并显示。

在这里描述函数接口：
void root(double a,double b,double c,double& x1,double& x2);
在这里解释接口参数。其中a，b，c都是用户传入的参数
a为二次项系数，b为一次项系数，c为常数项
x1，x2 为欲求的实数根：​

示例一:
输入：0 0 1
输出：Not a equation!
示例二：
输入：3 3 4
输出：No real root!
示例三：
输入：1 0 -4
输出：root:x1=2,x2=-2
*/

#include<iostream>
#include<cmath>
using namespace std;
void root(double a, double b, double c, double& x1, double& x2);

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double x1, x2;
    try
    {
        root(a, b, c, x1, x2);
        cout << "root:x1=" << x1 << ",x2=" << x2 << endl;
    }
    catch (int)
    {
        cout << "Not a equation!" << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    catch (...)
    {
        cout << "Other Error!";
    }
    return 0;
}
/* 请在这里填写答案 */
void root(double a, double b, double c, double& x1, double& x2)
{
    double index = pow(b, 2);
    if ((index - 4 * a * c) < 0)  throw "No real root!";
    double ans = sqrt(index - 4 * a * c);
    if (a == 0 && b == 0) throw 0;
    x1 = (ans - b) / (2 * a);
    x2 = (0 - ans - b) / (2 * a);
}
