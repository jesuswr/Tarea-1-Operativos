/*
*	File:			list.c
*	Description:	file that contains the implementation of the
*					linked list and its functions
*	Author:			Jesus Wahrman 15-11540
*	Date:			29 / 07 / 19
*/


#include <stdio.h>
#include <string.h>
#include "list.h"

/*
* Function: insert
* --------------------
* 	Inserts the given node in the first position of the given list by
*	moving its pointers and updates the size of the list
*	
* 	l: pointer to a list
*	n: pointer to a node
*/
void insert( list *l , node *n )
{
	l->size = l->size + 1;
	n->next = l->head;
	l->head = n;
}

/*
* Function: make_node
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for a node
*	and initializes its values with the given pointer to an array of chars and
*	with number of repetitions equal to 1, because the node with that 
*	word has just been created
*
* 	n: pointer to a node
*	c: pointer to an array of chars
*/
void make_node( node *n , char *c )
{
	n->reps = 1;
	n->word = c;
}

/*
* Function: make_list
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for a list
*	and initializes its values head to NULL and size to 0
*
* 	l: pointer to a list
*/
void make_list( list *l )
{
	l->size = 0;
	l->head = NULL;
}

/*
* Function: find
* --------------------------
*	Looks for the given word in the list by moving through its nodes,
*	if it founds it, it adds 1 to the repetition counter for that 
*	node and returns that value. Otherwise if the word is not in the list
*	it returns 0
*
* 	l: pointer lo a list
*	c: pointer to an array of char
*
*	returns: 0 if the words is not in the list or an int that represents
*			 the number of times that word appears in the list plus 1
*/
int find( list *l , char *c )
{
	node *np = l->head;
	while ( np != NULL )
	{
		/* If the word is in the list, it updates the repetition count and 
		   returns it */
		if ( strcmp( c , np->word ) == 0 )
		{
			np->reps = np->reps + 1;
			return np->reps;
		}

		np = np->next;
	}
	return 0;
}