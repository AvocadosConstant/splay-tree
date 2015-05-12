#ifndef SPLAY_H_
#define SPLAY_H_

#include <vector>
#include <iostream>
#include "node.h"

class splay
{
	public:
		splay():root(nullptr),size(0){};
		~splay();
		void insert(double dta);
	    void leftRotate(node* nd);
	    void rightRotate(node* nd);
	    void splayf(node* nd);
        std::vector<double> printBreadthFirst();
		void inOrder();
		node* search(double dta);
        node* min(node* nd);
        node* max(node* nd);
		node* deleteKey(double dta);
		std::vector<double> sortedArray();
		node* getRoot(){return root;};
		int getSize(){return size;};
		void print();

	private:
		node* root;
		void insert(node *nd,double dta);
		void inOrder(node *nd);
		node* search(node* nd,double dta);
		node* deleteKey(node* nd, double dta);
		void sortedArray(node* nd, std::vector<double>& vct);
		int size;
};

#endif
