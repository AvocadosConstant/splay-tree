#include "splay.h"
#include <iostream>
#include <stack>
#include <queue>

int main(int argc, char const *argv[])
{
  splay s;

  std::cout << "inserting 9, 4, 13, 6, 20, 11" << std::endl;

  s.insert(9);
  s.print();

  s.insert(4);
  s.print();

  s.insert(13);
  s.print();

  s.insert(6);
  s.print();

  s.insert(20);
  s.print();

  s.insert(11);
  s.print();


  std::cout << std::endl;
  std::cout << "searching for 9" << std::endl;
  s.search(9);
  s.print();

  std::cout << std::endl;
  std::cout << "searching for 12" << std::endl;
  s.search(12);
  s.print();


  std::cout << "del 11" << std::endl;
  s.deleteKey(11);
  s.print();

  std::cout << "del 6" << std::endl;
  s.deleteKey(6);
  s.print();

  std::cout << "del nonexistant num" << std::endl;
  s.deleteKey(21);
  s.print();

  std::cout << "del 20" << std::endl;
  s.deleteKey(20);
  s.print();

  return 0;

}
