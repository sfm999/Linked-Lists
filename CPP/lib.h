
// lib.h | This is the header file, containing declarations for
// data structures, import declarations, and function declarations.
//

#pragma once

#include <iostream>
#include <cstdlib>
#include <random>

/* ------------------------------------------
             'node' data structure
   ----------------------------------------- */
struct node
{
    int data;
    struct node* next;
};

/* ------------------------------------------------
             Singly Linked List Functions
   ------------------------------------------------ */

// Initialised a node double ptr with value, initialises node->next to nullptr
void initNode(struct node**, int);

// Receives a given node and inserts a new node after it
// Accounts for if given node has a valid 'next'
void insertAfter(struct node*, int);

// Adds a new tail to the singly linked list
void append(struct node**, int);

// Adds a new head to the singly linked list
void push(struct node**, int);

// This function makes use of all the previous functions to do an ordered insertion.
// You would edit this function to change how the data is ordered.
void insert(struct node**, int);


/* -------------------------------------------
                Utility Functions
   ------------------------------------------- */

// Prints a given node
void printNode(node*);

// Prints all nodes in a linked list. Utilises printNode(node*)
void printAllNodes(node*);
