#include<iostream>
#include<cstdio>
#include<string>
#include<stdlib.h>

using namespace std;


struct Node
{
	int key;
	Node *pre, *next;
};

Node *nil;

void init()
{
	nil = (Node*)malloc(sizeof(Node));
	nil->pre = nil;
	nil->next = nil;
}

void insert(int key)
{
	Node *x = (Node*)malloc(sizeof(Node));
	x->key = key;
	x->next = nil->next;
	nil->next->pre = x;
	nil->next = x;
	x->pre = nil;
}

Node *findlist(int key)
{
	Node *cur = nil->next;
	while (cur->key != key&&cur != nil)
	{
		cur = cur->next;
	}
	return cur;
}

void deleteNode(Node *node)
{
	if (node == nil) return;
	node->next->pre = node->pre;
	node->pre->next = node->next;
	free(node);
}

void deletekey(int key)
{
	deleteNode(findlist(key));
}

void deletefirst()
{
	deleteNode(nil->next);
}

void deletelast()
{
	deleteNode(nil->pre);
}

void printNode()
{
	int sum = 0;
	while (nil->next != nil)
	{
		if (sum++ > 0)
			cout << ' ';
		cout << nil->next->key;
		deleteNode(nil->next);
	}
	cout << endl;
}

int main()
{
	int N, key;
	char A[100];
	cin >> N;
	init();
	for (int i = 0; i < N; i++)
	{
		scanf("%s", A);
		if (A[0] == 'i')
		{
			scanf("%d", &key);
			insert(key);
		}
		else if (A[0] == 'd')
		{
			if (A[6] == 'F')
			{
				deletefirst();
			}
			else if (A[6] == 'L')
			{
				deletelast();
			}
			else
			{
				scanf("%d", &key);
				deletekey(key);
			}
		}
	}
	printNode();
	return 0;
}