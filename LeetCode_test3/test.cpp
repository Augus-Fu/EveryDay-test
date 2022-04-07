#include<iostream>

using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size()) return false;//���Ȳ�һ��һ������false
    int n = s.size(), m = goal.size(), j = 0;
    for (int i = 0; i < n; i++, j = 0)//���ַ���s�е��ַ�����ƥ��goal�ĵ�һ���ַ�
    {
        int index = i;//��index����i����������iֵ�仯
        while (s[index] == goal[j] && j < m)
        {
            index++; j++;
            if (index == n) index = 0;//s���һ���ַ�ƥ�����ת�����һ���ַ�����ƥ��
        }
        if (j == m) break;//j==m˵��ƥ��ɹ�������ѭ��
    }
    if (j == m) return true;//j==m˵��ƥ��ɹ�,����TRUE
    return false;
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    cout << rotateString(a, b) << endl;
    return 0;
}