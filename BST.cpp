#include "BST.h"
#include "Node.h"

BST::BST()
{
	root = nullptr;
}

int Node::degree(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int degree = 0;
	if (node->left)
	{
		degree++;
	}
	if (node->right)
	{
		degree++;
	}
	return degree;
}


bool BST::insert(int data)
{
	return insert(root, data);
}

bool BST::remove(int data)
{
	return remove(root, data);
}

bool BST::find(int data)
{
	return find(root, data);
}

void BST::inOrder(ostream& os)
{
	inOrder(root, os);
	os << endl;
}

void BST::preOrder(ostream& os)
{
	preOrder(root, os);
	os << endl;
}

void BST::postOrder(ostream& os)
{
	os << endl;
	postOrder(root, os);
	os << endl;
}

bool BST::insert(Node*& node, int data)
{
	if (node == nullptr)
	{
		node = new Node(data);
		return true;
	}
	if (data < node->data)
	{
		return insert(node->left, data);
	}
	if (data > node->data)
	{
		return insert(node->right, data);
	}
	return false;
}

bool BST::remove(Node *&node, int data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (data < node->data)
	{
		return remove(node->left, data);
	}
	if (data > node->data)
	{
		return remove(node->right, data);
	}

	int deg = node->degree(node);
	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	if (deg == 1)
	{
		Node* tmp = node;
		if (node->left != nullptr)
			node = node->left;
		else
			node = node->right;
		delete tmp;
	}
	else
	{
		Node* tmp = node->left;
		while (tmp->right != nullptr)
			tmp = tmp->right;
		node->data = tmp->data;
		remove(node->left, tmp->data);
	}
	return true;
}

bool BST::find(Node* node, int data)
{
	if (node == nullptr) return false;
	if (data < node->data)
	{
		return find(node->left, data);
	}
	if (data > node->data)
	{
		return find(node->right, data);
	}
	return true;
}

void BST::inOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	inOrder(node->left, os);
	os << node->data << " ";
	inOrder(node->right, os);
}

void BST::preOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	os << node->data << " ";
	preOrder(node->left, os);
	preOrder(node->right, os);
}

void BST::postOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	postOrder(node->left, os);
	postOrder(node->right, os);
	os << node->data << " ";
}
