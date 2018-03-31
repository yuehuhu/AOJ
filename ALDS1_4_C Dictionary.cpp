#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

#define M 1000000
#define L 14
char H[M][L];

int getchar(char s)
{
	if (s == 'A') return 1;
	else if (s == 'C') return 2;
	else if (s == 'G') return 3;
	else if (s == 'T') return 4;
	else return 0;
}

int getkey(char A[])
{
	int sum = 0;
	int p = 1;
	for (int i = 0; i < strlen(A); i++)
	{
		int tmp = getchar(A[i]);
		sum = sum + tmp*p;
		p = p * 5;
	}
	return sum;
}

int h1(int key)
{
	return key%M;
}

int h2(int key)
{
	return 1 + key % (M - 1);
}


int insert(char str[])
{
	int key=getkey(str);
	for (int i = 0;; i++)
	{
		int h = (h1(key) + i*h2(key))%M;
		if (strcmp(H[h], str) == 0)
			return 1;
		else if (strlen(H[h]) == 0)
		{
			strcpy(H[h], str);
			return 0;
		}	
	}
	return 0;
}

int find(char str[])
{
	int key = getkey(str);
	for (int i = 0;; i++)
	{
		int h = (h1(key) + i*h2(key)) % M;
		if (strcmp(H[h], str) == 0)
			return 1;
		else if (strlen(H[h]) == 0)
		{
			return 0;
		}
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;
	char A[6], S[L];
	for (int i = 0; i < M; i++)
	{
		H[i][0] = '\0';
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%s%s", A, S);
		if (A[0] == 'i')
		{
			insert(S);
		}
		else if (A[0] == 'f')
		{
			if (find(S))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}