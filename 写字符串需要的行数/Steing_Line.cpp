/*
����Ҫ�Ѹ������ַ��� S
������д��ÿһ���ϣ�ÿһ�е������Ϊ100����λ
���������дĳ����ĸ��ʱ���ʹ���г�����100 ����λ����ô����Ӧ�ð������ĸд����һ�С�
���Ǹ�����һ������widths
�������widths[0] ���� 'a' ��Ҫ�ĵ�λ��widths[1] ���� 'b' ��Ҫ�ĵ�λ��...��?widths[25] ���� 'z' ��Ҫ�ĵ�λ��
���ڻش��������⣺���ٶ������ܷ���S���Լ����һ��ʹ�õĿ���Ƕ��ٸ���λ������Ĵ���Ϊ����Ϊ2�������б��ء�

widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
3 60
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> numberOfLines(vector<int>& widths, string s)
{
    int in = 0, k = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (in + widths[s[i] - 'a'] > 100)
        {
            k++;
            in = widths[s[i] - 'a'];
        }
        else  in += widths[s[i] - 'a'];
    }
    vector<int> result{ k,in };
    return result;
}
int main()
{

    vector<int> a{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
    string b = "abcdefghijklmnopqrstuvwxyz";
    vector<int> c(numberOfLines(a, b));
    vector<int>::iterator ita;
    for (ita = c.begin(); ita != c.end(); ita++)
        cout << (*ita) << " ";
    return 0;
}