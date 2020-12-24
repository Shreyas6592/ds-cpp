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

int Length()
{
	Node* curr = head;
	int cnt = 0;
	if(!curr)
	{
		return cnt;
	}
	else
	{
		while(curr)
		{
			cnt++;
			curr=curr->next;
		}
		return cnt;
	}
}

Node* Delete(int pos)    //Position '1' is head
{
	if(pos==0 && pos>Length())
	{
		cout<<"Invalid position"<<endl;
		return NULL;
	}
	else if(pos==1)  //Delete head
	{
		if(head)
		{
			Node*tmp = head;
			head = tmp->next;
			delete tmp;
			return head;
		}
		else
		{
			cout<<"No element in list"<<endl;
		}
	}
	else{
		if(head)
		{
			Node*tmp = head;
			while(--pos && tmp)
			{
				tmp=tmp->next;
			}
			Node* tmp2 = tmp->prev;
			tmp2->next = tmp->next;
			if(tmp->next)
			{
				tmp->next->prev = tmp2;
			}
			delete tmp;
			return head;
		}
	}
}

int main() {
	Node* ptr = Init(10);
	Append(20);
	Append(30);
	Append(40);
	Print();
	Delete(2);
	Print();
	Delete(1);
	Print();
	cout<<Length()<<endl;
	return 0;
}
