#include<iostream>      
using namespace std;
int main()
{
	for(int j=0;j<9;j++)
	{
		for(int i=0;i<j;i++)
		cout<<" "; 
		cout<<"*";
		for(int i=j;i<8;i++)
		{
		cout<<"**";
		}     
		cout<<endl;
	}
	 
	system("pause");
	return 0;
 } 
