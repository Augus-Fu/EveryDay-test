#include<iostream>
#include<vector>
#include<algorithm>
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


/*ÿһλ�ϵ����ֶ���ǰһλ�ϵ����ִ� 1 ��������
���㷵����[low, high] ��Χ������˳������ɵ� ���� �б���С��������*/
vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    for (int i = 1; i <= 9; ++i)
    {
        int num = i;
        for (int j = i + 1; j <= 9; ++j)
        {
            num = num * 10 + j;
            if (num >= low && num <= high)
            {
                ans.push_back(num);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/*��λ���𿪺���ϳ���������
����������к���С������*/
int minimumSum(int num) {
    int digits[4];
    for (int i = 0; i < 4; i++)
    {
        digits[i] = num % 10;
        num /= 10;
    }
    for (int m = 0; m < 4; m++)
    {
        for (int j = m + 1; j < 4; j++)
        {
            if (digits[m] > digits[j])
            {
                int index = digits[j];
                digits[j] = digits[m];
                digits[m] = index;
            }
        }
    }
    return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
}

int main()
{
	int i;
	cin >> i; 
    cout << minimumSum(i);
    /*vector<int> n = { 1, 2, 1, 2,3, 2,2 };
    int m=majorityElement(n);
    printf("%d", m);*/
    /*int n;
    cin >> n;
    cout << findIntegers(n);*/
    /*vector <int> n = {0, 0};
    int m=hIndex(n);
    cout << m;*/
    return 0;
} 
