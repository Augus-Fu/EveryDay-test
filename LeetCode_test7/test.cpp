/*
������Сд��ĸ��ɵ��ַ���?S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��

���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��
֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��
*/
#include<iostream>
using namespace std;
string removeDuplicates(string s) {
    string stk;
    for (char ch : s)
    {
        if (!stk.empty() && stk.back() == ch)
            stk.pop_back();
        else    stk.push_back(ch);
    }
    return stk;
}
int main()
{
    string a;
    cout << "������a��";
    cin >> a;
    a=removeDuplicates(a);
    cout << endl << a;
	system("pause");
	return 0;
}