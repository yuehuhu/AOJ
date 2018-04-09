#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define Lens 10005
#define Inf 1<<22

using namespace std;
vector<pair<int, int> > adj[Lens];
int N;
char c[Lens];
int d[Lens];

void dijkstra()
{
	d[0] = 0;
	priority_queue<pair<int, int> > PQ;
	PQ.push(make_pair(0, 0));
	while (!PQ.empty())
	{
		pair<int, int> t = PQ.top();
		PQ.pop();
		int u = t.second;
		c[u] = 'b';
		if (d[u] < -t.first) continue;
		for (int i = 0; i < adj[u].size(); i++)
		{
			int tmp = adj[u][i].first;
			if (c[tmp] == 'w'&&d[tmp] > d[u] + adj[u][i].second)
			{
				d[tmp] = d[u] + adj[u][i].second;
				PQ.push(make_pair(-d[tmp],tmp));
				cout << tmp << "  " << d[tmp] << endl;
			}
		}

	}
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int k, n;
		cin >> k >> n;
		c[k] = 'w';
		d[k] = Inf;
		for (int j = 0; j < n; j++)
		{
			int v, tw;
			cin >> v >> tw;
			adj[k].push_back(make_pair(v, tw));
		}

	}
	dijkstra();
	for (int i = 0; i < N; i++)
	{
		cout << i << ' ' << d[i] << endl;;
	}
	return 0;
}