# Semester Project 1: Implementing a Doubly Linked List

This is an individual assignment. Seeking direct help from students, tutors, and websites such as chegg or stack overflow will be construed as a violation of the honor code.

## Data Structures and Analysis of Algorithms, akk5

## Objectives

- To strengthen student's knowledge of C++ programming
- To give student experience reading and parsing strings of commands
- To give student experience in writing Data Structures for data types

## Instructions

For this assignment you must write a program that implements and manages a list of information. The list must store entries comprised of a string representing an event id and an integer representing the events priority; for simplicity, this program does not concern itself with duplicate event ids. The linked list should be implemented as a doubly linked list.

Your program should implement a text-based interface capable of handling the following commands:

- **exit** - exits the program
- **load** ***<file>*** - parses the contents of the file as if they were entered from the command line
- **display forward** - displays the contents of the double linked list from head to tail
- **display backward** - displays the contents of the double linked list from tail to head
- **find** ***<loc>*** - finds the specified event, displays its priority. Should inform the user on a failure.
- **remove** ***<loc>*** - Removes the specified event. Should inform the user on a failure.
- **clear** - clears the list of events
- **insert** ***<event> <priority>*** **before** ***<loc>*** - inserts the specified event, priority pair immediately before loc. Should inform the user if the insert fails because loc is not in the list.
- **insert** ***<event> <priority>*** **after** ***<loc>*** - inserts the specified event, priority pair immediately after loc. Should inform the user if the insert fails because loc is not in the list.
- Note: ***<event>*** is a single word representing the event
    - ***<loc>*** can be:
        - a single word representing the event
        - |HEAD| which represents the head of the list
        - |TAIL| which represents the tail of the list
    - ***<priority>*** is an integer from 0 to 100.

## Guidance

Use the Tokenizer class you developed, or the one I have provided to assist in processing the commands from the text-based interface.

Remember that |HEAD| and |TAIL| are only valid inputs for loc, and should be considered an error if used as an event.

## Grading Breakdown

| Point Breakdown   |               |
|-------------------|---------------|
| Structure     |   12 pts      |
| The program has a header comment with the required information. | 3 pts |
| The overall readability of the program. | 3 pts |
| Program uses separate files for main and class definitions | 3 pts |
| Program includes meaningful comments | 3 pts |
| Syntax | 24 pts |
| Implements Class Node correctly | 9 pts |
| Implements Class List correctly | 15 pts |
| | |
| Behavior | 64 pts |
| Program handles all command inputs properly | |
| - Exit the program | 8 pts |
| - Display the list correctly | 8 pts |
| - Load a valid file | 8 pts |
| - Find a value in the list | 8 pts |
| - Remove a value from the list | 8 pts |
| - Clear the list | 8 pts |
| - Insert a uid, security pair before another uid | 8 pts |
| - Insert a uid, security pair after another uid | 8 pts |
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
    Compiler Used: <Visual Studio, GCC, etc.> Program Description:
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

Due Date: 2/7/2021

Files Expected:

1. Main.cpp - File containing function main
2. List.h - File containing the List and Node class definitions.
3. List.cpp - File containing the code for the List and Node methods.
4. Tokenizer.h
5. Tokenizer.cpp
