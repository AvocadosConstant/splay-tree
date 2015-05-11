#include "splay.h"
#include <iostream>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
  splay s;

  std::cout << "inserting 9, 4, 13, 6, 20, 11" << std::endl;

  std::cout << std::endl;
  std::cout << "inserting 9";
  s.insert(9);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "inserting 4";
  s.insert(4);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "inserting 13";
  s.insert(13);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "inserting 6";
  s.insert(6);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "inserting 20";
  s.insert(20);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "inserting 11";
  s.insert(11);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();


  std::cout << std::endl;
  std::cout << "searching for 9" << std::endl;
  s.search(9);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << std::endl;
  std::cout << "searching for 12" << std::endl;
  s.search(12);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();


  std::cout << "del 11" << std::endl;
  s.deleteKey(11);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << "del 6" << std::endl;
  s.deleteKey(6);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << "del nonexistant num" << std::endl;
  s.deleteKey(21);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  std::cout << "del 20" << std::endl;
  s.deleteKey(20);
  std::cout << std::endl << "inorder print" << std::endl;
  s.inOrder();
  std::cout << std::endl << "breadth first print" << std::endl;
  s.printBreadthFirst();

  return 0;

}
