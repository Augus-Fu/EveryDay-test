/*
给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。
你需要 重排 nums 中的元素，使修改后的数组满足下述条件：
任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int x = 0, y = 1;
    for (auto& index : nums)
    {
        if (index > 0)
        {
            result[x] = index; x += 2;
        }
        else { result[y] = index; y += 2; }
    }
    return result;
}
int main()
{
    vector<int> index{ 3,-5,-2,1,2,-4 };
    vector<int> result(rearrangeArray(index));
    vector<int>::iterator it;//迭代器
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << (*it)<<" ";
    }
	return 0;
}