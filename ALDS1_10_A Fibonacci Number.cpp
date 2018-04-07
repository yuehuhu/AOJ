#include<iostream>
#include<cstdio>
#define Lens 50
using namespace std;

int n;
int F[Lens];
int main()
{
	F[0] = F[1] = 1;
	for (int i = 2; i <= Lens; i++)
		F[i] = F[i - 1] + F[i - 2];
	cin >> n;
	cout << F[n] << endl;
	return 0;
}