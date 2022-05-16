#include<iostream>
#include<string>
using namespace std;
int BF_Find(string a, string b)
{
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] == b[j]) { i++; j++; }
		else { i = i - j + 1; j = 0; }
	}
	if (j >= b.size()) return i - j + 1;
	return -1;
}
int main()
{
	string a, b;
	cout << "������A�ַ�����";
	cin >> a;
	cout << "������B�ַ�����";
	cin >> b;
	if (BF_Find(a, b) == -1) cout << "A��������B��";
	else	cout << "���B��A�е���ʼλ��: " << BF_Find(a, b) << endl;
	system("pause");
	return 0;
}