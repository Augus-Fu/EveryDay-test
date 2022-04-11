/*
*把符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在下标 i（0 < i < arr.length - 1），满足
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给出一个整数数组 arr，返回最长山脉子数组的长度。如果不存在山脉子数组，返回 0 
*/
#include<iostream>
#include<vector>
using namespace std;
int longestMountain(vector<int>& arr)
{
    if (arr.size() <= 2)
    {
        return 0;
    }
    int Fresult = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            int j = i, k = i, left = 1, right = 1;
            while (j > 0 && arr[j] > arr[j - 1])
            {
                j--;
                left++;
            }
            while (k < arr.size() - 1 && arr[k] > arr[k + 1])
            {
                k++;
                right++;
            }
            Fresult = max(Fresult, (right + left - 1));
        }
    }
    return Fresult;
}
int main()
{
int b[11] = { 0,1,2,3,4,5,4,3,2,1,0 };
vector<int> a(b, b + 11);
int result= longestMountain(a);
cout << result << endl;
system("pause");
return 0;
}
