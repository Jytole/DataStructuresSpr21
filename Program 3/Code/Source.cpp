/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The Main file of execution for the usage of my Directory class.
* Borrowed and edited from Professor Knight's original Tokenizer example class.
* Controls the flow of the program through the tokenizer and Directory classes
*/
#include "Directory.h"
#include "Tokenizer.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;

//Takes in text from the given stream ("is") and tests it for commands, executing List class functions.
bool processText(istream& is, bool usingFile = false)
{
	// implement support for 
	// exit ... exit the program
	// load file ... loads a file containing supported commands
	// save file ... saves the current directory to a file
	// directory ... displays the current directory
	// display member ... displays the data related to a given member
	// clear ... clears the current directory of all members
	// add member ... inserts a member into the directory
	// set member name last first middle ... sets the member's name; middle is optional
	// set member wins wins ... sets the member's wins
	// set member losses losses ... sets the member's losses
	// remove member ... removed the member from the directory
	string line;
	string command;
	string token1, token2, token3, token4, token5;
	int itoken1;
	Tokenizer tkn;
	Directory dir;
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
		else if (command == "save")
		{
			if (!tkn.readWord(token1)) {
				cout << "Missing file name\n";
				continue; // skip back to the top of the read loop
			}
			ofstream fout;
			fout.open(token1);
			dir.save(fout);
			cout << "Successfully saved directory to the file " << token1 << "\n";
		}
		else if (command == "directory")
		{
			cout << "\nEach entry has the following format:\nMember ID\nLast, First Middle\nWins Losses\n\n";
			dir.inOrder(cout, "\n");
		}
		else if (command == "display")
		{
			if (tkn.readWord(token1))
			{
				if (!dir.display(token1))
				{
					cout << "Failed to find " << token1 << " for display\n";
				}
			}
			else
			{
				cout << "Missing string for <member>\n";
			}

		}
		else if (command == "clear")
		{
			//call deconstructor instead of making an arbitrary "clear" method
			dir.~Directory();
			cout << "Cleared the directory\n";
		}
		else if (command == "add")
		{
			if (tkn.readWord(token1))
			{
				dir.insert(token1);
				cout << "Added user " << token1 << "\n";
			}
			else
			{
				cout << "Missing string for <member>\n";
			}

		}
		else if (command == "set")
		{
			if (tkn.readWord(token1)) //<member>
			{
				if (tkn.readWord(token2)) //variable being set
				{
					if (token2 == "name")
					{
						if (tkn.readWord(token3)) //<last>
						{
							if (tkn.readWord(token4)) //<first>
							{
								if (tkn.readWord(token5)) //<middle> (optional)
								{
									if (dir.setName(token1, token3, token4, token5))
									{
										cout << "Successfully set name of \"" << token1 << "\"\n";
									}
									else
									{
										cout << "Failed to set name of \"" << token1 << "\"\n";
									}
								}
								else
								{
									if (dir.setName(token1, token3, token4))
									{
										cout << "Successfully set name of \"" << token1 << "\"\n";
									}
									else
									{
										cout << "Failed to set name of \"" << token1 << "\"\n";
									}
								}
							}
							else
							{
								cout << "Expected a string for <last>\n";
							}
						}
						else
						{
							cout << "Expected a string for <first>\n";
						}
					}
					if (token2 == "wins")
					{
						if (tkn.readInteger(itoken1)) //<wins>
						{
							if (dir.setWins(token1, itoken1))
							{
								cout << "Successfully set the wins of \"" << token1 << "\"\n";
							}
							else
							{
								cout << "Failed to set the wins of \"" << token1 << "\"\n";
							}
						}
						else
						{
							cout << "Expected an integer for <wins>\n";
						}
					}
					if (token2 == "losses")
					{
						if (tkn.readInteger(itoken1)) //<losses>
						{
							if (dir.setLosses(token1, itoken1))
							{
								cout << "Successfully set the losses of \"" << token1 << "\"\n";
							}
							else
							{
								cout << "Failed to set the losses of \"" << token1 << "\"\n";
							}
						}
						else
						{
							cout << "Expected an integer for <losses>\n";
						}
					}
				}
				else
				{
					cout << "Expected string for desired set type. Only \"name\", \"wins\", and \"losses\" are accepted\n";
				}
			}
			else
			{
				cout << "Missing string for <member>\n";
			}
		}
		else if (command == "remove")
		{
			if(tkn.readWord(token1))
			{
				if (dir.remove(token1))
				{
					cout << "Successfully removed member " << token1 << "\n";
				}
				else
				{
					cout << "Failed to find " << token1 << " for removal\n";
				}
			}
			else
			{
				cout << "Missing string for <member>\n";
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
