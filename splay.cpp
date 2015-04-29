#include "splay.h"

splay::~splay()
{
}

//-----------
// insert
//-----------
void splay::insert(double dta)
{
	if(root == nullptr)
	{
		node *newNode = new node(dta);
		root = newNode;
		return;
	}
	insert(root, dta);
}


void splay::insert(node *nd, double dta)
{
	if(nd->data < dta)
	{
		if(nd->right == nullptr)
		{
			node *newNode = new node(dta);
			nd->right = newNode;
		}
		else insert(nd->right, dta);
	}
	else
	{
		if(nd->left == nullptr)
		{
			node *newNode = new node(dta);
			nd->left = newNode;
		}
		else insert(nd->left, dta);
	}
	return;
}

//-----------
// inOrder
//-----------
void splay::inOrder()
{
	if(root == nullptr) return;
	inOrder(root);
}

void splay::inOrder(node* nd)
{
	if(nd == nullptr) return;
	inOrder(nd->left);
	std::cout << nd->data << std::endl;
	inOrder(nd->right);
}


//-----------
// search
//-----------
node* splay::search(double dta)
{
	if(root == nullptr) return nullptr;
	return search(root, dta);
}

node* splay::search(node *nd, double dta)
{
	if(nd == nullptr) return nullptr;
	if(nd->data == dta) return nd;
	if(nd->data <= dta && nd->left!=nullptr) return search(nd->left, dta);
	if(nd->data > dta && nd->right!=nullptr) return search(nd->right, dta);
	return nullptr;
}

void splay::deleteKey(double dta)
{
}

void splay::deleteKey(node* nd, double dta)
{
}



//sorted array
