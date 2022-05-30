/*
���������ÿһ����������С��������������
һ������Ϊһ��������һ������Ϊ��������
��1��ʾ������2��ʾ�ַ�������3��ʾ��һλС���ĸ�������4��ʾ�ַ�����0��ʾ���������
�ڶ�������Ϊ������������size��0<size<=10����������Ϊsize��ָ�����͵����ݡ�
�������С����˳��������ݡ�
�����ӿڶ��壺sort����������size�����ݣ������Ǵ�С������������aָ���һ�������ռ��С�


����������
1 3 3 2 1
2 2 a A
3 3 1.5 2.6 2.2
4 2 bca abc
0

���������
1 2 3
A a
1.5 2.2 2.6
abc bca


*/


#include <iostream>
#include <string>
using namespace std;

/* ����������д�� */
template <class T>
void sort(T* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    for (int k = 0; k < size; k++)
    {
        for (int i = 1; i < size - k; i++)
        {
            if (a[i - 1] > a[i])
            {
                T c = a[i];
                a[i] = a[i - 1];
                a[i - 1] = c;
            }
        }
    }
}
template <class T>
void display(T* a, int size) {
    for (int i = 0; i < size - 1; i++) cout << a[i] << ' ';
    cout << a[size - 1] << endl;
}
int main() {
    const int SIZE = 10;
    int a[SIZE];
    char b[SIZE];
    double c[SIZE];
    string d[SIZE];
    int ty, size;
    cin >> ty;
    while (ty > 0) {
        cin >> size;
        switch (ty) {
        case 1:sort(a, size); display(a, size); cout << endl; break;
        case 2:sort(b, size); display(b, size); cout << endl; break;
        case 3:sort(c, size); display(c, size); cout << endl; break;
        case 4:sort(d, size); display(d, size); cout << endl; break;
        }
        cin >> ty;
    }
    return 0;
}
