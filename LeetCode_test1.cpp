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
�������� citations ������ citations[i] ��ʾ�� i ƪ���ı����õĴ�����citations �Ѿ�����?��������?��
���㲢���ظ��о��ߵ� h?ָ��
(h ָ����ָ���������� ��n ƪ�����У��ܹ��� h ƪ���ķֱ����������� h ��)
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


//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ��������
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



//����һ�������� n �����ط�Χ�� [0, n] ���Ǹ������У�������Ʊ�ʾ������ ������ 1 �ĸ�����
int findIntegers(int n)
{
    vector<int> dp(31);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 31; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // pre ��¼��һ��ĸ��ڵ�ֵ��res ��¼����·����
    int pre = 0, res = 0;
    for (int i = 29; i >= 0; --i)
    {
        int val = 1 << i;
        // if ����ж� ��ǰ�����Ƿ���������
        if ((n & val) != 0)
        {
            // ��������
            n -= val;
            res += dp[i + 1]; // �Ƚ���������������������·���ӵ������
            // ����������
            if (pre == 1)
            {
                // ��һ��Ϊ 1��֮��Ҫ��������������ڵ�϶�ҲΪ 1
                // ��ʱ�������� 1�����������⣬ֱ���˳�
                break;
            }
            // ��ǵ�ǰ���ڵ�Ϊ 1
            pre = 1;
        }
        else
        {
            // ������������ʱ���ܱ�֤�������Ƿ�Ϊ��������������Ҫ����һ���ټ����ж�
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
