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
    //first search forr i. If the search is succesful then splay at the node containing i.
    //if search is not sucessful
    node *newNode = new node(dta);
    if(nd == nullptr)return;
	if(nd->data < dta)
	{
		if(nd->right == nullptr)
		{
            newNode->parent = nd;
			nd->right = newNode;
		}
		else insert(nd->right, dta);
	}
	else
	{
		if(nd->left == nullptr)
		{
            newNode->parent = nd;
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
    if(nd->data == dta){
       // std::cout << nd->data << std::endl;
        return nd;
    }
	if(nd->data > dta && nd->left!=nullptr) return search(nd->left, dta);
	if(nd->data < dta && nd->right!=nullptr) return search(nd->right, dta);
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

/*

node* splay::deleteKey(double dta)
{
  if(root == nullptr)return nullptr;
    node* nd = search(dta);
    if (nd == nullptr)return nullptr;
    
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
        //newNode->parent = nd->parent;
        if(nd->parent->left == nd){
            nd->parent->left = newNode;
        }
        else{
            nd->parent->right = newNode;
        }
        newNode->right = nd->right;
    }
    return nd;

}
*/

void splay::deleteKey(double dta)
{
    if(root == nullptr)return;
    node* nd = search(dta);
    if (nd == nullptr)return;
    //splay(nd);
    if(nd->left == nullptr && nd->right != nullptr){
        switchf(nd, nd->right);
    }
    else if(nd->right == nullptr && nd->left != nullptr){
        switchf(nd, nd->left);
    }
    else{
        node* tmp = max(nd->left);
        if(tmp->parent != nd){
            switchf(tmp, tmp->left);
            tmp->left = nd->left;
            tmp->left->parent = tmp;
        }
        switchf(nd, tmp);
        tmp->right = nd->right;
        tmp->right->parent = tmp;
    }
    delete nd;
}

    
    
    
    
    

//sorted array
