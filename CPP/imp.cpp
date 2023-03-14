
// imp.cpp | This is the implementation file for the header file.
//							   For explanations of each function, please refer to lib.h
//


#include "lib.h"

// 

void initNode(struct node** head, int val)
{
	(*head) = new node();
	(*head)->data = val;
	(*head)->next = nullptr;
}

void insertAfter(struct node* prevNode, int val)
{
	if (prevNode == NULL) {
		printf("The previous node cannot be NULL. Insertion failed");
		return;
	}

	struct node* newNode = NULL;
	initNode(&newNode, val);

	// If prevNode has a next already
	// Store its next in temp, make its next now point to newNode,
	// make newNode->next point to temp
	if (prevNode->next != NULL) {
		struct node* temp = prevNode->next;
		prevNode->next = newNode;
		newNode->next = temp;
		return;
	}

	prevNode->next = newNode;
}

void append(struct node** headRef, int val) {
	if (*headRef == NULL) {
		initNode(headRef, val);
		return;
	}

	struct node* last = *headRef;

	struct node* newNode = NULL;
	initNode(&newNode, val);

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newNode;
}

void push(struct node** headRef, int val)
{
	struct node* newHead = NULL;
	initNode(&newHead, val);
	newHead->next = *headRef;
	*headRef = newHead;
	return;
}

void insert(struct node** headRef, int val)
{
	// If head is null
	if (*headRef == NULL)
	{
		push(headRef, val);
		return;
	}

	if ((*headRef)->data > val)
	{
		push(headRef, val);
		return;
	}

	struct node* curr = *headRef;
	struct node* prev = curr;

	// Need to keep track of previous node
	// Iterate till either tail node OR we find a value >= to given val
	while (curr != NULL && curr->data < val)
	{
		prev = curr;
		curr = curr->next;
	}

	insertAfter(prev, val);





	return;
}


void printNode(node* givenNode)
{
	std::cout << " ------ " << std::endl;
	std::cout << "|      |" << std::endl;

	if (givenNode->data < 10) {
		std::cout << "|  "  << givenNode->data << "   |" << std::endl;
	}
	else {
		std::cout << "|  ";
		std::cout << givenNode->data;
		std::cout << "  |" << std::endl;
	}
	std::cout << "|      |" << std::endl;
	std::cout << " ------ " << std::endl;
	std::cout << "   ||   " << std::endl;
	std::cout << "   ||   " << std::endl;
	std::cout << "   \\/   " << std::endl;

	
}

void printAllNodes(node* n)
{
	if (n == NULL) {
		std::cout << "List is empty." << std::endl;
		return;
	}
	std::cout << "Printing all nodes in list" << std::endl;
	while (n != NULL) {
		printNode(n);
		n = n->next;
	}
	return;
}
