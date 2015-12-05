/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void add(struct node** headref, int data) {
	struct node* current =(struct node *) malloc(sizeof(struct node));
	current->num = data;
	current->next = *headref;
	*headref = current; 
}
struct node * numberToLinkedList(int N) 
{
	int n = (N > 0) ? N : -N;
	struct node *head=(struct node *) malloc(sizeof(struct node));
	head->num = n % 10;
	head->next = NULL;
	n /= 10;
	while (n > 0)
	{
		int rem = n % 10;
		add(&head, rem);
		n /= 10;
	}
	return head;
}