/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* This is the header file for the Tokenizer class.
* It provides signatures for each method used in the tokenizer class.
*/
#pragma once
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Tokenizer
{
private:
	string str;
	stringstream ss;
public:
	//Creates a default instance of the class
	Tokenizer();
	//Creates an instance of the class using a string
	Tokenizer(string str);
	//Clears the string being used: sets to empty string
	void clear();
	//Sets the string to be tokenized: sets to input
	void set(string str);
	//Checks if the stringstream is empty
	bool isEmpty();
	//Reads a word from the string
	bool readWord(string& token);
	//Reads and integer from the string
	bool readInt(int& token);
	//Reads a double from the string
	bool readDouble(double& token);
	//Reads the remaining string
	bool readRest(string &string);
	//Resets the stream to initial string value
	void reset();
};