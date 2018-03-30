#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int main()
{
	list<int> v;
	int N;
	char A[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", A);
		if (A[0] == 'i')
		{
			int key;
			scanf("%d", &key);
			v.push_front(key);
		}
		else if (A[0] == 'd')
		{
			if (A[6] == 'F')
			{
				v.pop_front();
			}
			else if (A[6] == 'L')
			{
				v.pop_back();
			}
			else
			{
				int key;
				scanf("%d", &key);
				for (list<int>::iterator it = v.begin(); it != v.end(); it++)
				{
					if (*it == key)
					{
						v.erase(it);
						break;
					}
				}
			}
		}
	}
	int sum = 0;
	for (list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (sum++ > 0)
		{
			cout << ' ' <<*it ;
		}
		else
		{
			cout << *it;
		}

	}
	cout << endl;
	return 0;
}