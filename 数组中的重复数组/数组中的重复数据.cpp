/*
* LeetCode  442  数组中的重复数据
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
请你找出所有出现 两次 的整数，并以数组形式返回。
你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
*/
/*
当遍历到位置 i 时，看 nums[i] 和 nums[i]−1，是否相同;
如果相同这开始从下一个数字开始比较;
如果不同则应该把 nums[i]−1 放在对应的位置上，因此我们交换 num[i] 和 nums[nums[i]−1] 即可，直到待交换的两个元素相等为止;
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (nums[i] - 1 != i) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int> a{ 1,3,5,2,2,1 };
    a=findDuplicates(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
	system("pause");
	return 0;
}