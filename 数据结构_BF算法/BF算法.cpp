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
	cout << "请输入A字符串：";
	cin >> a;
	cout << "请输入B字符串：";
	cin >> b;
	if (BF_Find(a, b) == -1) cout << "A中无完整B！";
	else	cout << "输出B在A中的起始位置: " << BF_Find(a, b) << endl;
	system("pause");
	return 0;
}