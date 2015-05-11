#include "splay.h"
#include <queue>
#include <stack>

splay::~splay()
{
}

//-----------
// insert
//-----------


void splay::insert(double dta)
{
	size++;
	std::cout << std::endl << "Insert: " << dta << std::endl;

	if(root == nullptr)
	{
		node *newNode = new node(dta);
		root = newNode;
		return;
	}
	insert(root, dta);
}

//first search for i. If the search is succesful then splay at the node containing i.
//if search is not sucessful

void splay::insert(node *nd,double dta)
{
    if(nd == nullptr)return;

    if(dta > nd->data){
        if(nd->right == nullptr){
            node *newNode = new node(dta);
            nd->right = newNode;
            newNode->parent = nd;
            splayf(newNode);
        }
        else{
            insert(nd->right,dta);
        }
    }
    else{
        if(nd->left == nullptr){
            node *newNode = new node(dta);
            nd->left = newNode;
            newNode->parent = nd;
            splayf(newNode);
        }
        else{
            insert(nd->left,dta);
        }
    }
    return;
}

void splay::leftRotate(node* nd){
    if (nd == nullptr) return;
    node* tmp = nd->right;
    nd->right = tmp->left;
    tmp->left = nd;
    if(nd->right != nullptr){
        nd->right->parent = nd;
    }
    tmp->parent = nd->parent;
    if(nd->parent == nullptr){
        root = tmp;
    }
    else if(nd->parent->right == nd){
        nd->parent->right = tmp;
    }
    else
    {  
        nd->parent->left = tmp;
    }
    nd->parent = tmp;
}

void splay::rightRotate(node* nd){
        if(nd == nullptr) return;
        node* tmp = nd->left;
        nd->left = tmp->right;
        tmp->right = nd;
        if(nd->left != nullptr){
            nd->left->parent = nd;
        }
        tmp->parent = nd->parent;
        if(nd->parent == nullptr){
            root = tmp;
        }
        else if(nd->parent->left == nd){
            nd->parent->left = tmp;
        }
        else{
            nd->parent->right = tmp;
        }
        nd->parent = tmp;
}

void splay::splayf(node* nd){
    while(nd->parent != nullptr){
		//if nd->parent is root
        if(nd->parent->parent == nullptr){
            //if nd is left child
			if(nd->parent->left == nd){
                rightRotate(nd->parent);
            }
            else{
                leftRotate(nd->parent);
            }
        }
        else if(nd->parent->left == nd && nd->parent->parent->left == nd->parent){
            rightRotate(nd->parent->parent);
            rightRotate(nd->parent);
        }
        else if(nd->parent->right == nd && nd->parent->parent->right == nd->parent){
            leftRotate(nd->parent->parent);
            leftRotate(nd->parent);
        }
        else if(nd->parent->left == nd && nd->parent->parent->right == nd->parent){
            rightRotate(nd->parent);
            leftRotate(nd->parent);
        }
        else{
            leftRotate(nd->parent);
            rightRotate(nd->parent);
        }
    }
	root = nd;
}

//-----------
// print Breadth
//-----------
void splay::printBreadthFirst(){
    if(root == nullptr)return;
    std::queue<node*> qe;
    qe.push(root);
    while(!qe.empty()){
        node* tmp = qe.front();
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
node* splay::min(node *nd){
    if(nd == nullptr)return nullptr;
    if(nd->left == nullptr){
        return nd;
    }
    return min(nd->left);
}


//-----------
// max
//-----------
node* splay::max(node *nd){
    if(nd == nullptr)return nullptr;
    if(nd->right == nullptr) return nd;
    return max(nd->right);
}

/*


//-----------
// delete
//-----------

//switch
void splay::switchf(node* nd1, node* nd2){
    if (nd1->parent == nullptr) root = nd2;
    else if(nd1 == nd1->parent->left){
        nd1->parent->left = nd2;
    }
    else{
        nd1->parent->right = nd2;
    }
    if(nd2 != nullptr){
        nd2->parent = nd1->parent;
    }
}

*/
node* splay::deleteKey(double dta)
{
    if(root == nullptr)return nullptr;
    node* nd = search(dta);
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
        node* newNode = max(nd->left);	//newNode is rightmost child of left subtree

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


//sorted array
std::vector<double> splay::sortedArray()
{
	std::vector<double> vct;
	if(root == nullptr) return vct;
	sortedArray(root, vct);
	return vct;
}

void splay::sortedArray(node* nd, std::vector<double>& vct)
{
	if(nd == nullptr) return;
	sortedArray(nd->left, vct);
	vct.push_back(nd->data);
	sortedArray(nd->right, vct);
}



void splay::print()
{
	std::cout << "Size: " << size << std::endl;
	std::cout  << "    InOrder Print" << std::endl;
	inOrder();
	std::cout << "    Breadth First Print" << std::endl;
	printBreadthFirst();
	std::cout << std::endl;
}
