// Linked Lists Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "lib.h"

int main()
{

    srand(time(NULL));

    struct node* head = NULL;
    initNode(&head, 5);


    for (int i = 0; i < 20; i++)
    {
        insert(&head, rand() % 30 + 1);
    }

    printAllNodes(head); 
}
