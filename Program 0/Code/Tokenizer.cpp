/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* This is the class file for the Tokenizer class.
* It defines the methods with which a programmer can parse a string of user text in order to interpret commands.
* Each getter function takes a variable by reference that stores the recieved token and returns a boolean value representing success.
*/
#include "Tokenizer.h"
#include <iostream>

using std::ios;
using std::ios_base;

Tokenizer::Tokenizer()
{
	ss.str(""); //set the stream to an empty string for good measure
	ss.exceptions(ios::failbit); //add failbit to exceptions for read failure
}

Tokenizer::Tokenizer(string str)
{
	ss.str(str); //set the stream to input string
	this->str = str; //set private str variable to keep string for reset
	ss.exceptions(ios::failbit); //add failbit to exceptions for read failure
}

void Tokenizer::clear()
{
	ss.clear(); //clear error bits just in case
	ss.str(""); //set the stream to an empty string in order to clear values
	str = ""; //clear the private string variable too
}

void Tokenizer::set(string str)
{
	ss.str(str); //set the stream to input string
	ss.clear(); //DEBUG RESULT!! clear error bits to avoid end-of-stream error bits carrying over
	this->str = str; //set private str variable to keep string for reset
}

bool Tokenizer::isEmpty()
{
	//boolean compare stream to empty string AND returns true if end-of-file is flagged (comparison doesn't work)
	try
	{
		return ss.str() == "" || ss.eof();
	}
	catch (ios_base::failure)
	{
		return true;
	}
}

bool Tokenizer::readWord(string& token)
{
	//Try-Catch peek so that if there aren't any readable characters, it won't try reading which would clear error bits and mess up "isEmpty"
	try { ss.peek(); }
	catch (ios_base::failure) { return false; }
	try
	{
		string x;
		ss >> x;
		if (x == "y") {} //try to compare the token to a string (doing nothing if true); if fail, it skips to catch
		token = x;
		return true;
	}
	catch (ios_base::failure)
	{
		ss.clear(); //clears error bits for future use
		return false;
	}
}

bool Tokenizer::readInt(int& token)
{
	//Try-Catch peek so that if there aren't any readable characters, it won't try reading which would clear error bits and mess up "isEmpty"
	try { ss.peek(); }
	catch (ios_base::failure) { return false; }
	try
	{
		int x;
		ss >> x;
		if (x == 0) {} //try to compare the token to an int (doing nothing if true); if fail, it skips to catch
		token = x;
		return true;
	}
	catch (ios_base::failure)
	{
		ss.clear(); //clears error bits for future use
		return false;
	}
}

bool Tokenizer::readDouble(double& token)
{
	//Try-Catch peek so that if there aren't any readable characters, it won't try reading which would clear error bits and mess up "isEmpty"
	try { ss.peek(); }
	catch (ios_base::failure) { return false; }
	try
	{
		double x;
		ss >> x;
		if (x == 1.2) {} //try to compare the token to a double (doing nothing if true); if fail, it skips to catch
		token = x;
		return true;
	}
	catch (ios_base::failure)
	{
		ss.clear(); //clears error bits for future use
		return false;
	}
}

bool Tokenizer::readRest(string& token)
{
	//Try-Catch peek so that if there aren't any readable characters, it won't try reading which would clear error bits and mess up "isEmpty"
	try { ss.peek(); }
	catch (ios_base::failure) { return false; }
	try
	{
		string x;
		getline(ss, x);
		if (x == "y") {} //try to compare the token to a string (doing nothing if true); if fail, it skips to catch
		token = x;
		return true;
	}
	catch (ios_base::failure)
	{
		ss.clear(); //clears error bits for future use
		return false;
	}
}

void Tokenizer::reset()
{
	//[debug] Clear flags so there isn't a false fail
	ss.clear();
	ss.str(this->str);
}