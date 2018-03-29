#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstdlib>

using namespace std;
int A[1000];
int top;

void push(int x)
{
	A[++top] = x;
}

int pop()
{
	top--;
	return A[top + 1];
}

int main()
{
	char s[100];
	while (scanf("%s", s) != EOF)
	{
		cout << s << endl;
	/*
		if (s[0] =='+')
		{
			int a = pop();
			int b = pop();
			push(a + b);
		}
		else if (s[0] == '-')
		{
			int a = pop();
			int b = pop();
			push(b-a);
		}
		else if (s[0] == '*')
		{
			int a = pop();
			int b = pop();
			push(a*b);
		}
		else
		{
			push(atoi(s));
		}
		*/
	}
	//printf("%d", pop());
	return 0;
}