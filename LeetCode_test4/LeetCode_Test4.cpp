/*
LeetCode.357(中等)
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数
测试用例：n=2 result=91;n=0 result=1;n=5 result=32491
*/
#include<iostream>
using namespace std;
int INDEX(int n)
{
    int result = 9, index = 9;//result初值为9因为最高位不能取0，只能是0~9中的一个数
    while (n-- != 1)
    {
        result *= index--;
    }
    return result;
}
int DIGIT(int n)//求n位数的结果
{
    if (n == 1) return 10;//n=1时返回10（单个数字情况）
    int result = INDEX(n) + DIGIT(n - 1);//递归
    return result;
}
int countNumbersWithUniqueDigits(int n)
{
    if (n > 9) return 0;//超过9位数，必定不满足题意
    if (n == 0) return 1;
    return DIGIT(n);//调用函数DIGIT
}
/*简化版题解：
int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int result = 10, index = 9;
        for (int i = 0; i < n - 1; i++)
        {
            index *= 9 - i;
            result+= index;
        }
        return result;
    }
*/
int main()
{
    int index;
    cin >> index;
    cout << countNumbersWithUniqueDigits(index) << endl;
	system("pause");
	return 0;
}
