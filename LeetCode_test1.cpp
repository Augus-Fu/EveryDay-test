#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isSubsequence(string s, string t) 
{
    int j, i;
    for (i = 0, j = 0; j < s.length() && i < t.length();)
    {
        if (s[j] == t[i])
        {
            i++; j++;
        }
        else if (s[j] != t[i]) i++;
    }
    if (i < t.length() || (j == s.length() && i == t.length())) return true;
    else return false;
}


/*
整数数组 citations ，其中 citations[i] 表示第 i 篇论文被引用的次数，citations 已经按照?升序排列?。
计算并返回该研究者的 h?指数
(h 指数是指他（她）的 （n 篇论文中）总共有 h 篇论文分别被引用了至少 h 次)
*/
int hIndex(vector<int>& citations)
{
    int n = citations.size(), result = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (citations[n - i - 1] >= i + 1)
        {
            result = i + 1;
            break;
        }
    }
    return result;
}


//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0, result=-1;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            result = nums[i];
            count = 1;
        }
        else
        {
            if (result == nums[i])     count++;
            else count--;
        }
    }
    return result;
}



//给定一个正整数 n ，返回范围在 [0, n] 都非负整数中，其二进制表示不包含 连续的 1 的个数。
int findIntegers(int n)
{
    vector<int> dp(31);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 31; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // pre 记录上一层的根节点值，res 记录最终路径数
    int pre = 0, res = 0;
    for (int i = 29; i >= 0; --i)
    {
        int val = 1 << i;
        // if 语句判断 当前子树是否有右子树
        if ((n & val) != 0)
        {
            // 有右子树
            n -= val;
            res += dp[i + 1]; // 先将左子树（满二叉树）的路径加到结果中
            // 处理右子树
            if (pre == 1)
            {
                // 上一层为 1，之后要处理的右子树根节点肯定也为 1
                // 此时连续两个 1，不满足题意，直接退出
                break;
            }
            // 标记当前根节点为 1
            pre = 1;
        }
        else
        {
            // 无右子树，此时不能保证左子树是否为满二叉树，所以要在下一层再继续判断
            pre = 0;
        }
        if (i == 0)
        {
            ++res;
        }
    }
    return res;
}

int main()
{
	string a="acd";
	string b="abcjkskfd";
	cout<<isSubsequence(a,b);
    /*ector<int> n = { 1, 2, 1, 2,3, 2,2 };
    int m=majorityElement(n);
    printf("%d", m);*/
    int n;
    cin >> n;
    cout << findIntegers(n);
    /*vector <int> n = {0, 0};
    int m=hIndex(n);
    cout << m;*/
    return 0;
}
