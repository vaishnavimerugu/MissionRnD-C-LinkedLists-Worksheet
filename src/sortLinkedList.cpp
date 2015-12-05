/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node *n1, struct node *n2)
{
	int data = n1->num;
	n1->num = n2->num;
	n2->num = data;
}
struct node * sortLinkedList(struct node *head) 
{
	if (head==NULL)
		return NULL;
	int flag;
	struct node *last = NULL;
	do
	{
		struct node *current = head;
	    flag = 0;
		while (current->next != last)
		{
			if (current->num > current->next->num)
			{
				swap(current, current->next);
				flag = 1;
			}
			current = current->next;
		}
		last = current;
	} while (flag);
	return head;
}