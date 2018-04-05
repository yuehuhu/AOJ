#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>

#define Lens 250
#define Nil -1

using namespace std;

struct Node
{
	int p, l, r;
};

int N;
Node Tr[Lens];
int D[Lens], C[Lens], H[Lens];
bool V[Lens];

//½¨Ê÷
void maketree()
{
	int m, l, r;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> l >> r;
		Tr[m].l = l;
		Tr[l].p = m;
		Tr[m].r = r;
		Tr[r].p = m;
	}
}

//Éî¶È
void dns(int i, int p)
{
	D[i] = p;
	if (Tr[i].l != Nil)
	{
		C[i]++;
		dns(Tr[i].l, p + 1);
	}
	if (Tr[i].r != Nil)
	{
		C[i]++;
		dns(Tr[i].r, p + 1);
	}
}

int hns(int i)
{
	int h1 = 0, h2 = 0;
	if (Tr[i].l != Nil)
		h1 = hns(Tr[i].l)+1;
	if (Tr[i].r != Nil)
		h2 = hns(Tr[i].r)+ 1;
	H[i] = max(h1, h2);
	return H[i];
}

void printtree()
{
	int root;
	for (int i = 0; i < N; i++)
	{
		if (Tr[i].p == Nil)
			root = i;
	}
	dns(root, 0);
	hns(root);
	for (int i = 0; i < N; i++)
	{
		cout << "node " << i << ": parent = " << Tr[i].p << ", sibling = ";
		if (i == root)
			cout << Nil;
		else if (i == Tr[Tr[i].p].l)
			cout << Tr[Tr[i].p].r;
		else
			cout << Tr[Tr[i].p].l;
		cout << ", degree = " << C[i] << ", depth = " << D[i] << ", height = " << H[i] << ", ";
		if (i == root)
			cout << "root";
		else if (i != root&&C[i] != 0)
			cout << "internal node";
		else
			cout << "leaf";
		cout << endl;;
	}

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Tr[i].p = Tr[i].l = Tr[i].r = Nil;
		V[i] = false;
	}
	maketree();
	printtree();
	return 0;
}