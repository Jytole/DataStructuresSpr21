# Semester Project 4: Updating the Membership Directory for BEAM

This is an individual assignment. Seeking direct help from students, tutors, and websites such as chegg or stack overflow will be construed as a violation of the honor code.

## Data Structures and Analysis of Algorithms, akk5

## Objectives

- To strengthen student's knowledge of C++ programming
- To give student experience reading and parsing strings of commands
- To give student experience in writing Data Structures for data types

## Instructions

For this assignment you must rewrite your program from Project 3 to add new functionality. The new version of the membership directory should use an AVL instead of a BST; it should be able to load previously saved data and reconstruct the tree and be able to display the directory in inorder, preorder, and postorder.

As an additional requirement, you must implement your AVL using inheritance from the previously implemented BST. A working version of the BST has been provided if you failed to implement Project 3. You should not edit the provided BST.cpp or BST.h when implementing your AVL.

Every entry in the membership directory should have the following properties: a member account name (one word), the member’s first, last, and middle names, the number of games won, and the number of games lost. You will still use the account name to sort the AVL.

Your program should implement a text-based interface capable of handling the following commands:

- **exit** - exits the program
- **load** ***<file>*** - parses the contents of the file as if they were entered from the command line
- **load from** ***<file>*** - rebuilds the membership directory from a previous save file.
- **save** ***<file>*** - saves the contents of the membership directory into the specified file using the format described below; output the information in post-order
- **directory** ***<order>*** - displays a list of member account names in the traversal order specified (in, pre, or post).
- **display** ***<member>*** - displays the information for the given member
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

Remember, you must use inheritance to implement the AVL.

## Grading Breakdown

| Point Breakdown   |               |
|-------------------|---------------|
| Structure     |   12 pts      |
| The program has a header comment with the required information. | 3 pts |
| The overall readability of the program. | 3 pts |
| Program uses separate files for main and class definitions | 3 pts |
| Program includes meaningful comments | 3 pts |
| | |
| Syntax | 20 pts |
| Implements Class AVL correctly | 20 pts |
| | |
| Behavior | 68 pts |
| Program handles all command inputs properly | |
| - Exit the program | 5 pts |
| - Display a list of members | 7 pts |
| - Display a member's information | 5 pts |
| - Save the members to a file | 5 pts |
| - Load a valid file | 5 pts |
| - Load a previous save | 7 pts |
| - Clear the member directory | 5 pts |
| - Create a new member | 7 pts |
| - Remove a member | 7 pts |
| - Set a member's first last and middle name | 5 pts |
| - Set a member's wins | 5 pts |
| - Set a member's losses | 5 pts |
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

Due Date: 3/21/2021
