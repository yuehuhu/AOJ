#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
long long cnt;
int N;
int A[1000000], G[100];

void insertionSort(int A[], int N, int g)
{
	for (int i = g; i < N; i++)
	{
		int tmp1 = i;
		int tmp2 = i - g;
		while (tmp2 >= 0 && A[tmp2] > A[tmp1])
		{
			swap(A[tmp2], A[tmp1]);
			tmp1 = tmp2;
			tmp2 = tmp2 - g;
			cnt++;
		}
	}

}

void shellSort(int A[], int N, int G[])
{
	int i = 0;
	for (int h = 1; h <= N; i++)
	{
		G[i] = h;
		h = 3 * h + 1;
	}
	cout << i << endl;
	if (i != 1)
	{
		for (int j = i - 1; j > 0; j--)
		{
			cout << G[j] << " ";
		}
	}

	cout << G[0] << endl;
	for (int j = i - 1; j >= 0; j--)
	{
		insertionSort(A, N, G[j]);
	}
	cout << cnt << endl;
	for (int j = 0; j < N; j++)
	{
		cout << A[j] << endl;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	shellSort(A, N, G);
	return 0;
}