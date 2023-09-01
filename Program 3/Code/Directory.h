/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The Header file for my Directory class.
* Declares all necessary class methods and variables for Node and Directory (Combining "Class Member" and "Class BST")
* Integrates necessary commands with standard BST functions and structure
*/
#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

using std::string;
using std::ostream;
using std::ofstream;

class Node
{
public:
	//strings for username, firstname, lastname, and middlename
	string uName, fName, lName, mName;
	//ints for number wins and number losses
	int numW, numL;
	Node* left;
	Node* right;

	Node() : uName(""), fName(""), lName(""), mName(""), numW(0), numL(0), left(nullptr), right(nullptr) {}
	Node(string uName) : uName(uName), fName(""), lName(""), mName(""), numW(0), numL(0), left(nullptr), right(nullptr) {}
	Node(string uName, string fName, string lName, string mName, int numW, int numL) : uName(uName), fName(fName), lName(lName), mName(mName), numW(numW), numL(numL), left(nullptr), right(nullptr) {}

	int degree() const;
	friend ostream& operator<<(ostream &os, const Node& node);
};

//The BEAM Directory implemented as a BST
class Directory
{
private:
	Node* root;
	int size;
	bool insert(Node*& node, string uName, string fName, string lName, string mName, int numW, int numL);
	Node* find(Node*& node, string uName);
	bool remove(Node*& node, string uName);
	void inOrder(Node* node, ostream& os, const string& space);
	//void preOrder(Node* node, ostream& os, const string& space); //never used, so don't need pre and post!
	//void postOrder(Node* node, ostream& os, const string& space);
	void clear(Node*& node);

public:
	Directory() : root(nullptr), size(0) {}
	~Directory() { clear(root); root = nullptr; }
	//Could make insert, find, & remove
	bool insert(string uName) { return insert(root, uName, "", "", "", 0, 0); }
	Node* find(string uName) { return find(root, uName);  };
	bool remove(string uName) { return remove(root, uName); }
	void inOrder(ostream& os, const string& space) { inOrder(root, os, space); }
	//void preOrder(ostream& os, const string& space) { preOrder(root, os, space); }
	//void postOrder(ostream& os, const string& space) { postOrder(root, os, space);  }

	bool setName(string uName, string lName, string fName, string mName = "");
	bool setWins(string uName, int wins);
	bool setLosses(string uName, int losses);

	void save(ofstream &fout);
	bool display(string uName);
};