/*
����Ҫ��ʵ��һ��Vector��ģ�壬��ʵ�����ݵĴ洢�ͷ��ʡ�
ͨ��[]���������ʱֻ�ܷ����Ѿ����ڵ�Ԫ�أ���ͨ��add()��������ʱ�����Զ���չ�ڲ��洢�ռ䡣
ע�⣬���Vector����Ϊ��std::vector�ǲ�ͬ��

����������100 50

���������
100
50
99
51
-1
100

*/

#include <iostream>
using namespace std;

/* ����������д�� */

template <class T>
class Vector
{
public:
    T* V;
    int size;
    Vector(int n = 0)
    {
        size = n;
        V = new T[100];
    };
    T& operator=(Vector a)
    {
        for (int i = 0; i < a.get_size(); i++)
        {
            V[i] = a[i];
            size++;
        }
    }
    T& operator[](int i)
    {
        return V[i];
    };
    T add(T n)
    {
        V[size] = n;
        size++;
        return size - 1;
    };
    int get_size()
    {
        return size;
    };
    void remove(int m)
    {
        for (int i = m; i < size - 1; i++)
        {
            V[i] = V[i + 1];
        }
        size--;
    }
};

int main()
{
    Vector<int> vint;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        //    add() can inflate the vector automatically
        vint.add(i);
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size() - 1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}
