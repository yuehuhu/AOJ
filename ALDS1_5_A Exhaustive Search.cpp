#include<iostream>
#include<cstdio>
using namespace std;

int N1, N2, A[20], M[200];

int res(int i, int m)
{
	if (m == 0) return 1;
	else if (i >= N1) return 0;
	else return res(i + 1, m) || res(i + 1, m - A[i]);
}

int main()
{
	cin >> N1;
	for (int i = 0; i < N1; i++)
	{
		cin >> A[i];
	}
	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		cin >> M[i];
		if (res(0, M[i]))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}