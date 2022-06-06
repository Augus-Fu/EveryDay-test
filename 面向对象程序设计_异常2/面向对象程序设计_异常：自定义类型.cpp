/*
本题重点在于抛出异常的类型
异常既可以抛出内置类型的数据，也可以抛出自定义的类型
设计一个关于栈的简单类，并且添加异常处理，判断栈空和栈溢出，在主程序中对其进行测试。


输入示例一：1 2 3 0
在这里给出相应的输出，首先栈内元素出栈；若继续出栈，抛出异常”栈空“：
输出示例一：321stack is empty!

输入示例二：1 2 3 4 5 6 7 8 9 10 11
在这里给出相应的输出，因元素超出栈的容量，抛出异常，并显示栈满“：
输出示例二：Exception: Stack Full...
The value not push in stack: 11
*/

#include<iostream>
const int SIZE = 10;
using namespace std;
class Full
{
private:
    int a;
public:
    Full(int i);
    int getValue();
};

class Empty
{
public:
    void show();
};

class Stack
{
private:
    int stack[SIZE];
    int tos;//长度
public:
    Stack();
    void push(int a);
    int pop();
    int top()const;
};

int main()
{
    Stack s;
    int b[20], i = 0;
    try
    {
        cin >> b[i];
        while (b[i])
        {
            s.push(b[i]);
            ++i;
            cin >> b[i];
        }
        for (i = 0; i < SIZE; i++)
            cout << s.pop();
    }
    catch (Full e)
    {
        cout << "Exception: Stack Full..." << endl;
        cout << "The value not push in stack: " << e.getValue() << endl;
    }
    catch (Empty e)
    {
        e.show();
    }
    return 0;
}


/* 请在这里填写答案 */
Full::Full(int i)
{
    a = i;
}
int Full::getValue()
{
    return a;
}
void Empty::show()
{
    cout << "stack is empty!";
}
Stack::Stack()
{

    tos = 0;
}
void Stack::push(int a)
{
    Full e(a);
    if (tos == SIZE) throw e;
    stack[tos++] = a;
}
int Stack::pop()
{
    Empty e;
    if (top() == 0) throw e;
    else return stack[--tos];
}
int Stack::top()const
{
    return tos;
}