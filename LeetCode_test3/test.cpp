#include<iostream>

using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size()) return false;//长度不一样一定返回false
    int n = s.size(), m = goal.size(), j = 0;
    for (int i = 0; i < n; i++, j = 0)//用字符串s中的字符挨个匹配goal的第一个字符
    {
        int index = i;//用index存下i避免后面造成i值变化
        while (s[index] == goal[j] && j < m)
        {
            index++; j++;
            if (index == n) index = 0;//s最后一个字符匹配后，跳转到其第一个字符继续匹配
        }
        if (j == m) break;//j==m说明匹配成功，跳出循环
    }
    if (j == m) return true;//j==m说明匹配成功,返回TRUE
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