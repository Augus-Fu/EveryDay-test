#include<iostream>
#include<vector>
/*
示例 1： 
输入：nums = [1], k = 0
输出：0
解释：分数是 max(nums) - min(nums) = 1 - 1 = 0。
示例 2：
输入：nums = [0,10], k = 2
输出：6
解释：将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
示例 3：
输入：nums = [1,3,6], k = 3
输出：0
解释：将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
*/ 
using namespace std; 
int smallestRangeI(vector<int>& nums, int k) 
{
    int max=nums[0],min=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(max<nums[i]) max=nums[i];
        if(min>nums[i]) min=nums[i];
    }
    if(max-min<=2*k) return 0;
    return max-min-2*k;
}
int main()
{
	cout<<"给你一个整数数组 nums，和一个整数 k "<<endl;
	cout<<"在一个操作中，您可以选择 0 <= i < nums.length 的任何索引 i"<<endl;
	cout<<"将 nums[i] 改为 nums[i] + k ，其中 k 是一个范围为 [-k, k] 的整数"<<endl;
	cout<<"对于每个索引 i ，最多 只能 应用 一次 此操作"<<endl;
	cout<<"nums的分数是nums中最大和最小元素的差值"<<endl;
	cout<<"在对 nums 中的每个索引最多应用一次上述操作后，返回nums 的最低 分数"<<endl<<endl<<endl;
	cout<<"示例 1："<<endl<<"输入：nums = [1], k = 0"<<endl<<"输出：0   "<<endl<<"解释：分数是 max(nums) - min(nums) = 1 - 1 = 0"<<endl<<endl;
	cout<<"示例 2："<<endl<<"输入：nums = [0,10], k = 2"<<endl<<"输出：6   "<<endl<<"解释：将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6"<<endl<<endl;
	cout<<"示例 3："<<endl<<"输入：nums = [1,3,6], k = 3"<<endl<<"输出：0   "<<endl<<"解释：将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0 "<<endl<<endl<<endl;
	int index;
	cout<<"请输入数组nums的元素个数：";
	cin >>index;
	int nums[index];
	vector<int> a;
	for(int i=0;i<index;i++)
	{
		cout<<"请输入数组nums的第"<<i+1<<"个元素：";
		cin>>nums[i];
		a.push_back(nums[i]);
	 } 
	int k;
	cout<<"请输入k值：";
	cin>>k; 
	cout<<smallestRangeI(a,k)<<endl;
	system("pause");
	return 0;
}
