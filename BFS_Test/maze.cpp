#include<iostream>
#include<queue>
using namespace std;

/*
5 4//迷宫大小
1 1 2 1
1 1 1 1 
1 1 2 1
1 2 1 1
1 1 1 2

0 0//起点坐标
3 2//终点坐标

5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
0 0
3 2
*/
struct point
{
	int x;
	int y;
	int step;
};
int a[100][100], v[100][100];
int dx[4] = { 0,1,0,-1 };//右下左上
int dy[4] = { 1,0,-1,0 };
queue<point> r;
int main()
{
	int n, m, startx, starty, goalx,goaly;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	cin >> startx >> starty >> goalx >> goaly;
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	r.push(start);
	v[startx][starty] = 1;
	while (!r.empty())
	{
		int x = r.front().x, y = r.front().y;
		if (x == goalx && y == goaly)
		{
			cout << r.front().step;
			break;
		}
		for (int k = 0; k < 4; k++)
		{
			int tx=x+dx[k], ty=y+dy[k];
			if (tx < 0 || ty < 0)  continue;
			if (a[tx][ty] == 1 && v[tx][ty] == 0)
			{
				point stmp;
				stmp.x = tx;
				stmp.y = ty;
				stmp.step = r.front().step + 1;
				v[tx][ty] = 1;
				r.push(stmp);
			}
		}
		r.pop();
	}
	return 0;
}