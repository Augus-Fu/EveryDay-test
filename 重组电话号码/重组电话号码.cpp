#include<iostream>
using namespace std;
string reformatNumber(string number)
{
    string ans, result;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] >= '0' && number[i] <= '9') ans += number[i];
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.size() == 4)
        {
            result += ans[i++];
            result += ans[i++];
            result += '-';
            result += ans[i++];
            result += ans[i++];
            return result;
        }
        if (i != 0 && i % 3 == 0)
        {
            result += '-';
            if (i == ans.size() - 4)
            {
                result += ans[i++];
                result += ans[i++];
                result += '-';
                result += ans[i++];
                result += ans[i++];
                return result;
            }
        }
        result += ans[i];
    }
    return result;
}
int main()
{
    string a = "1-2-3-4";
    cout << reformatNumber(a);
    system("pause");
    return 0;
}