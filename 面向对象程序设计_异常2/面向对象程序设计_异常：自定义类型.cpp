/*
�����ص������׳��쳣������
�쳣�ȿ����׳��������͵����ݣ�Ҳ�����׳��Զ��������
���һ������ջ�ļ��࣬��������쳣�����ж�ջ�պ�ջ��������������ж�����в��ԡ�


����ʾ��һ��1 2 3 0
�����������Ӧ�����������ջ��Ԫ�س�ջ����������ջ���׳��쳣��ջ�ա���
���ʾ��һ��321stack is empty!

����ʾ������1 2 3 4 5 6 7 8 9 10 11
�����������Ӧ���������Ԫ�س���ջ���������׳��쳣������ʾջ������
���ʾ������Exception: Stack Full...
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
    int tos;//����
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


/* ����������д�� */
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