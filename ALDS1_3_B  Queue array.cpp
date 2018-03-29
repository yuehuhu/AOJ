#include<iostream>
#include<cstdio>
#include<string>
#define len 150000

using namespace std;


struct A
{
	char name[100];
	int time;
};

int head, tail,N, interval;
A a[len];

A dequeue()
{
	A x = a[head++];
	head = head%len;
	return x;
}

void enqueue(A m)
{
	a[tail] = m;
	tail = (tail + 1) % len;
}

int main()
{
	cin >> N >> interval;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", a[i].name);
		scanf("%d", &a[i].time);
	}
	head = 0;
	tail = N;
	int sum = 0;
	while (head != tail)
	{
		A x = dequeue();
		if (x.time <= interval)
		{
			sum = sum + x.time;
			cout << x.name << ' ' << sum << endl;
		}
		else
		{
			x.time = x.time - interval;
			sum = sum + interval;
			enqueue(x);
		}
	}

	return 0;
}