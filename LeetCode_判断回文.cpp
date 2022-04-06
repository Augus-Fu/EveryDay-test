#include<iostream>
using namespace std;
//еп╤о╩ьнд 
bool isPalindrome(int x) 
{
    if (x < 0 || (x % 10 == 0 && x != 0)) 
	{
        return false;
    }
    int index=0;
    while(x>index)
    {
        index = index * 10 + x % 10 ;
        x/=10;
    }
    return x == index || x == index / 10;
}
int main()
{
	int i;
	cin >> i;
	cout << isPalindrome(i); 
	return 0;
 } 
