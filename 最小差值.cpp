#include<iostream>
#include<vector>
/*
ʾ�� 1�� 
���룺nums = [1], k = 0
�����0
���ͣ������� max(nums) - min(nums) = 1 - 1 = 0��
ʾ�� 2��
���룺nums = [0,10], k = 2
�����6
���ͣ��� nums ��Ϊ [2,8]�������� max(nums) - min(nums) = 8 - 2 = 6��
ʾ�� 3��
���룺nums = [1,3,6], k = 3
�����0
���ͣ��� nums ��Ϊ [4,4,4]�������� max(nums) - min(nums) = 4 - 4 = 0��
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
	cout<<"����һ���������� nums����һ������ k "<<endl;
	cout<<"��һ�������У�������ѡ�� 0 <= i < nums.length ���κ����� i"<<endl;
	cout<<"�� nums[i] ��Ϊ nums[i] + k ������ k ��һ����ΧΪ [-k, k] ������"<<endl;
	cout<<"����ÿ������ i ����� ֻ�� Ӧ�� һ�� �˲���"<<endl;
	cout<<"nums�ķ�����nums��������СԪ�صĲ�ֵ"<<endl;
	cout<<"�ڶ� nums �е�ÿ���������Ӧ��һ�����������󣬷���nums ����� ����"<<endl<<endl<<endl;
	cout<<"ʾ�� 1��"<<endl<<"���룺nums = [1], k = 0"<<endl<<"�����0   "<<endl<<"���ͣ������� max(nums) - min(nums) = 1 - 1 = 0"<<endl<<endl;
	cout<<"ʾ�� 2��"<<endl<<"���룺nums = [0,10], k = 2"<<endl<<"�����6   "<<endl<<"���ͣ��� nums ��Ϊ [2,8]�������� max(nums) - min(nums) = 8 - 2 = 6"<<endl<<endl;
	cout<<"ʾ�� 3��"<<endl<<"���룺nums = [1,3,6], k = 3"<<endl<<"�����0   "<<endl<<"���ͣ��� nums ��Ϊ [4,4,4]�������� max(nums) - min(nums) = 4 - 4 = 0 "<<endl<<endl<<endl;
	int index;
	cout<<"����������nums��Ԫ�ظ�����";
	cin >>index;
	int nums[index];
	vector<int> a;
	for(int i=0;i<index;i++)
	{
		cout<<"����������nums�ĵ�"<<i+1<<"��Ԫ�أ�";
		cin>>nums[i];
		a.push_back(nums[i]);
	 } 
	int k;
	cout<<"������kֵ��";
	cin>>k; 
	cout<<smallestRangeI(a,k)<<endl;
	system("pause");
	return 0;
}
