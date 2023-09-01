/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The Header file for my DirectoryAVL class.
* Declares all necessary class methods for "class AVL"; extends my Directory as public
* Integrates necessary commands with standard AVL functions and structure, adopting many of BST's functions
*/
#pragma once
#include "Directory.h"

using std::istream;

class DirectoryAVL : public Directory
{
private:
	void balance(Node*& node);
	void leftRotate(Node*& node);
	void rightRotate(Node*& node);
	int calcBF(Node* node);
	int updateHeight(Node* node);
	int getHeight(Node* node);

	bool insert(Node*& node, string uName, string fName, string lName, string mName, int numW, int numL, int height);
	bool remove(Node*& node, string uName);
public:
	~DirectoryAVL() { } //Even though this is empty, it automatically calls the parent destructor as well (thanks testing!)
	bool insert(string uName) { return insert(root, uName, "", "", "", 0, 0, 0); };
	bool remove(string uName) { return remove(root, uName); }
	bool load(istream &fin);
};