/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The cpp file for my Directory class.
* Defines all necessary class methods for Node and Directory (Combining "Class Member" and "Class BST")
* Integrates necessary commands with standard BST functions and structure
*/
#include "Directory.h"

int Node::degree() const
{
	int out = 0;
	if (this->left != nullptr) out++;
	if (this->right != nullptr) out++;

	return out;
}

bool Directory::insert(Node*& node, string uName, string fName, string lName, string mName, int numW, int numL, int height)
{
	if (node == nullptr)
	{
		node = new Node(uName, fName, lName, mName, numW, numL, height);
		size++;
		return true;
	}
	else if (uName > node->uName)
	{
		return insert(node->right, uName, fName, lName, mName, numW, numL, height);
	}
	else if (uName < node->uName)
	{
		return insert(node->left, uName, fName, lName, mName, numW, numL, height);
	}
	return false;
}

Node* Directory::find(Node*& node, string uName)
{
	if (node == nullptr)
		return node;
	else if (node->uName == uName)
		return node;
	else if (uName > node->uName)
		return find(node->right, uName);
	else if (uName < node->uName)
		return find(node->left, uName);

	//Shouldn't reach here, but if it does, return a default
	return nullptr;
}

bool Directory::remove(Node*& node, string uName)
{
	if (node == nullptr) //base case
	{
		return false;
	}
	else if (uName > node->uName)
	{
		return remove(node->right, uName);
	}
	else if (uName < node->uName)
	{
		return remove(node->left, uName);
	}
	
	int deg = node->degree();
	//delete (adjust children) based on degree
	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	else if (deg == 1)
	{
		Node* tmp = node;
		if (node->left != nullptr) //(the 1 child is left)
		{
			node = node->left;
		}
		else
		{ //the 1 child is right
			node = node->right;
		}
		delete tmp;
	}
	else //(deg == 2)
	{
		Node* tmp = node->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		//Move data (takes a bit)
		node->uName = tmp->uName;
		node->fName = tmp->fName;
		node->lName = tmp->lName;
		node->mName = tmp->mName;
		node->numW = tmp->numW;
		node->numL = tmp->numL;
		remove(node->left, tmp->uName);
	}
	size--;
	return true;
}

void Directory::inOrder(Node* node, ostream& os, const string& space)
{
	if (node == nullptr) return; //rule out empty traversals
	if(node->left != nullptr)
		inOrder(node->left, os, space);
	os << *node << space;
	if(node->right != nullptr)
		inOrder(node->right, os, space);
}

void Directory::preOrder(Node* node, ostream& os, const string& space)
{
	if (node == nullptr) return; //rule out empty traversals
	os << *node << space;
	if (node->left != nullptr)
		preOrder(node->left, os, space);
	if (node->right != nullptr)
		preOrder(node->right, os, space);
}

void Directory::postOrder(Node* node, ostream& os, const string& space)
{
	if (node == nullptr) return; //rule out empty traversals
	if (node->left != nullptr)
		postOrder(node->left, os, space);
	if (node->right != nullptr)
		postOrder(node->right, os, space);
	os << *node << space;
}

void Directory::clear(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}
	//Post-Order traversal of deletions
	if (node->left != nullptr)
		clear(node->left);
	if (node->right != nullptr)
		clear(node->right);
	size--;
	delete node;
}

bool Directory::setName(string uName, string lName, string fName, string mName)
{
	Node* node = find(uName);
	if (node == nullptr) //not found
	{
		return false;
	}
	node->fName = fName;
	node->lName = lName;
	node->mName = mName;
	return true;
}

bool Directory::setWins(string uName, int wins)
{
	Node* node = find(uName);
	if (node == nullptr) //not found
	{
		return false;
	}
	node->numW = wins;
	return true;
}

bool Directory::setLosses(string uName, int losses)
{
	Node* node = find(uName);
	if (node == nullptr) //not found
	{
		return false;
	}
	node->numL = losses;
	return true;
}

void Directory::save(ofstream& fout)
{
	fout << size << "\n";
	inOrder(fout, "");
}

bool Directory::display(string uName)
{
	Node* node = find(uName);
	if (node != nullptr)
	{
		std::cout << "\n" << *node;
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Node& node)
{
	os << node.uName << "\n";
	os << node.lName << ", " << node.fName << " " << node.mName << "\n";
	os << node.numW << " " << node.numL << "\n";
	return os;
}