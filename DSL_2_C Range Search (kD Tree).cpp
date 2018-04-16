#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define Lens 1000100
#define Nil -1

using namespace std;

struct point
{
	int x;
	int y;
	int add;
};

struct node
{
	int lc;
	int rc;
	int key;
};

int N, q, h;
point p[Lens];
node T[Lens];
vector<int> ans;
bool lessx(point a, point b) { return a.x < b.x; }
bool lessy(point a, point b) { return a.y < b.y; }

int maketree(int l, int r, int depth)
{
	if (l >= r)
		return Nil;
	int mid = (l + r) / 2;
	if (depth % 2 == 0)
		sort(p + l, p + r, lessx);
	else
		sort(p + l, p + r, lessy);
	int t = h++;
	T[t].key = mid;
	T[t].lc = maketree(l, mid, depth + 1);
	T[t].rc = maketree(mid + 1, r, depth + 1);
	return t;

}

void findtree(int root, int lx, int hx, int ly, int ry, int depth)
{
	int tr = root;
	int tx = p[T[tr].key].x;
	int ty = p[T[tr].key].y;
	if (lx <= tx&&tx <= hx&&ly <= ty&&ty <= ry)
		ans.push_back(p[T[tr].key].add);
	if (depth % 2 == 0)
	{
		if (T[tr].lc != Nil&&lx <= tx)
			findtree(T[tr].lc, lx, hx, ly, ry, depth + 1);
		if (T[tr].rc != Nil&&tx <= hx)
			findtree(T[tr].rc, lx, hx, ly, ry, depth + 1);
	}
	else
	{
		if (T[tr].lc != Nil&&ly <= ty)
			findtree(T[tr].lc, lx, hx, ly, ry, depth + 1);
		if (T[tr].rc != Nil&&ty <= ry)
			findtree(T[tr].rc, lx, hx, ly, ry, depth + 1);
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &p[i].x ,&p[i].y);
		p[i].add = i;
		T[i].lc = T[i].rc = T[i].key = Nil;

	}
	int root = maketree(0, N, 0);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		ans.clear();
		int lx, hx, ly, ry;
		scanf("%d %d %d %d", &lx, &hx,&ly,&ry);

		findtree(root, lx, hx, ly, ry, 0);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			printf("%d\n", ans[i]); 
		printf("\n");
	}
	return 0;
}