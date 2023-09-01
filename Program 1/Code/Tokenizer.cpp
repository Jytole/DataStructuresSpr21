/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The cpp file for Professor Knight's Tokenizer class.
* Allows for a string to be read token by token as a stream.
*/
#include "Tokenizer.h"

void Tokenizer::setString(const string& str)
{
	ss.str(str);
	ss.clear();
}
bool Tokenizer::isEmpty() const
{
	if (ss.eof()) return true;
	return false;
}
bool Tokenizer::readLine(string& line)
{
	if (isEmpty()) return false;
	if (getline(ss, line)) return true;
	return false;
}
bool Tokenizer::readInteger(int& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readWord(string& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readDouble(double& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}

bool Tokenizer::readChar(char& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}

void Tokenizer::rewind()
{
	ss.seekg(0, ss.beg);
}
void Tokenizer::clear()
{
	setString("");
	ss.setstate(std::ios::eofbit);
}