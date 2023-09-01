/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The cpp file for my DirectoryAVL class.
* Defines all necessary class methods for "class AVL"; extends my Directory as public
* Integrates necessary commands with standard AVL functions and structure, adopting many of BST's functions
*/
#include "DirectoryAVL.h"
#include "Tokenizer.h"

//Calculates the Balance Factor given a node pointer
//Uses the getHeight method to get height of node's children
//Balance Factor is just those subtracted
int DirectoryAVL::calcBF(Node* node)
{
	//If node is nullptr, balance factor is always 0
	if (node == nullptr)
	{
		return 0;
	}
	return (getHeight(node->left) - getHeight(node->right));
}

//Calculates the updated height of a node, does not assign it to anything
//Intended in tandem with "getHeight" so that functions that require a retrieval of height can utilize the height variables 
//rather than always wasting resources calculating height
int DirectoryAVL::updateHeight(Node* node)
{
	//In this class's height system, a null node is height of -1
	if (node == nullptr)
	{
		return -1;
	}
	//Use getHeight and compare left and right height
	int lHeight = getHeight(node->left);
	int rHeight = getHeight(node->right);
	return (rHeight > lHeight ? rHeight : lHeight) + 1;
}

//Gets the height of a node, allowing nullptr's as arguments
//This allows a function to never need test for nullptr defaults when dealing with height
int DirectoryAVL::getHeight(Node* node)
{
	//In this class's height system, a null node is height of -1
	if (node == nullptr)
	{
		return -1;
	}
	//If it's not a nullptr, there is some value from when the node was last messed with
	return node->height;
}

//Balances a node based on the balance factor of that node
//Rotates if the node is 2 away from a 0 balance factor
void DirectoryAVL::balance(Node*& node)
{
	int BF = calcBF(node);
	//Right is heavier -> left rotate
	if (BF < -1)
	{
		//Check for double rotate
		if (calcBF(node->right) > 0)
		{
			rightRotate(node->right);
		}
		leftRotate(node);
	}
	//Left is heavier -> right rotate
	else if (BF > 1)
	{
		//Check for double rotate
		if (calcBF(node->left) < 0)
		{
			leftRotate(node->left);
		}
		rightRotate(node);
	}
	return;
}

//Rotates a node set left; intended to achieve AVL balance
void DirectoryAVL::leftRotate(Node*& node)
{
	Node* right = node->right;
	Node* tmp = right->left;
	right->left = node;
	node->right = tmp;
	node->height = updateHeight(node);
	right->height = updateHeight(right);
	node = right;
}

//Rotates a node set right; intended to achieve AVL balance
void DirectoryAVL::rightRotate(Node*& node)
{
	Node* left = node->left;
	Node* tmp = left->right;
	left->right = node;
	node->left = tmp;
	node->height = updateHeight(node);
	left->height = updateHeight(left);
	node = left;
}

//Inserts a node with all possible data
//Updates height and balances each node with the help of stack properties
//After each call finishes the child case, it updates height and checks balance
bool DirectoryAVL::insert(Node*& node, string uName, string fName, string lName, string mName, int numW, int numL, int height)
{
	bool stat = false;
	if (node == nullptr) //default case: insert spot is open, return true
	{
		node = new Node(uName, fName, lName, mName, numW, numL, height);
		size++;
		return true;
	}
	else if (uName > node->uName) //Node target spot is to the right
	{
		stat = insert(node->right, uName, fName, lName, mName, numW, numL, height);
	}
	else if (uName < node->uName) //Node target spot is to the left
	{
		stat = insert(node->left, uName, fName, lName, mName, numW, numL, height);
	}
	if(!stat) return false; //no need to update things if nothing changed

	node->height = updateHeight(node); //Update node's height (inherently moving up the call stack)
	balance(node);
	return true;
}

bool DirectoryAVL::remove(Node*& node, string uName)
{
	bool stat = false;
	if (node == nullptr) //base case
	{
		return false;
	}
	else if (uName > node->uName) //Target is to the right
	{
		stat = remove(node->right, uName); //store stat
		node->height = updateHeight(node); //update height & balance in all cases
		balance(node);
		return stat;
	}
	else if (uName < node->uName) //Target is to the left
	{
		stat = remove(node->left, uName);
		node->height = updateHeight(node); //update height & balance in all cases
		balance(node);
		return stat;
	}

	node->height = updateHeight(node); //update height & balance (just to be safe.. probably unnecessary)
	balance(node);

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
		node->height = updateHeight(node);
		balance(node);
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
		node->height = updateHeight(node);
		balance(node);
	}
	size--;
	return true;
}

//Load a directory from a file
//If members are already in the directory, they remain and these members just get added in
bool DirectoryAVL::load(istream& fin)
{
	//Uses a tokenizer to parse each line
	Tokenizer tkn;
	int mem, numL, numW;
	string rawString, uName, rawName, fName, mName, lName;
	bool stat = false;
	//Use rawString to hold each line, give it to the tokenizer
	std::getline(fin, rawString);
	tkn.setString(rawString);
	if (tkn.readInteger(mem))//Make sure we can get the member quantity integer
	{
		while (mem != 0) //keep looping while there's members left to add
		{
			//Grab the data from the file, break if any of it is missing
			std::getline(fin, rawString);
			tkn.setString(rawString); //member ID line
			if (!tkn.readWord(uName))
			{
				break;
			}
			std::getline(fin, rawString);
			tkn.setString(rawString); //member name line
			if (!tkn.readLine(rawName))
			{
				break;
			}
			std::getline(fin, rawString);
			tkn.setString(rawString); //member wins / losses line
			if (!tkn.readInteger(numW))
			{
				break;
			}
			if (!tkn.readInteger(numL))
			{
				break;
			}
			//Split rawName into fName, lName, mName, using them as char pointers
			fName = "", lName = "", mName = "";
			
			//Fix for warning C4018 (lines 248, 253, 258) from Visual Studio tooltip: 
		    //https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4018#remarks
			unsigned int i = 0;
			for(; i < rawName.size() && rawName[i] != ','; i++) //lName
			{
				lName += rawName[i];
			}
			i += 2; //skip the comma and space combo
			for (; i < rawName.size() && rawName[i] != ' '; i++) //fName
			{
				fName += rawName[i];
			}
			i++; //skip the space (doesn't mess it up if already passed size)
			for (; i < rawName.size(); i++) //mName
			{
				mName += rawName[i];
			}
			insert(root, uName, fName, lName, mName, numW, numL, 0);
			stat = true; //we added a member, so we loaded *something*!
			mem--; //decrement members left
		}
	}
	//returns true if any member was added; nothing is stated if one in the middle fails
	return stat;
}