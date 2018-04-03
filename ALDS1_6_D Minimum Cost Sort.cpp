#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#define Lens 1000
#define Maxi 10005

using namespace std;
int N,mini;
int A[Lens], B[Lens],C[Maxi];
bool V[Lens];

int solve()
{
	int total=0;
	for (int i = 0; i < N; i++)
	{
		B[i] = A[i];
		V[i] = false;
	}
	sort(B, B + N);
	mini = B[0];
	for (int i = 0; i < N; i++)
	{
		C[B[i]] = i;
		if (B[i] == A[i]) V[i] = true;
	}
	for (int i = 0; i < N; i++)
	{
		while (V[i] == false)
		{
			int tmp = A[i];
			int min_tmp;
			int next = C[A[i]];
			int sum =A[i];
			int n = 0;
			V[i] = true;
			min_tmp= min(A[i], A[next]);
			while (!V[next])
			{
				n++;
				V[next] = true;
				sum = sum + A[next];
				if (A[next] < min_tmp) 
					min_tmp = A[next];
				next= C[A[next]];
			}
			total = total + min(sum + (n - 1)*min_tmp, sum + min_tmp + (n + 2)*mini);
		}
		
	}
	return total;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	int s = solve();
	cout << s << endl;
	return 0;
}