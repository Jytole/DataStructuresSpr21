# Semester Project 2: A BINGO Management System

This is an individual assignment. Seeking direct help from students, tutors, and websites such as chegg or stack overflow will be construed as a violation of the honor code.

## Data Structures and Analysis of Algorithms, akk5

## Objectives

- To strengthen student's knowledge of C++ programming
- To give student experience reading and parsing strings of commands
- To give student experience in writing Data Structures for data types

## Instructions

For this assignment you must write a program that implements a BINGO management system. The management system should be able to create/delete player accounts, assign/remove BINGO cards to each player, display the layout of a card, mark cards, and declare BINGO’s.

A BINGO card is a 5 x 5 grid with columns labeled B, I, N, G, O; each cell contains a number between 1 and 75. In traditional BINGO, the numbers for each column are restricted, column B contains only the values 1 to 15, column I’s values range from 16 to 30, column N’s values range from 31 to 45, column G’s values range from 46 to 60, and column O’s values range from 61 to 75. In addition to these restrictions, every cell in the grid is unique (no duplicated values). The central cell of the grid is usually considered a free cell and thus has no assigned value – we can assign it the value of 0 for ease of notation.

The game of BINGO consists of randomly generating numbers from 1 to 75, announcing them to the players, giving them time to mark their cards and declared BINGOs, then repeating the process. A player declares a BINGO if 5 marked cells form a row, column, or diagonal. The game assumes that those numbers are generated elsewhere and is only concerned with managing the cards and declaring BINGO.

Because each card contains 24 separate elements of data in its 5x5 grid, cards will be represented by an integer that is the seed for the series of random numbers which generated the card’s values.

Your program should implement a text-based interface capable of handling the following commands:

- **exit** - exits the program
- **load** ***<file>*** - parses the contents of the file as if they were entered from the command line
- **display user <user>** - displays a list of the user's cards
- **display** - displays a list of the users and their cards
- **display card <card>** - display the specified card.
- **new game** - clears each card of their current markings.
- **mark <cell>** - mark the given cell for every card being managed and check for a BINGO.
- **add user <user>** - add a new user to the game
- **add card <card> to <user>** - add the given card to the specified user. Report failure if the card is duplicate.
- **remove user** ***<user>*** - remove the specified user.
- **remove card** ***<card>*** - remove the specified card.
- Note: ***<cell>*** is an integer between 1 and 75
    - ***<card>*** is the integer id for the card; how this works is described below
    - ***<user>*** is a single word

## Guidance

Use the Tokenizer class you developed, or the one I have provided to assist in processing the commands from the text-based interface.

There are a number of ways to generate random numbers in C++. We will be using the minstd_rand0 generator as implemented in the random library. In order to use this random number generator you need to #include <random> and create an instance of the generator as follows:

    std::minstd_rand0 gen;

You can now generate random numbers with the generator as follow:

    cout << gen()%100 << endl;

would print out a random number generated using gen between 0 and 99.

You can use:

    gen.seed(x);

to set the initial seed for the random number generator to x.

Use the seeding mechanism to generate cards from the integer id described above.

## Grading Breakdown

| Point Breakdown   |               |
|-------------------|---------------|
| Structure     |   12 pts      |
| The program has a header comment with the required information. | 3 pts |
| The overall readability of the program. | 3 pts |
| Program uses separate files for main and class definitions | 3 pts |
| Program includes meaningful comments | 3 pts |
| | |
| Syntax | 28 pts |
| Implements Class User correctly | 13 pts |
| Implements Class Bingo correctly | 15 pts |
| | |
| Behavior | 60 pts |
| Program handles all command inputs properly | |
| - Exit the program | 5 pts |
| - Display a list of users and cards | 5 pts |
| - Display a list of the user's cards | 5 pts |
| - Display a card specified by a given seed | 5 pts |
| - Load a valid file | 5 pts |
| - Clear the markings on every registered card | 5 pts |
| - Mark the specified cell on every card | 5 pts |
| - Successfully declare a BINGO when it occurs | 5 pts |
| - Remove a given user | 5 pts |
| - Remove a given card | 5 pts |
| - Add a user to the game | 5 pts |
| - Add a card to a given user | 5 pts |
| **Total Possible Points** | **100pts** |
|   |   |
| Penalties |    |
| Program does NOT compile | -100 |
| Late up to 24 hrs | -30 |
| Late more than 24hrs | -100 |

## Header Comment

At the top of each program, type in the following comment:

    /*
    Student Name: <student name>
    Student NetID: <student NetID>
    Compiler Used: <Visual Studio, GCC, etc.>
    Program Description:
    <Write a short description of the program.>
    */

Example:

    /*
    Student Name: John Smith
    Student NetID: jjjs123
    Compiler Used: Eclipse using MinGW
    Program Description:
    This program prints lots and lots of strings!!
    */

## Assignment Information

Due Date: 2/21/2021

Files Expected:

1. Main.cpp - File containing function main
2. List.h - File containing the List and Node class definitions.
3. List.cpp - File containing the code for the List and Node methods.
4. Tokenizer.h
5. Tokenizer.cpp
