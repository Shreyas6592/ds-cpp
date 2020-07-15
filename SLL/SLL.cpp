//============================================================================
// Name        : SLL.cpp
// Author      : Shreyas Atul Pophli
// Version     :
// Copyright   : No rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

/* Implements the following */
/* Inserting Node before the head (At the beginning)*/
/* Inserting new node after the tail (At the end)*/
/* Inserting a new node in the middle (Random Location)*/

#include <iostream>
#include <stdbool.h>
using namespace std;

/*Singly linked list node*/
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		this->data=0;
		this->next=NULL;
	}
};

Node* head = NULL;
Node* curr = NULL;

//Calculate the size of list
int length()
{
	int count=0;
	Node* tmp = new Node();
	tmp = head;
	while(tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count+1;
}

//Print the list
void print()
{
	Node* itr = new Node();
	itr = head;
	while(itr)
	{
		cout<<itr->data<<" ";
		itr = itr->next;
	}
	cout<<endl;
}

//Append a node
void Add(int Data)
{
	if(head)
	{
		//cout<<"Data to be inserted"<<Data<<endl;
		//cout<<"Head at: "<<head->data<<endl;
		curr = head;
		//cout<<"Curr at: "<<curr->data<<endl;
		while(curr->next)
		{
			//cout<<"In loop: now at:"<<curr->data<<endl;
			curr = curr->next;
		}
		curr->next = new Node();
		curr->next->data = Data;
		curr->next->next = NULL;
		cout<<"Data appended: "<<curr->next->data<<endl;
	}
	else
	{
		head = new Node();
		head->data = Data;
	}
}

void ModHead(int Data)
{
	Node* tmp = new Node;
	tmp->data = Data;
	tmp->next = head;
	head = tmp;
}

void DeleteHead()
{
	Node* tmp = new Node();
	tmp = head;
	head = head->next;
	delete tmp;
}

void InsertAtIdx(int Data, int pos, int len)
{
	Node* nw = new Node();
	nw->data = Data;
	nw->next = NULL;

	if(pos<=1)
	{
		nw->next = head;
		head = nw;
		return;
	}
	else
	{
		int n = pos+1;
		Node* pred = head;
		while(--n && pred!=NULL)
		{
			pred = pred->next;
		}
		nw->next = pred->next;
		pred->next = nw;
	}
}

int main() {
	//init
	curr = new Node();
	Add(10);
	Add(20);
	Add(30);
	Add(40);
	Add(50);
	Add(60);
	print();
	ModHead(5);
	print();
	cout<<"Length: "<<length()<<endl;
	DeleteHead();
	print();
	cout<<"Length: "<<length()<<endl;
	InsertAtIdx(15,1,length());
	print();
	return 0;
}
