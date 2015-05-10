#include "splay.h"
#include <iostream>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
  splay s;
  s.insert(10);
  s.insert(8);
  s.insert(13);
    std::cout << "proving" << std::endl;
    
    s.printBreadthFirst();

    /*
  s.insert(6);
  s.insert(20);
  s.insert(11);
      s.inOrder();
    std::cout << "proving" << std::endl;

    s.printBreadthFirst();
  */
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

  s.search(8);
  s.search(12);
   */
  std::cout << "main is running." << std::endl;
  return 0;

}
