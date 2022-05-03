/*
给你一个长度为n的整数数组每次操作将会使n-1个元素增加1
返回让数组所有元素相等的最小操作次数

思路：
每次操作既可以理解为使n−1个元素增加1也可以理解使1个元素减少1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMoves(vector<int>& nums) 
{
    int result = 0;
    int min = *min_element(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        result += (nums[i] - min);
    return result;
}
int main()
{
    vector<int> nums{1,5,3};
    cout << minMoves(nums);
	system("pause");
	return 0;
}