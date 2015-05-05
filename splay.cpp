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

//added min
node* splay::min(node *nd){
    if(nd == nullptr)return nullptr;
    if(nd->left == nullptr){
        return nd;
    }
    return min(nd->left);
}

node* splay::max(node *nd){
    if(nd == nullptr)return nullptr;
    if(nd->right == nullptr){
        return nd;
    }
    return max(nd->right);
}

node* splay::deleteKey(double dta)
{
  if(root == nullptr)return nullptr;
  return deleteKey(root, dta);
}

node* splay::deleteKey(node* nd, double dta)
{
    if(nd == nullptr)return nullptr;
    if(dta == nd->data){
        
        if(nd->right == nullptr && nd->left != nullptr){
            nd->left->parent = nd->parent;
            if(nd->parent->left == nd){
                nd->parent->left = nd->left;
            }
            else{
                nd->parent->right = nd->left;
            }
        }
        else if(nd->left == nullptr && nd->right != nullptr){
            nd->right->parent = nd->parent;
            if(nd->parent->left == nd){
                nd->parent->left = nd->right;
            }
            else{
                nd->parent->right = nd->right;
            }
        }
        else{
            node* newNode = max(nd->left);
            newNode->parent = nd->parent;
            if(nd->parent->left == nd){
                nd->parent->left = newNode;
            }
            else{
                nd->parent->right = newNode;
            }
        }
        return nd;
    }
    else if(dta < nd->data){
        return deleteKey(nd->left, dta);
    }
    else if(dta > nd->data){
        return deleteKey(nd->right, dta);
    }
	return nullptr;
}

    /*

//case1 no child
    else if(nd->left == nullptr && nd->right == nullptr){
        delete nd;
        nd = nullptr;
    }
//case2 one child
    else if(nd->left == nullptr && nd->right != nullptr){
        node* tmp = nd;
        nd = nd->right;
        delete tmp;
    }
    else if(nd->right == nullptr && nd->left != nullptr){
        node* nemp = nd;
        nd = nd->left;
        delete nemp;
    }
    //case 3 two children
    else if(nd->left != nullptr && nd->right != nullptr){
        node* newNode = min(nd->right);
        nd->data = newNode->data;
        deleteKey(nd->right, newNode->data);
        nd = nd->right;
    }
    
    //recursive
    
  return;
     */



//sorted array
