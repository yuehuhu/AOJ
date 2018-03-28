#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Card
{
	char suit;
	char value;
};

void bubble(Card A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (A[j].value < A[j - 1].value)
			{
				swap(A[j], A[j - 1]);
			}

		}
	}
}

void selection(Card A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		int tmp = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[j].value < A[tmp].value)
			{
				tmp = j;
			}
		}
		swap(A[i], A[tmp]);
	}
}

void Print(Card A[], int N)
{
	for (int i = 0; i < N-1; i++)
	{
		cout << A[i].suit << A[i].value << " ";

	}
	cout << A[N-1].suit << A[N-1].value << endl;
}

bool isstable(Card A[], Card C[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int flag = 1;
			if (A[j].value == A[i].value)
			{
				for (int m = 0; m < N; m++)
				{
					if (C[m].value == A[i].value)
					{
						if (C[m].suit != A[i].suit)
							return false;
						else
						{
							C[m] = A[j];
							flag = 0;
							break;
						}
					}
				}
			}
			if (flag == 0)
			{
				break;
			}
		}
	}
	return true;
}


int main()
{
	Card A[100],B[100],C[100],D[100];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].suit >> A[i].value;
	}
	for (int i = 0; i < N; i++)
	{
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
	}
	bubble(A, N);
	Print(A, N);
	if(isstable(A, C, N))
	{
		cout << "Stable" << endl;
	}
	else
	{
		cout << "Not stable" << endl;
	}
	selection(B, N);
	Print(B, N);
	if (isstable(B, D, N))
	{
		cout << "Stable" << endl;
	}
	else
	{
		cout << "Not stable" << endl;
	}
	return 0;
}