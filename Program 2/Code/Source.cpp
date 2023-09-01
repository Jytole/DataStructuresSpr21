/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The Main file of execution for the usage of my Game class.
* Borrowed and edited from Professor Knight's original Tokenizer example class.
* Controls the flow of the program through the Tokenizer and Game classes to play Bingo.
*/
#include "Game.h"
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
	// display ... displays the seeds of cards given to each <user>
	// display user <user> ... displays the contents and marks of cards given to <user>
	// display card <card> ... displays the card with any marks associated with the seed <card>
	// new game ... resets the game of bingo by clearing all cards' marks
	// mark <cell> ... marks <cell> on all cards in play
	// add user <user> ... adds <user> to the vector of users in Game game
	// add card <card> to <user> ... adds card with seed <card> to <user>
	// remove user <user> ... removes <user> and all cards associated with <user>
	// remove card <card> ... removed the card with seed <card> from play
	string line;
	string command;
	string token1, token2, token3;
	int itoken1;
	Tokenizer tkn;
	Game game;
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
			//user or card
			if (tkn.readWord(token1))
			{
				if (token1 == "card")
				{
					if (tkn.readInteger(itoken1)) //display card
					{
						game.printCard(itoken1); //can't fail
					}
					else //error reading <card>
					{
						cout << "Missing integer for <card>\n";
					}
				}
				else if (token1 == "user")
				{
					if (tkn.readWord(token2)) //display user
					{
						if (!game.printUser(token2)) //error reading user
						{
							cout << "User " << token2 << " does not exist!\n";
						}
					}
					else //error reading <user>
					{
						cout << "Missing string for <user>\n";
					}
				}
				else //error reading display
				{
					cout << "Invalid display function. Only display, display card, and display user are supported.\n";
				}
			}
			else //display
			{
				game.print();
			}
		}
		else if (command == "new")
		{
			if (tkn.readWord(token1))
			{
				if (token1 == "game") //new game
				{
					game.newGame(); //can't fail
					cout << "New game started!\n";
				}
				else //error reading new
				{
					cout << "Invalid command. Only \"game\" is recognized after \"new\".\n";
				}
			}
			else //error reading new
			{
				cout << "Invalid command. Only \"game\" is recognized after \"new\".\n";
			}
		}
		else if (command == "mark")
		{
			if (tkn.readInteger(itoken1))
			{
				if (itoken1 > 0 && itoken1 < 76) //mark <cell>
				{
					game.mark(itoken1);
				}
				else //bad cell!
				{
					cout << "Invalid <cell>. Only integers between 1 and 75 are accepted.\n";
				}
			}
			else //bad cell!
			{
				cout << "Invalid <cell>. Only integers between 1 and 75 are accepted.\n";
			}
		}
		else if (command == "add")
		{
			if (tkn.readWord(token1))
			{
				if (token1 == "user")
				{
					//<user>
					if (tkn.readWord(token2)) //add user <user>
					{
						if (!game.addUser(token2)) //user already exists
						{
							cout << "User " << token2 << " already exists! Nothing changed.\n";
						}
						else //user successfully added!
						{
							cout << "User " << token2 << " successfully added!\n";
						}
					}
					else //error reading <user>
					{
						cout << "Missing string for <user>.\n";
					}
				}
				else if (token1 == "card")
				{
					//<card>
					if (tkn.readInteger(itoken1))
					{
						//to
						if (tkn.readWord(token2))
						{
							if (token2 == "to")
							{
								//<user>
								if (tkn.readWord(token3))//add card to user
								{
									if (game.addCard(itoken1, token3)) //card successfully added!
									{
										cout << "Card " << itoken1 << " successfully given to " << token3 << "\n";
									}
									else //either the card is already in play or the user doesn't exist
									{
										cout << "Failed to add card.\n";
									}
								}
								else //error reading <user>
								{
									cout << "Missing string for <user>.\n";
								}
							}
							else //error reading to <user>
							{
								cout << "Missing \"to\" after <card>.\n";
							}
						}
						else //error reading to <user>
						{
							cout << "Missing \"to\" after <card>.\n";
						}
					}
					else //error reading <card>
					{
						cout << "Missing integer for <card>.\n";
					}
				}
				else //error reading add
				{
					cout << "Invalid command. Only \"user\" and \"card\" are recognized after \"add\".\n";
				}
			}
			else //error reading add
			{
				cout << "Invalid command. Only \"user\" and \"card\" are recognized after \"add\".\n";
			}
		}
		else if (command == "remove")
		{
			if (tkn.readWord(token1))
			{
				if (token1 == "user")
				{
					//<user>
					if (tkn.readWord(token2)) //remove user
					{
						if (game.delUser(token2)) //user successfully found and removed
						{
							cout << "User " << token2 << " successfully removed!\n";
						}
						else //no such user exists!
						{
							cout << "User " << token2 << " was not found.\n";
						}
					}
					else //error reading <user>
					{
						cout << "Missing string for <user>.\n";
					}
				}
				else if (token1 == "card")
				{
					//<card>
					if (tkn.readInteger(itoken1)) //remove card
					{
						if (game.delCard(itoken1)) //found and removed <card>
						{
							cout << "Card " << itoken1 << " successfully removed!\n";
						}
						else //no such <card> exists!
						{
							cout << "Card " << itoken1 << " was not found.\n";
						}
					}
					else //error reading <card>
					{
						cout << "Missing integer for <card>.\n";
					}
				}
				else //error reading remove
				{
					cout << "Invalid command. Only \"user\" and \"card\" are recognized after \"remove\".\n";
				}
			}
			else //error reading remove
			{
				cout << "Invalid command. Only \"user\" and \"card\" are recognized after \"remove\".\n";
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
