/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* This program uses a tokenizer to test the tokenizer!
* A list of available functions and the format for them is available with the "help" command.
* An array of 5 tokenizers is held in main in order to allow the user to initialize default or string-defined tokenizers.
*/

#include "Tokenizer.h"
#include <iostream>

using std::cin;
using std::cout;
using std::getline;
using std::tolower;

int main()
{
	//Define tokenizers
	Tokenizer userIn;
	Tokenizer tokenizerArr[5];
	//Boolean value to loop menu
	bool menu = true;
	//A string for the user's input and a token variable for each gettable data type
	string rawIn, strToken;
	int intToken;
	double dblToken;
	//Intro message
	cout << "Welcome to Kyler's Tokenizer Class!\n<<UP TO 5 tokenizers can be stored.>>\nEnter \"help\" to see a full list of supported commands and their format!";
	//A while loop to continue taking input while the user hasn't entered "quit"
	while (menu)
	{
		cout << "\n\nUser >>>";
		getline(cin, rawIn);
		userIn.set(rawIn);
		//Read a word from user input, parsing through the line to interpret commands and operate the class.
		if (userIn.readWord(strToken))
		{
			//Branching else-if options to split the possible commands
			//Quit option
			if (strToken == "quit") { menu = false; }
			//Help option
			else if (strToken == "help")
			{
				cout << "Format of commands:\nWords in quotes are required verbatim; square brackets are decided by the user and are formatted as:\n[requirement level: required type: identifying name]\n\nList of Commands:\n";
				//Quit command to end execution
				cout << "\"quit\" to terminate\n";
				//Tokenizer commands to show default and string-input constructors
				cout << "\"addtokenizer [required: int: tokenizerID] [optional: string: data]\" to replace the data at tokenizerID with a new tokenizer.\n";
				cout << "\"clear [required: int: tokenizerID]\" to clear the stream of the tokenizer at tokenizerID.\n";
				cout << "\"reset [required: int: tokenizerID]\" to reset the tokenizer at tokenizerID to its previously input string.\n";
				cout << "\"set [required: int: tokenizerID] [required: string: data]\" to set a tokenizer's data based on its numerical index.\n";
				cout << "\"isEmpty [required: int: tokenizerID]\" to check if the tokenizer at tokenizerID has values left.\n";
				cout << "\"read [required: int: tokenizerID] [required: string: Data Type]\" to read data from the tokenizer at tokenizerID.\n";
				cout << "Recognizable Types include:\n\"word\" for a single string\n\"int\" for a single integer\n\"dbl\" for a single decimal\n\"rest\" for the remainder of the line";
			}
			//addtokenizer branch
			else if (strToken == "addtokenizer")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						if (userIn.readRest(strToken))
						{
							tokenizerArr[intToken] = Tokenizer(strToken);
							cout << "Tokenizer with data \"" << strToken <<  "\" added to index " << intToken;
						}
						else
						{
							tokenizerArr[intToken] = Tokenizer();
							cout << "Default tokenizer added to index " << intToken;
						}
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			//Clear branch
			else if (strToken == "clear")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						tokenizerArr[intToken].clear();
						cout << "The tokenizer at index " << intToken << " has been cleared.";
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			//Reset branch
			else if (strToken == "reset")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						tokenizerArr[intToken].reset();
						cout << "The tokenizer at index " << intToken << " has been reset.";
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			//Set branch
			else if (strToken == "set")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						if (userIn.readRest(strToken))
						{
							tokenizerArr[intToken].set(strToken);
							cout << "Tokenizer at index " << intToken << " set to have the data \"" << strToken << "\"";
						}
						else
						{
							cout << "No data found to give the tokenizer.";
						}
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			//isEmpty branch
			else if (strToken == "isEmpty")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						if (tokenizerArr[intToken].isEmpty())
						{
							cout << "The tokenizer at index " << intToken << " is empty. No more tokens can be read.";
						}
						else
						{
							cout << "The tokenizer at index " << intToken << " still has characters left. This may include whitespace.";
						}
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			//Read branch
			else if (strToken == "read")
			{
				if (userIn.readInt(intToken))
				{
					if (intToken < 5 && intToken > -1)
					{
						if (userIn.readWord(strToken))
						{
							if (strToken == "word")
							{
								if (tokenizerArr[intToken].readWord(strToken))
								{
									cout << "Read Word: \"" << strToken << "\"";
								}
								else
								{
									cout << "Failed to read a word from tokenizer at index " << intToken;
								}
							}
							else if (strToken == "int")
							{
								int temp = intToken; //save the intToken to tell user which index they accessed if it fails.
								if (tokenizerArr[intToken].readInt(intToken))
								{
									cout << "Read Integer: \"" << intToken << "\"";
								}
								else
								{
									cout << "Failed to read an integer from tokenizer at index " << temp;
								}
							}
							else if (strToken == "dbl")
							{
								if (tokenizerArr[intToken].readDouble(dblToken))
								{
									cout << "Read Double: \"" << dblToken << "\"";
								}
								else
								{
									cout << "Failed to read a double from tokenizer at index " << intToken;
								}
							}
							else if (strToken == "rest")
							{
								if (tokenizerArr[intToken].readRest(strToken))
								{
									cout << "Rest of Tokenizer: \"" << strToken << "\"";
								}
								else
								{
									cout << "Failed to read anything from tokenizer at index " << intToken;
								}
							}
							else
							{
								cout << "Invalid string for Data Type. Only case-sensitive strings \"word\", \"int\", \"dbl\", and \"rest\" will work.";
							}
						}
						else
						{
							cout << "Missing a string for Data Type.";
						}
					}
					else
					{
						cout << "Invalid integer for tokenizerID. Only IDs 0 through 4 are acceptable.";
					}
				}
				else
				{
					cout << "Missing an integer for tokenizerID.";
				}
			}
			else
			{
				cout << "Your input didn't contain a valid function. Use \"help\" for a list of functions. Functions are all case-sensitive.";
			}
		}
		else
		{
			cout << "Your input doesn't seem to contain any tokens...";
		}
	}
	return 0;
}