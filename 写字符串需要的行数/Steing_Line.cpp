/*
我们要把给定的字符串 S
从左到右写到每一行上，每一行的最大宽度为100个单位
如果我们在写某个字母的时候会使这行超过了100 个单位，那么我们应该把这个字母写到下一行。
我们给定了一个数组widths
这个数组widths[0] 代表 'a' 需要的单位，widths[1] 代表 'b' 需要的单位，...，?widths[25] 代表 'z' 需要的单位。
现在回答两个问题：至少多少行能放下S，以及最后一行使用的宽度是多少个单位？将你的答案作为长度为2的整数列表返回。

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