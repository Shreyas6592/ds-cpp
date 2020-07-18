//============================================================================
// Name        : DLL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct Node{
	int data;
	Node* prev;
	Node* next;
}Node;

Node* head = NULL;

Node* Init(int Data)
{
	head = new Node;
	head->data = Data;
	head->prev = NULL;
	head->next = NULL;
	return head;
}

Node* Append(int Data)
{
	Node* curr = head;
	if(!curr)
	{
		curr = new Node;
		curr->data = Data;
		curr->prev = NULL;
		curr->next = NULL;
		return curr;
	}
	else
	{
		while(curr->next != NULL)
		{
			curr=curr->next;
		}
		Node* newNode = new Node;
		newNode->data = Data;
		newNode->next = NULL;
		curr->next = newNode;
		newNode->prev = curr;
		return head;
	}
}

void Print()
{
	Node* curr = head;
	while(curr)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

int main() {
	Node* ptr = Init(10);
	Append(20);
	Append(30);
	Append(40);
	Print();
	return 0;
}
