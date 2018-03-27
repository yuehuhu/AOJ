#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

void Print(int A[],int N)
{
	for (int i = 0; i < N-1; i++)
	{
		cout << A[i] << " ";
	}
	cout <<A[N-1]<< endl;
}

int main()
{
	int A[100];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		int tmp = A[i];
		int j = i-1;
		while (A[j] >tmp && j >= 0)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
		Print(A, N);
	}
	return 0;
}