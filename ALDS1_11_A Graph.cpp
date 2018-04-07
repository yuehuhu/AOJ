#include<iostream>
#include<cstdio>
#define Lens 100
using namespace std;
int N;
int A[Lens][Lens];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int k, n;
		cin >> k >> n;
		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			A[k][j] = 1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j > 1)
				cout << ' ';
			cout << A[i][j];
		}
		cout << endl;
	}
	return 0;
}