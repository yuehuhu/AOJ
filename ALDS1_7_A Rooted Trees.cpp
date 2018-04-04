#include<iostream>
#include<cstdio>
#include<algorithm>
#define Nil -1
#define Lens 1000000

using namespace std;

struct Node
{
	int p, l, r;
};
int N;
Node Tr[Lens];
int D[Lens];
int v, d;

void maketree()
{
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> v >> d;
		int tmpv = v;
		int next;
		for (int i = 0; i < d; i++)
		{
			cin >> tmp;
			
			if (i == 0)
			{
				Tr[v].l = tmp;
				Tr[tmp].p = v;
				next = tmp;
			}
			else
			{
				
				Tr[next].r = tmp;
				Tr[tmp].p = tmpv;
				next = tmp;
			}
		}
	}
}

void dns(int i, int p)
{
	D[i] = p;
	if (Tr[i].r != Nil) dns(Tr[i].r, p);
	if (Tr[i].l != Nil) dns(Tr[i].l, p + 1);
	
	
}

void printtree()
{
	int tmp = -1;
	int r;
	for (int i = 0; i < N; i++)
	{
		if (Tr[i].p == Nil)
			r = i;
	}
	dns(r, 0);
	for (int i = 0; i < N; i++)
	{
		cout << "node " << i << ": parent = " << Tr[i].p << ", " << "depth = " << D[i] << ", ";
		if (Tr[i].p == Nil)
		{
			cout << "root, [";
			if (Tr[i].l != Nil)
			{
				int next = Tr[i].l;
				cout << Tr[i].l;
				while (Tr[next].r != Nil)
				{
					cout << ", " << Tr[next].r;
					next = Tr[next].r;
				}
			}
			cout << "]";
		}
		else if (Tr[i].p != Nil&&Tr[i].l != Nil)
		{
			cout << "internal node, [";
			cout << Tr[i].l;
			int next = Tr[i].l;
			while (Tr[next].r != Nil)
			{
				cout << ", " << Tr[next].r;
				next = Tr[next].r;
			}
			cout << "]";
		}
		else
		{
			cout << "leaf, []";
		}


		cout << endl;
	}
}



int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Tr[i].l = Tr[i].r = Tr[i].p = Nil;
	}

	maketree();


	printtree();
	return 0;
}