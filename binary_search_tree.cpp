#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
	BST b;
	b.insert(56);
	b.insert(34);
	b.insert(70);
	b.insert(5);
	b.insert(1);
	b.insert(42);
	b.insert(40);
	b.insert(52);
	b.insert(62);
	b.insert(57);
	b.insert(89);
	b.insert(90);
	cout << b.find(44) << endl;
	cout << b.find(62) << endl;
	b.remove(62);
	cout << b.find(62) << endl;
	b.insert(44);
	cout << b.find(44);
	b.postOrder(cout);
	b.preOrder(cout);
	b.inOrder(cout);
}
