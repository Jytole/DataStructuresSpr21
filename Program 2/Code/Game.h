/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* Program Description:
* The header file of my Game class.
* Implements support for all necessary functions of a Bingo game.
* Implements an additional Card class.
*/
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <ostream>

using std::string;
using std::ostream;

class Card
{
public:
	string user;
	int seed;
	int cells[5][5]; //0-4 = B, 5-9 = I, 10-13 = N, 14-18 = G, 19-23 = O
	bool marks[5][5]; //same indeces as cells -- middle is always true (true = marked)

	Card(int seed);
	bool testBingo();

	//operator overload to print a card with any marks
	friend ostream &operator<<(ostream& os, const Card& card);
};

//Data structure of accounts
//"class Bingo"
class Game
{
public:
	std::vector<Card> cards;
	std::vector<string> users;

	Game() {};
	//prints the cards with marks from a user
	bool printUser(string user);
	void printCard(int card);
	void print();
	void newGame();
	bool mark(int cell);
	bool addUser(string user);
	bool addCard(int card, string user);
	bool delUser(string user);
	bool delCard(int card);
};