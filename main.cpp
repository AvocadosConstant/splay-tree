#include "splay.h"
#include <iostream>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
  splay s;

  std::cout << "inserting 9, 4, 13, 6, 20, 11" << std::endl;
  s.insert(9);
  s.insert(4);
  s.insert(13);
  s.insert(6);
  s.insert(20);
  s.insert(11);

  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();

 // std::cout << "proving" << std::endl;

  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl << "left rotate on root" << std::endl;
  s.leftRotate(s.getRoot());

  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();

  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();


/*
  std::cout << "del 11" << std::endl;
  s.deleteKey(11);
  s.inOrder();
  std::cout << "del 6" << std::endl;
  s.deleteKey(6);
  s.inOrder();
  std::cout << "del nonexistant num" << std::endl;
  s.deleteKey(21);
  s.inOrder();
  std::cout << "del 20" << std::endl;
  s.deleteKey(20);
  s.inOrder();
*/
//  s.search(8);
  //s.search(12);

  std::cout << "main is running." << std::endl;
  return 0;

}
