/*
LeetCode.357(�е�)
����һ������ n ��ͳ�Ʋ����ظ�λ���ֶ���ͬ������ x �ĸ���
����������n=2 result=91;n=0 result=1;n=5 result=
*/
#include<iostream>
using namespace std;
int INDEX(int n)
{
    int result = 9, index = 9;//result��ֵΪ9��Ϊ���λ����ȡ0��ֻ����0~9�е�һ����
    while (n-- != 1)
    {
        result *= index--;
    }
    return result;
}
int DIGIT(int n)//��nλ���Ľ��
{
    if (n == 1) return 10;//n=1ʱ����10���������������
    int result = INDEX(n) + DIGIT(n - 1);//�ݹ�
    return result;
}
int countNumbersWithUniqueDigits(int n)
{
    if (n > 9) return 0;//����9λ�����ض�����������
    if (n == 0) return 1;
    return DIGIT(n);//���ú���DIGIT
}
/*�򻯰���⣺
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