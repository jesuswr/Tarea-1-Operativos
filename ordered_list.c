/*
*	File:			ordered_list.c
*	Description:	file that contains the implementation of the
*					ordered linked list and its functions
*	Author:			Jesus Wahrman 15-11540
*	Date:			29 / 07 / 19
*/


#include <stdio.h>
#include <string.h>
#include "ordered_list.h"

/*
* Function: ol_insert
* --------------------------
* 	Inserts the given node in the given list in order, to do this
*	it compares the word in the node to insert with the word in the head node
*	of the list, if the word in the list is smaller, it does the same process
*	with the next node until it finds a bigger word or the pointer to the
*	node in the list becomes NULL, after this it inserts the node in that
*	position and moves the pointers to adjust the list
*	
* 	l: pointer to the ordered list
*	np: pointer to the ordered list node to insert
*/
void ol_insert( ordered_list *l , ol_node *np )
{
	ol_node *n;
	/* If the list is empty or the word of the first node is bigger than 
	   the word to insert, we insert the node in the beginning of the list,
	   else we check the other nodes to find where to place it */
	if ( l->head == NULL || strcmp( np->word , l->head->word ) < 0 )
	{
		np->next = l->head;
		l->head = np;
	}
	else
	{
		n = l->head;
		while ( n != NULL )
		{
			if ( n->next == NULL || strcmp( np->word , n->next->word ) < 0 )
			{
				np->next = n->next;
				n->next = np;
				return;
			}
			n = n->next;
		}
	}
}

/*
* Function: ol_make_node
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for an ordered
*	list node and initializes its values with the given pointer to an
*	array of chars
*
* 	np: pointer to an ordered list node
*	c: pointer to an array of char 	
*/
void ol_make_node( ol_node *np , char *c )
{
	np->word = c;
}

/*
* Function: ol_make_list
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for an ordered
*	list and initializes its values
*
* 	l: pointer to an ordered list
*/
void ol_make_list( ordered_list *l )
{
	l->head = NULL;
}