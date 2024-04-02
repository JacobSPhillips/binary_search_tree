#pragma once
class Node
{
public:
	int data;
	Node* right;
	Node* left;

	Node()
	{
		data = 0;
		right = nullptr;
		left = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
	}

	int degree(Node* node);
};

