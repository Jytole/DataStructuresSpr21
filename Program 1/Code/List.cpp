/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The cpp file for my List class including declarations for the Node and List classes.
* The Node allows for the storage of the id and priority, as well as a next and previous variable.
* The List allows for finding, removing, and adding nodes as well as printing and clearing the list.
* The List is implemented to be doubly linked and utilizes shared pointers.
*/
#include "List.h"
#include <iostream>

using std::cout;

//Deconstructor (doubles as clear)
//When a smart pointer stops pointing to an element, it gets deallocated, so
//this goes through the list and changes all the pointers that point to any element to nullptr
List::~List()
{
	while (head != nullptr)
	{
		node_ptr tmp = head;	//save head for reference pointing
		head = head->next;		//move head 
		tmp->prev = nullptr;	//remove [old head]'s prev & next pointers
		tmp->next = nullptr;
	}
	//tmp gets deleted when it leaves scope, deleting the remaining list element
	tail = nullptr;
}

//Prints the list from head to tail
void List::printPos()
{
	if (head == nullptr) //empty error message
	{
		cout << "Empty List!\n";
		return;
	}
	node_ptr tmp = head;
	while (tmp != nullptr)
	{
		cout << *tmp << "\n";
		tmp = tmp->next;
	}
	return;
}

//Prints the list from tail to head
void List::printNeg()
{
	if (head == nullptr) //empty error message
	{
		cout << "Empty List!\n";
		return;
	}
	node_ptr tmp = tail;
	while (tmp != nullptr)
	{
		cout << *tmp << "\n";
		tmp = tmp->prev;
	}
	return;
}

//Searches for an element in the list with the id string <loc>
//Assigns <priority> to the int passed by reference and returns true if found
//Otherwise, returns false
bool List::find(const string &loc, int &priority)
{
	if (head == nullptr) //don't try accessing elements if empty
	{
		return false;
	}
	node_ptr tmp = head;
	while (tmp != nullptr) //search through the elements
	{
		if (loc == tmp->id)
		{
			priority = tmp->priority; //assign priority as extra output
			return true;
		}
		tmp = tmp->next;
	}
	return false; //default return false
}

//Searches for an element in the list with the loc string as id
//Removes it and returns true if found
//Otherwise, returns false
bool List::remove(const string &loc)
{
	if (head == nullptr) //don't try accessing elements if empty
	{
		return false;
	}
	node_ptr tmp = head;
	while (tmp != nullptr)
	{
		//search elements like in find
		if (loc == tmp->id)
		{
			//if so, test if tmp is head or tail and move pointers accordingly
			if (tmp == head)
			{
				head = tmp->next;
			}
			else
			{
				tmp->prev->next = tmp->next;
			}
			if (tmp == tail)
			{
				tail = tmp->prev;
			}
			else
			{
				tmp->next->prev = tmp->prev;
			}
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

//Inserts a Node into the list containing the id <id> and priority <priority>
//inserts the node before the element with id <loc>
bool List::insertBef(const string &id, const int &priority, const string &loc)
{
	if (id == "!HEAD!" || id == "!TAIL!") //display error message for reserved flags
	{
		cout << "Invalid event! !HEAD! and !TAIL! are reserved event titles. "; //Don't end line so that every command's output is only 1 line
		return false;
	}
	if (priority < 0 || priority > 100) //display error message for bad priority
	{
		cout << "Invalid priority! Only values between 1 and 100 are accepted. "; //Don't end line so that every command's output is only 1 line
		return false;
	}
	if (loc == "!HEAD!") //if the flag is used as the proper parameter, do the proper location inserting
	{
		if (head == nullptr) //if the list is empty, don't try to access its elements; just assign tail
		{
			head = std::make_shared<Node>(id, priority);
			tail = head;
			return true;
		} //all other cases of !HEAD!
		head->prev = std::make_shared<Node>(id, priority, head);
		head = head->prev;
		return true;
	}
	if (loc == "!TAIL!") //if the flag is used as the proper parameter, do the proper location inserting
	{
		if (tail == nullptr) //if the list is empty, don't try to access its elements; just assign head
		{
			tail = std::make_shared<Node>(id, priority);
			head = tail;
			return true;
		}
		if (head == tail) //if there's one element
		{
			head = std::make_shared<Node>(id, priority, tail);
			tail->prev = head;
			return true;
		} //all other cases of !TAIL!
		tail->prev->next = std::make_shared<Node>(id, priority, tail, tail->prev);
		tail->prev = tail->prev->next;
		return true;
	}
	node_ptr tmp = head;
	while (tmp != nullptr) //search and insert
	{
		if (loc == tmp->id)
		{
			if (tmp == head)
			{
				head = std::make_shared<Node>(id, priority, tmp);
				tmp->prev = head;
				return true;
			}
			tmp->prev->next = std::make_shared<Node>(id, priority, tmp, tmp->prev);
			tmp->prev = tmp->prev->next;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

//Inserts a Node into the list containing the id <id> and priority <priority>
//inserts the node after the element with id <loc>
bool List::insertAft(const string &id, const int &priority, const string &loc)
{
	if (id == "!HEAD!" || id == "!TAIL!") //display error message for reserved flags
	{
		cout << "Invalid event! !HEAD! and !TAIL! are reserved event titles. "; //Don't end line so that every command's output is only 1 line
		return false;
	}
	if (priority < 0 || priority > 100) //display error message for bad priority
	{
		cout << "Invalid priority! Only values between 1 and 100 are accepted. "; //Don't end line so that every command's output is only 1 line
		return false;
	}
	if (loc == "!HEAD!") //if the flag is used as the proper parameter, do the proper location inserting
	{
		if (head == nullptr) //if the list is empty, don't try to access its elements and assign tail
		{
			head = std::make_shared<Node>(id, priority);
			tail = head;
			return true;
		}
		if (head == tail) //if there's only one element
		{
			tail = std::make_shared<Node>(id, priority, nullptr, head);
			head->next = tail;
			return true;
		} //all other cases of !HEAD!
		head->next->prev = std::make_shared<Node>(id, priority, head->next, head);
		head->next = head->next->prev;
		return true;
	}
	if (loc == "!TAIL!") //if the flag is used as the proper parameter, do the proper location inserting
	{
		if (tail == nullptr) //if the list is empty, don't try to access its elements and assign head
		{
			tail = std::make_shared<Node>(id, priority);
			head = tail;
			return true;
		} //all other cases of !TAIL!
		tail->next = std::make_shared<Node>(id, priority, nullptr, tail);
		tail = tail->next;
		return true;
	}
	node_ptr tmp = head;
	while (tmp != nullptr) //search and insert
	{
		if (loc == tmp->id)
		{
			if (tmp == tail)
			{
				tail = std::make_shared<Node>(id, priority, nullptr, tmp);
				tmp->next = tail;
				return true;
			}
			tmp->next->prev = std::make_shared<Node>(id, priority, tmp->next, tmp);
			tmp->next = tmp->next->prev;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

//Overloads the insertion operator to allow a node to be printed straight
ostream &operator<<(ostream &os, const Node &right)
{
	os << "Event: " << right.id << ", Priority: " << right.priority;
	return os;
}