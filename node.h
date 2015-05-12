#ifndef NODE_H_
#define NODE_H_

template<class T>
struct node

{
	node():parent(nullptr),left(nullptr),right(nullptr),data(nullptr){};
	node(T dta):parent(nullptr),left(nullptr),right(nullptr),data(dta){};

	node<T>* parent;
	node<T>* left;
	node<T>* right;
	T data;
};

#endif
