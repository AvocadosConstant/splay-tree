#ifndef SPLAY_H_
#define SPLAY_H_

#include <vector>
#include <iostream>
#include "node.h"

class splay
{
	public:
		splay():root(nullptr){};
		~splay();
		void insert(double dta);
		void inOrder();
		node* search(double dta);
        node* min(node* nd);
        node* max(node* nd);
		void deleteKey(double dta);
    void switchf(node* nd1, node* nd2);
		// sortedArray(); //return array of tree with items inOrder

	private:
		node* root;
		void insert(node *nd,double dta);
		void inOrder(node *nd);
		node* search(node* nd,double dta);
		node* deleteKey(node* nd, double dta);
};

#endif
