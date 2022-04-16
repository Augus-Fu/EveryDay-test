#include<iostream>
using namespace std;
#include"CP_studentteacher.h"
int main()
{
	student s;
	teacher t;
	int score;
	cin >> score;
	t.set_score(s, score);
	s.get_score();
	system("pause");
	return 0;
}