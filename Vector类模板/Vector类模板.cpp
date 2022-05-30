/*
本题要求实现一个Vector类模板，能实现数据的存储和访问。
通过[]运算符访问时只能访问已经存在的元素，而通过add()方法访问时可以自动扩展内部存储空间。
注意，这个Vector的行为和std::vector是不同的

输入样例：100 50

输出样例；
100
50
99
51
-1
100

*/

#include <iostream>
using namespace std;

/* 请在这里填写答案 */

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
