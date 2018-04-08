//emmmmmm,这个超时了！！！
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define Lens 100005

using namespace std;
int n, m, q;
vector<int> A[Lens];

char c[Lens], d[Lens];

int Find(queue<int> Q,int s, int t)
{
	Q.push(s);
	c[s] = 'g';
	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();
		c[s] = 'g';
		for (int j = 0; j < A[s].size(); j++)
		{
			if (c[A[s][j]] == 'w')
				Q.push(A[s][j]);
			if (A[s][j] == t)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		d[s] = d[t] = 'w';
		A[s].push_back(t);
		A[t].push_back(s);
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		queue<int>	Q;
		for (int j = 0; j < n; j++)
			c[j] = d[j];
		int s, t;
		cin >> s >> t;
		if (Find(Q,s, t))
			cout << "yes" << endl;

		else
			cout << "no" << endl;
	}
	return 0;
}