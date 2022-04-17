#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<5;i++)
		{
			for(int k=i;k<16;k++)
			cout<<" ";
			cout<<"*";
			for(int j=16-i;j<16;j++)
			cout << "**"; 
			cout<<endl;
		}
	return 0;
} 
