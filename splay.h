#ifndef SPLAY_H_
#define SPLAY_H_

#include <vector>
#include <iostream>

class splay
{
 public:
 splay():root(nullptr){};
  ~splay();
  void insert();
  void inOrder();
  node* search(double k);
  void deleteKey(double k);
  void sortedArray(); //?
  
 private:
  node* root;
  void insert(node *nd,double dta);
  void inOrder(node *nd);
  node* find(node* nd,double k);
  void deleteKey(node* nd, double k);
};

#endif
