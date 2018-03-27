#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int R[200000];
	int N;
	int mini, maxi;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> R[i];
	}

	maxi = R[1] - R[0];
	mini = R[0];
	for (int i = 1; i < N; i++)
	{
		mini = min(mini, R[i-1]);
		maxi = max(maxi, R[i] - mini);
	}
	cout << maxi << endl;
	return 0;
}