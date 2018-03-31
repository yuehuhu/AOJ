#include<iostream>
#include<cstdio>

using namespace std;
int A[10000], B[10000], NA, NB;

int binarysearch(int key)
{
	int left = 0, right = NA - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (A[mid] == key)
			return 1;
		else if (A[mid] < key)
			left = mid + 1;
		else
			right = mid-1;
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
		if (binarysearch( B[i]))
			sum++;
	}
	cout << sum << endl;
	return 0;
}