#include<iostream>
#include<cstdio>

using namespace std;
int A[10000], B[10000], NA, NB;

int linearsearch(int A[], int N, int key)
{
	for (int i = 0; i < N; i++)
	{
		if (A[i] == key)
			return 1;
	}
	return 0;
}

int main()
{
	int sum = 0;
	cin >> NA;
	for (int i = 0; i < NA; i++)
	{
		cin >> A[i];
	}
	cin >> NB;
	for (int i = 0; i < NB; i++)
	{
		cin >> B[i];
		if (linearsearch(A, NA, B[i]))
			sum++;
	}
	cout << sum << endl;
	return 0;
}