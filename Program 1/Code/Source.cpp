/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The Main file of execution for the usage of my List class.
* Borrowed and edited from Professor Knight's original Tokenizer example class.
* Controls the flow of the program through the tokenizer and List classes
*/
#include "List.h"
#include "Tokenizer.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ifstream;

//Takes in text from the given stream ("is") and tests it for commands, executing List class functions.
bool processText(istream& is, bool usingFile = false)
{
	// implement support for 
	// exit ... exit the program
	// load file ... loads a file containing supported commands
	// display forward ... displays the contents of the list from head to tail
	// display backward ... displays the contents of the list from tail to head
	// find loc ... finds the specified event, displays its priority
	// remove loc ... removes the specified event
	// clear ... clears the list of events
	// insert <event> <priority> before <loc> ... inserts the specified event immediately before loc
	// insert <event> <priority> after <loc> ... inserts the specified event immediately after loc
	string line;
	string command;
	string token1, token2, token3;
	int itoken1;
	Tokenizer tkn;
	List lst;
	while (true)
	{
		//Start by checking if in file or user-input mode
		if (usingFile)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }//prompt user if needed

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);//Read the first word in the line as "command" and see if it matches any commands
		if (command == "exit")
		{
			cout << "Exiting ...\n";
			return false;
		}
		else if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(token1)) {
				cout << "Missing file name\n";
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(token1);
			if (fin.is_open())
			{
				status = processText(fin, true);
			}
			else { cout << "Failed to open the file\n"; }
			fin.close();
			if (!status) return false;
		}
		else if (command == "display")
		{
			if (tkn.readWord(token1))
			{
				if (token1 == "forward") 
				{ 
					lst.printPos();
				}
				else if (token1 == "backward") 
				{ 
					lst.printNeg(); 
				}
				else
				{
					cout << "Expected a string for \"forward\" or \"backward\"\n";
				}
			}
			else
			{
				cout << "Missing a string for \"forward\" or \"backward\"\n";
			}
		}
		else if (command == "find")
		{
			//read event
			if (tkn.readWord(token1))
			{
				if (lst.find(token1, itoken1))
				{
					cout << "Priority: " << itoken1 << "\n";
				}
				else
				{
					cout << "Failed to find event \"" << token1 << "\"\n";;
				}
			}
			else //error on event
			{
				cout << "Missing an event string to search for\n";
			}
		}
		else if (command == "remove")
		{
			//read event
			if (tkn.readWord(token1))
			{
				if (lst.remove(token1))
				{
					cout << "Successfully removed event \"" << token1 << "\"\n";
				}
				else
				{
					cout << "Failed to find event \"" << token1 << "\" for removal\n";
				}
			}
			else //error on event
			{
				cout << "Missing an event string to search for deletion";
			}
		}
		else if (command == "clear")
		{
			//call deconstructor instead of making an arbitrary "clear" method
			lst.~List();
			cout << "Cleared the list of all items\n";
		}
		else if (command == "insert")
		{
			//read event
			if (tkn.readWord(token1))
			{
				//read priority
				if (tkn.readInteger(itoken1))
				{
					//read before / after
					if (tkn.readWord(token2))
					{
						if (token2 == "before")
						{
							//read loc
							if (tkn.readWord(token3))
							{
								if (lst.insertBef(token1, itoken1, token3))
								{
									cout << "Successfully inserted event before \"" << token3 << "\"\n";
								}
								else
								{
									cout << "Failed to insert event before \"" << token3 << "\"\n";
								}
							}
							else //error on loc
							{
								cout << "Missing an loc string to search for\n";
							}
						}
						else if (token2 == "after")
						{
							//loc
							if (tkn.readWord(token3))
							{
								if (lst.insertAft(token1, itoken1, token3))
								{
									cout << "Successfully inserted event after \"" << token3 << "\"\n";
								}
								else
								{
									cout << "Failed to insert event after \"" << token3 << "\"\n";
								}
							}
							else //error on loc
							{
								cout << "Missing an loc string to search for\n";
							}
						}
						else //error on before / after
						{
							cout << "Expected string for \"before\" or \"after\"\n";
						}
					}
				}
				else //error on priority
				{
					cout << "Expected integer for priority\n";
				}
			}
			else //error on event
			{
				cout << "Expected string for event\n";
			}
		}
		else //error reading command
		{
			cout << "No valid command found to start the line\n";
		}
	}
}

//calls a user-controlled instance of processText to be terminated only when exit is called somewhere
int main()
{
	processText(cin);
	return 0;
}
