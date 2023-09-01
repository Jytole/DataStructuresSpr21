/*
* Student Name: 	Kyler Smith
* Student NetID:	kss445
* Compiler Used:	Visual Studio (MSVC)
* The cpp file of my Game class. 
* Implements support for all necessary functions of a Bingo game.
* Implements an additional Card class.
*/
#include "Game.h"
#include <random>
#include <iostream>

using std::cout;

//Generates a card based on seed
//Stores the card's marks and cells in 2 different matrices, [row][column]
Card::Card(int seed)
{
	this->seed = seed;
	std::minstd_rand0 gen;
	gen.seed(seed);
	int tmp;
	//B
	for (int i = 0; i < 5; i++)
	{
		tmp = gen() % 15 + 1;
		//rule out duplicates
		for (int j = 0; j < i; j++)
		{
			if (tmp == cells[j][0])
			{
				tmp = gen() % 15 + 1;
				j = -1;
			}
		}
		cells[i][0] = tmp;
		marks[i][0] = false;
	}
	//I
	for (int i = 0; i < 5; i++)
	{
		tmp = gen() % 15 + 16;
		for (int j = 0; j < i; j++)
		{
			if (tmp == cells[j][1])//rule out duplicates
			{
				tmp = gen() % 15 + 16;
				j = -1;
			}
		}
		cells[i][1] = tmp;
		marks[i][1] = false;
	}
	//N
	for (int i = 0; i < 5; i++)
	{
		if (i != 2)
		{
			tmp = gen() % 15 + 31;
			for (int j = 0; j < i; j++)
			{
				if (tmp == cells[j][2])//rule out duplicates
				{
					tmp = gen() % 15 + 31;
					j = -1;
				}
			}
			cells[i][2] = tmp;
			marks[i][2] = false;
		}
		else
		{
			cells[i][2] = 0;
			cells[i][2] = true;
		}
	}
	//G
	for (int i = 0; i < 5; i++)
	{
		tmp = gen() % 15 + 46;
		for (int j = 0; j < i; j++)
		{
			if (tmp == cells[j][3])//rule out duplicates
			{
				tmp = gen() % 15 + 46;
				j = -1;
			}
		}
		cells[i][3] = tmp;
		marks[i][3] = false;
	}
	//O
	for (int i = 0; i < 5; i++)
	{
		tmp = gen() % 15 + 61;
		for (int j = 0; j < i; j++)
		{
			if (tmp == cells[j][4])//rule out duplicates
			{
				tmp = gen() % 15 + 61;
				j = -1;
			}
		}
		cells[i][4] = tmp;
		marks[i][4] = false;
	}
}

//Tests for Bingo by checking marks[][]
//Returns true if bingo, false if not
bool Card::testBingo()
{
	//Test diagonals
	if ((marks[0][0] && marks[1][1] && marks[2][2] && marks[3][3] && marks[4][4]) || (marks[0][4] && marks[1][3] && marks[2][2] && marks[3][1] && marks[4][0])) return true;
	//Iterate
	for (int i = 0; i < 5; i++)
	{
		//Test for both horizontal and vertical bingo
		if ((marks[i][0] && marks[i][1] && marks[i][2] && marks[i][3] && marks[i][4]) || (marks[0][i] && marks[1][i] && marks[2][i] && marks[3][i] && marks[4][i])) return true;
	}
	return false;
}

//If user doesn't exist, let cout know
//Test through the list of cards to see if their user string matches
//Print if it does
bool Game::printUser(string user)
{
	bool ufound = false;
	for (string u : users)
	{
		if (u == user) ufound = true;
	}
	if (!ufound) return false;
	bool cfound = false;
	for (Card c : cards)
	{
		if (c.user == user)
		{
			cout << c;
			cfound = true;
		}
	}
	if (!cfound) cout << "User " << user << " was found but has no cards!\n";
	return true;
}

//Find the card in list cards
//If card doesn't exist, generate and print it
//Can't fail, so void
void Game::printCard(int card)
{
	//try to find the card
	for (Card c : cards)
	{
		if (c.seed == card)
		{
			cout << c;
			return;
		}
	}
	//generate and print the card if it doesn't exist
	Card out(card);
	cout << out;
	return;
}

//displays usernames with card seeds underneath
//Can't fail, so void
void Game::print()
{
	for (string user : users)
	{
		cout << "User " << user << "'s Cards:\n";
		for (Card c : cards)
		{
			if (c.user == user)
			{
				cout << c.seed << "\n";
			}
		}
		cout << "\n";
	}
}

//Resets the bingo game by clearing all marks arrays
//Ensures that the free space remains marked
//Can't fail, so void
void Game::newGame()
{
	for (int cardsi = 0; cardsi != cards.size(); cardsi++)
	{
		Card &c = cards[cardsi];
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (j == 2 && i == 2)
				{
					c.marks[i][j] = true;
				}
				else
				{
					c.marks[i][j] = false;
				}
			}
		}
	}
}

//Marks cell on all cards
//Returns true if any marks are placed, false if none
bool Game::mark(int cell)
{
	bool marked = false;
	for (int cardsi = 0; cardsi != cards.size(); cardsi++)
	{
		Card &c = cards[cardsi];
		int j = (cell - 1) / 15;
		for (int i = 0; i < 5; i++)
		{
			if (c.cells[i][j] == cell)
			{
				c.marks[i][j] = true;
				if (c.testBingo()) //Test each marked card for bingo
				{
					//Print Bingo within Game but don't end so that multiple Bingo's can trigger
					cout << c.user << "'s Card " << c.seed << " got BINGO!\n";
				}
				marked = true;
			}
		}
	}
	return marked;
}

//Adds user to the list of users
//If a duplicate user is added, return false and don't add it again
//Returns true if add is successful
bool Game::addUser(string user)
{
	//Don't allow duplicate users
	for (string u : users)
	{
		if (u == user)
		{
			return false;
		}
	}
	users.push_back(user);
	return true;
}

//Adds the card with seed "card" to the vector of Cards
//Returns false if a duplicate card is added or if a user doesn't exist
//Returns true if add is successful
bool Game::addCard(int card, string user)
{
	//rule out duplicates
	for (Card c : cards)
	{
		if (c.seed == card)
		{
			cout << "Card " << card << " is already in play! ";
			return false;
		}
	}
	bool ufound = false;
	//make sure user exists
	for (string u : users)
	{
		if (u == user) ufound = true;
	}
	//end execution if user doesn't exist (return false)
	if (!ufound)
	{
		cout << "User " << user << " not found! ";
		return false;
	}
	//iterate backwards to reach the last card from the desired user;
	//if no cards are found, new user's cards are added to the end
	std::vector<Card>::reverse_iterator reviter;
	for (reviter = cards.rbegin(); reviter != cards.rend(); ++reviter)
	{
		if (reviter.operator*().user == user)
		{
			Card newCard(card);
			newCard.user = user;
			cards.insert(reviter.base(), newCard);
			return true;
		}
	}
	//Case: user doesn't have any cards yet
	Card newCard(card);
	newCard.user = user;
	cards.push_back(newCard);
	return true;
}

//Removes the user <user> and all their cards from the vectors
//Returns false if the user doesn't exist
//Returns true if it does
bool Game::delUser(string user)
{
	bool ufound = false;
	//Iterate through name list, if name matches string, delete
	for (std::vector<string>::iterator iter = users.begin(); iter != users.end(); ++iter)
	{
		if (*iter == user)
		{
			users.erase(iter);
			ufound = true;
			break;
		}
	}
	//If the user doesn't exist return false and stop
	if (!ufound) return false;

	//If the user *does* exist, iterate through cards to remove if their user matches target
	for (std::vector<Card>::iterator iterStart = cards.begin(); iterStart != cards.end(); ++iterStart)
	{
		//Debug result: pointers are weird
		//If user matches, delete begins here
		if (iterStart.operator*().user == user)
		{
			std::vector<Card>::iterator iterEnd;
			//Check all cards after this point to find where delete ends
			//Due to addCard(), the list is in order of user, so this works!
			for (iterEnd = iterStart; iterEnd != cards.end(); ++iterEnd)
			{
				if (iterEnd.operator*().user != user)
				{
					break;
				}
			}
			cards.erase(iterStart, iterEnd);
			return true;
		}
	}
	return true;
}

//Removes the card with seed <card> from the vector of cards
//Returns false if the card doesn't exist; true if it does
bool Game::delCard(int card)
{
	for (std::vector<Card>::iterator iter = cards.begin(); iter != cards.end(); ++iter)
	{
		if (iter.operator*().seed == card)
		{
			cards.erase(iter);
			return true;
		}
	}
	return false;
}

//Operator Overload: Print a card
//Prints the card's user, seed, and full BINGO board
//Adds square brackets to any marked cell 
ostream &operator<<(ostream &os, const Card &card)
{
	os << "User: " << card.user << "\n";
	os << "Seed: " << card.seed << "\n";
	//B I N G O
	os << "   B    I    N    G    O  \n";//4 spaces between each (5 per cell)
	//i = row; j = column (bc it's hard (nigh impossible?) to add to strings by column)
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 2 && j == 2)
			{
				os << "[   ]";
				continue;
			}
			if (card.marks[i][j]) //give the cell a "mark" w/ square brackets
			{
				os << "[ ";
				if (card.cells[i][j] < 10) //format properly
				{
					os << " " << card.cells[i][j] << "]";
				}
				else
				{
					os << card.cells[i][j] << "]";
				}
			}
			else //don't mark the cell
			{
				os << "  ";
				if (card.cells[i][j] < 10) //format properly
				{
					os << " " << card.cells[i][j] << " ";
				}
				else
				{
					;					os << card.cells[i][j] << " ";
				}
			}
		}
		os << "\n";
	}
	return os;
}