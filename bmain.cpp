#include "bst.h"

int main()
{
	bst tree;
	tree.insert(10);
	tree.insert(11);
	tree.insert(9);
	tree.insert(12);
	tree.insert(8);

	std::cout << "inOrder: \n";
	tree.inOrder();

	std::cout << "preOrder: \n";
	tree.preOrder();

	std::cout << "postOrder: \n";
	tree.postOrder();

	std::cout << "\nsize: " << tree.size();

	std::cout << "\nnumLeaves: " << tree.numLeaves();
	std::cout << "\nsumLeaves: " << tree.sumLeaves();
	std::cout << "\nmin: " << tree.min()->data;
	std::cout << "\nmax: " << tree.max()->data;
//	std::cout << "\nfind(9): " << tree.find(9)->data;
	std::cout << "\nclosestToK(11.9): " << tree.closestToK(11.7)->data;
//	std::cout << "";

	return 0;
}
