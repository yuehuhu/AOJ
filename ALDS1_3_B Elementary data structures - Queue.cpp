#include<iostream>
#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int N;
int interval;

struct A
{
	string suit;
	int time;
};

int main()
{
	queue<A> Q;
	A a;
	int sum = 0;
	cin >> N >> interval;
	for (int i = 0; i < N; i++)
	{
		cin >> a.suit >> a.time;
		Q.push(a);
	}
	while (!Q.empty())
	{
		a = Q.front();
		Q.pop();
		if (a.time - interval <= 0)
		{
			sum = sum + a.time;
			
			cout << a.suit << ' '<<sum << endl;
			
		}
		else
		{
			a.time = a.time - interval;
			sum = sum + interval;
			Q.push(a);
		}
		
	}


	return 0;
}