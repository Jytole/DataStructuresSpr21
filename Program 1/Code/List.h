/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The header file for my List class including declarations for the Node and List classes.
* The Node allows for the storage of the id and priority, as well as a next and previous variable.
* The List allows for finding, removing, and adding nodes as well as printing and clearing the list.
* The List is implemented to be doubly linked and utilizes shared pointers.
*/
#pragma once
#include <string>
#include <memory>

class Node;
using std::string;
using node_ptr = std::shared_ptr<Node>;
using std::ostream;

class Node
{
public:
	string id;
	int priority;
	node_ptr next;
	node_ptr prev;
	Node() : id(""), priority(0), next(nullptr), prev(nullptr) {}
	Node(string id) : id(id), priority(0), next(nullptr), prev(nullptr) {}
	Node(string id, int priority) : id(id), priority(priority), next(nullptr), prev(nullptr) {}
	Node(string id, int priority, node_ptr next) : id(id), priority(priority), next(next), prev(nullptr) {}
	Node(string id, int priority, node_ptr next, node_ptr prev) : id(id), priority(priority), next(next), prev(prev) {}

	friend ostream &operator<<(ostream& os, const Node &right);
};

class List
{
private:
	node_ptr head;
	node_ptr tail;
public:
	List() : head(nullptr), tail(nullptr) {};
	~List();//make sure there's nothing pointing to anything left (auto-deletion only deletes the head, smart pointer means prev pointer keeps nodes alive)
	
	void printPos(); // display forward: displays full list from head to tail
	void printNeg(); // display backward: displays full list from tail to head
	bool find(const string &loc, int &priority); // find an event based on string loc; assign priority for return message
	bool remove(const string &loc); // find and remove an event based on string loc; return false is fail
	bool insertBef(const string &id, const int &priority, const string &loc); // insert an item before the item with the given id with data values priority and loc
	bool insertAft(const string &id, const int &priority, const string &loc); // insert an item after the item with the given id with data values priority and loc
};