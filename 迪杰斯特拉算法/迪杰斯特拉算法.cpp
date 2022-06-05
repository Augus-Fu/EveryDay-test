#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAX 100
int path[MAX];//ǰ��
int D[MAX];//shortestȨֵ
bool S[MAX];//�ж��Ƿ���ʹ��
void shortestpath_GIJ(vector<vector<int>> G, int V0)
{
	for (int i = 0; i < G.size(); i++)
	{
		S[i] = false;
		D[i] = G[V0][i];
		if (D[i] < MAX) path[i] = V0;
		else path[i] = -1;
	}
	S[V0] = true;
	D[V0] = 0;
	path[V0] = -1;
	int w,v = V0;

	for (int i = 1; i < G.size(); i++)
	{
		int min = MAX;
		for (w = 0; w < G.size(); w++)
		{
			if (!S[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		S[v] = true;
		for (w = 0; w < G.size(); w++)
		{
			if (!S[w] && (D[w] > D[v] + G[v][w]))
			{
				D[w] = D[v] + G[v][w];
				path[w] = v;
			}
		}
	}
}
int main()
{
	cout << "�������ĸ�����";
	int n,k;
	cin >> n;
	vector<int> T;
	vector<vector<int>> G;
	cout << "�������ڽӾ���" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> k;
			T.push_back(k);
		}
		G.push_back(T);
		T.clear();
	}
	shortestpath_GIJ(G, 0);
	for (int i = 1; i < n; i++)
	{
		cout << "V[0]��V[" << i << "]�����·��Ϊ��";
		int index = i;
		stack<int> X;
 		while(path[index] != -1)
		{
			X.push(index);
			index = path[index];
		}
		cout << "VO";
		while (!X.empty())
		{
			cout << "->V" << X.top();
			X.pop();
		}
		cout << "      MINlength=" << D[i];
		cout << endl;
	}
	system("pause");
	return 0;
}
/*
0   3    99  4   2   99  99  99  99   99
3   0    2   99  99  1   4   99  99   99
99  2    0   3   99  7   99  4   99   99
4   99   3   0   6   99  99  99  99   99
2   99   99  6   0   5   2   99  99   99
99  1    7   99  5   0   99  99  4    2
99  4    99  99  2   99  0   6   9    99
99  99   4   99  99  99  6   0   99   3
99  99   99  99  99  4   9   99  0    5
99  99   99  99  99  2   99  3   5    0*/