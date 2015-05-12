#ifndef SPLAY_H_
#define SPLAY_H_

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include "node.h"

template<class T>
class splay
{
	public:
		splay():root(nullptr),size(0){};
		~splay();
		void insert(T dta);
	    void leftRotate(node<T>* nd);
	    void rightRotate(node<T>* nd);
	    void splayf(node<T>* nd);
	    void printBreadthFirst();
		void inOrder();
		node<T>* search(T dta);
        node<T>* min(node<T>* nd);
        node<T>* max(node<T>* nd);
		node<T>* deleteKey(T dta);
		std::vector<T> sortedArray();
		node<T>* getRoot(){return root;};
		int getSize(){return size;};
		void print();

	private:
		node<T>* root;
		void insert(node<T> *nd,T dta);
		void inOrder(node<T> *nd);
		node<T>* search(node<T>* nd,T dta);
		node<T>* deleteKey(node<T>* nd, T dta);
		void sortedArray(node<T>* nd, std::vector<T>& vct);
		int size;
};

//#include "splay.cpp"

template<class T>
splay<T>::~splay()
{
}

//-----------
// insert
//-----------
template<class T>
void splay<T>::insert(T dta)
{
	size++;
	std::cout << std::endl << "Insert: " << dta << std::endl;

	if(root == nullptr)
	{
		node<T> *newNode = new node<T>(dta);
		root = newNode;
		return;
	}
	insert(root, dta);
}

template<class T>
void splay<T>::insert( node<T> *nd,T dta)
{
    if(nd == nullptr)return;

    if(dta > nd->data)
	{
        if(nd->right == nullptr)
		{
            node<T> *newNode = new node<T>(dta);
            nd->right = newNode;
            newNode->parent = nd;
            splayf(newNode);
        }
        else insert(nd->right,dta);
    }
    else
	{
        if(nd->left == nullptr)
		{
            node<T> *newNode = new node<T>(dta);
            nd->left = newNode;
            newNode->parent = nd;
            splayf(newNode);
        }
        else insert(nd->left,dta);
    }
    return;
}

//-----------
// leftRotate
//-----------
template<class T>
void splay<T>::leftRotate( node<T>* nd)
{
    if (nd == nullptr) return;

    node<T>* tmp = nd->right;
    nd->right = tmp->left;
    tmp->left = nd;
    if(nd->right != nullptr) nd->right->parent = nd;
    tmp->parent = nd->parent;

    if(nd->parent == nullptr) root = tmp;
    else if(nd->parent->right == nd) nd->parent->right = tmp;
    else nd->parent->left = tmp;

    nd->parent = tmp;
}

//-----------
// rightRotate
//-----------
template<class T>
void splay<T>::rightRotate( node<T>* nd)
{
	if(nd == nullptr) return;

    node<T>* tmp = nd->left;
    nd->left = tmp->right;
    tmp->right = nd;
    if(nd->left != nullptr) nd->left->parent = nd;
    tmp->parent = nd->parent;

    if(nd->parent == nullptr) root = tmp;
    else if(nd->parent->left == nd) nd->parent->left = tmp;
    else nd->parent->right = tmp;

    nd->parent = tmp;
}

//-----------
// splayf
//-----------
template<class T>
void splay<T>::splayf( node<T>* nd)
{
    while(nd->parent != nullptr)
	{
		//if nd->parent is root
        if(nd->parent->parent == nullptr)
		{
            //nd is left child
			if(nd->parent->left == nd) rightRotate(nd->parent);
			//nd is right child
            else leftRotate(nd->parent);
        }

		// left child zig-zig
        else if(nd->parent->left == nd && nd->parent->parent->left == nd->parent)
		{
            rightRotate(nd->parent->parent);
            rightRotate(nd->parent);
        }
		// right child zig-zig
        else if(nd->parent->right == nd && nd->parent->parent->right == nd->parent)
		{
            leftRotate(nd->parent->parent);
            leftRotate(nd->parent);
        }

		// left child zig-zag
        else if(nd->parent->left == nd && nd->parent->parent->right == nd->parent)
		{
            rightRotate(nd->parent);
            leftRotate(nd->parent);
        }
		// right child zig-zag
        else
		{
            leftRotate(nd->parent);
            rightRotate(nd->parent);
        }
    }
	//nd will be the new root
	root = nd;
}

//-----------
// print Breadth
//-----------
template<class T>
void splay<T>::printBreadthFirst(){
    if(root == nullptr)return;
    std::queue< node<T>* > qe;
    qe.push(root);
    while(!qe.empty()){
        node<T>* tmp = qe.front();
        if(tmp->left != nullptr){
//            std::cout << "/" << std::endl;
            qe.push(tmp->left);
        }
        if(tmp->right != nullptr){
            qe.push(tmp->right);
//            std::cout << "\\" << std::endl;
        }

        std::cout<< tmp->data << std::endl;

        qe.pop();
    }
}

//-----------
// inOrder
//-----------
template<class T>
void splay<T>::inOrder()
{
	if(root == nullptr) return;
	inOrder(root);
}

template<class T>
void splay<T>::inOrder( node<T>* nd)
{
	if(nd == nullptr) return;
	inOrder(nd->left);
	std::cout << nd->data << std::endl;
	inOrder(nd->right);
}


//-----------
// search
//-----------
template<class T>
node<T>* splay<T>::search(T dta)
{
	if(root == nullptr) return nullptr;
	return search(root, dta);
}

template<class T>
node<T>* splay<T>::search( node<T> *nd, T dta)
{
	if(nd == nullptr)
	{
		std::cout << "Did not find node with value " << dta << std::endl;
		return nullptr;
	}
    if(nd->data == dta){
        std::cout << "Found node with value " << nd->data << std::endl;
        //std::cout << nd->data << std::endl;
        splayf(nd);
        return nd;
    }
	if(nd->data > dta && nd->left!=nullptr) return search(nd->left, dta);
	if(nd->data < dta && nd->right!=nullptr) return search(nd->right, dta);

	std::cout << "Did not find node with value " << dta << std::endl;
	return nullptr;
}


//-----------
// min
//-----------
template<class T>
node<T>* splay<T>::min( node<T> *nd){
    if(nd == nullptr)return nullptr;
    if(nd->left == nullptr){
        return nd;
    }
    return min(nd->left);
}


//-----------
// max
//-----------
template<class T>
node<T>* splay<T>::max( node<T> *nd){
    if(nd == nullptr)return nullptr;
    if(nd->right == nullptr) return nd;
    return max(nd->right);
}


//-----------
// deleteKey
//-----------
template<class T>
node<T>* splay<T>::deleteKey(T dta)
{
    if(root == nullptr)return nullptr;
    node<T>* nd = search(dta);
    if (nd == nullptr)return nullptr;

	//because search was called, nd is the root!!!

	//if nd has no children
	if(nd->left == nullptr && nd->right == nullptr) root = nullptr;

	// nd has only a left child
    else if(nd->right == nullptr && nd->left != nullptr)
	{
		nd->left->parent = nullptr;
		root = nd->left;
    }
	// nd has only a right child
    else if(nd->left == nullptr && nd->right != nullptr)
	{
		nd->right->parent = nullptr;
		root = nd->right;
    }

    //If node to delete has two children
	else
	{
        node<T>* newNode = max(nd->left);	//newNode is rightmost child of left subtree

		//splay newnode to top of left subtree
		nd->left->parent = nullptr;
		splayf(newNode);

		//join left subtree with right subtree
		newNode->right = nd->right;
		newNode->right->parent = newNode;

    }
	size--;
    return nd;
}


//-----------
// sorted Array
//-----------
template<class T>
std::vector<T> splay<T>::sortedArray()
{
	std::vector<T> vct;
	if(root == nullptr) return vct;
	sortedArray(root, vct);
	return vct;
}

template<class T>
void splay<T>::sortedArray( node<T>* nd, std::vector<T>& vct)
{
	if(nd == nullptr) return;
	sortedArray(nd->left, vct);
	vct.push_back(nd->data);
	sortedArray(nd->right, vct);
}


//-----------
// print
//-----------
template<class T>
void splay<T>::print()
{
	std::cout << "- Size: " << size << std::endl;
	std::cout << "- InOrder Print" << std::endl;
	inOrder();
	std::cout << "- Breadth First Print" << std::endl;
	printBreadthFirst();
	std::cout << std::endl;
}

#endif
