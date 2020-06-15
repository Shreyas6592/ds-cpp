//============================================================================
// Name        : bst.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
public:
	int value;
	Node *left;
	Node *right;
	Node();
	Node(int a)
	{
		value = a;
		left = right = NULL;
	}
};

class BST{
private:
	Node *root;
	void addB(Node * root,int a);
	void preOrderB(Node *aNode);
	void inOrderB(Node *aNode);
	void postOrderB(Node *aNode);
public:
	BST();
	void add(int val);
	Node* Search(int a);
	void preOrder();
	void inOrder();
	void postOrder();
};

BST::BST() {
    root = NULL;
}

void BST::add(int v)
{
	if(root!=NULL)
	{
		addB(root,v);
	}
	else
	{
		root = new Node(v);
		root->value = v;
		root->left = NULL;
		root->right = NULL;
		cout<<"Root Node Created!!!"<<endl;
	}
}

void BST::addB(Node *root,int a)
{
	Node * tmp = root;

	if(tmp->value < a)
	{
		if(tmp->right != NULL)
		{
			addB(tmp->right,a);
		}
		else
		{
			tmp->right = new Node(a);
			tmp->right->right = NULL;
			tmp->right->left = NULL;
		}
	}
	else if(tmp->value >= a)
	{
		if(tmp->left != NULL)
		{
			addB(tmp->left,a);
		}
		else
		{
			tmp->left = new Node(a);
			tmp->left->right = NULL;
			tmp->left->left = NULL;
		}
	}
}

Node* BST::Search(int a)
{
return NULL;
}

void BST::preOrderB(Node *aNode)
{
	if(aNode==NULL){return;}

		cout<<aNode->value<<"->";
		preOrderB(aNode->left);
		preOrderB(aNode->right);


}

void BST::preOrder()
{
//RoLR
	preOrderB(root);
}

int main() {
	BST *bst = new BST;
	bst->add(15);
	bst->add(10);
	bst->add(22);
	bst->add(4);
	bst->add(12);
	bst->add(18);
	bst->add(24);
	bst->preOrder();
	return 0;
}
