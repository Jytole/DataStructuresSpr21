# Semester Project 3: A Membership Directory for BEAM

This is an individual assignment. Seeking direct help from students, tutors, and websites such as chegg or stack overflow will be construed as a violation of the honor code.

## Data Structures and Analysis of Algorithms, akk5

## Objectives

- To strengthen student's knowledge of C++ programming
- To give student experience reading and parsing strings of commands
- To give student experience in writing Data Structures for data types

## Instructions

For this assignment you must write a program that implements a membership directory for the BINGO Enthusiasts Association of Mississippi (BEAM). The membership directory should be implemented as a Binary Search Tree. The directory should be able to create/delete member accounts, edit a member’s information, search for a specific member, display a list of members, and output list of members and their information to a file in post-order (the file format is described below).

Every entry in the membership directory should have the following properties: a member account name (one word), the member’s first, last, and middle names, the number of games won, and the number of games lost. Use the account name to sort the BST.

Your program should implement a text-based interface capable of handling the following commands:

- **exit** - exits the program
- **load** ***<file>*** - parses the contents of the file as if they were entered from the command line
- **save** ***<file>*** - saves the contents of the membership directory into the specified file using the format described below; output the information in post-order
- **directory** - displays a list of member account names; use an inorder traversal
- **display <member>** - displays the information for the given member
- **clear** - clears the membership directory; this sets the BST to empty.
- **add <member>** - adds a new member to the directory; create the member with default information and the specified account name
- **set <member> name <last> <first> <middle>** - set the member's name to last, first middle. Last and first name is required, the middle name is optional.
- **set <member> wins <wins>** - set member's wins to wins.
- **set <member> losses <losses>** - set member's losses to losses.
- **remove** ***<member>*** - remove the specified member.

The save file should have the following format:

    # of Entries
    Member Account Name 1
    Last, First Middle
    Wins Losses
    Member Account Name 2
    Last, First Middle
    Wins Losses
    Member Account Name 3
    Last, First Middle
    Wins Losses

## Guidance

Use the Tokenizer class you developed, or the one I have provided to assist in processing the commands from the text-based interface.

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
| Implements Class Member correctly | 13 pts |
| Implements Class BST correctly | 15 pts |
| | |
| Behavior | 60 pts |
| Program handles all command inputs properly | |
| - Exit the program | 5 pts |
| - Display a list of members | 5 pts |
| - Display a member's information | 5 pts |
| - Save the members to a file | 6 pts |
| - Load a valid file | 5 pts |
| - Clear the member directory | 5 pts |
| - Create a new member | 5 pts |
| - Remove a member | 6 pts |
| - Set a member's first last and middle name | 6 pts |
| - Set a member's wins | 6 pts |
| - Set a member's losses | 6 pts |
| | |
| **Total Possible Points** | **100pts** |
|   |   |
| Penalties |    |
| Program does NOT compile | -100 |
| Late up to 24 hrs | -30 |
| Late more than 24 hrs | -100 |

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

Due Date: 3/7/2021
