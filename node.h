#ifndef NODE_H_
#define NODE_H_

struct node

{
	node():parent(nullptr),left(nullptr),right(nullptr),data(0){};
	node(double dta):parent(nullptr),left(nullptr),right(nullptr),data(dta){};

	node* parent;
	node* left;
	node* right;
	double data;
};

#endif
