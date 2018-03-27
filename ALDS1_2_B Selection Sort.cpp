#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

void Print(int A[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
}

int main()
{
	int A[100];
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		int tmp = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] < A[tmp])
			{
				tmp = j;

			}
		}
		if (i != tmp)
		{
			swap(A[i], A[tmp]);
			sum++;
		}


	}
	Print(A, N);
	cout << sum << endl;
	return 0;
}