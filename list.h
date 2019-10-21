/*
*	File:			list.h
*	Description:	header file that contains the signatures of the functions
*					and structures of the linked list
*	Author:			Jesus Wahrman 15-11540
*	Date:			29 / 07 / 19
*/


#ifndef _LIST_H
#define _LIST_H

typedef struct node {
	struct node *next;
	char *word;
	int reps;
} node;

typedef struct {
	int size;
	node *head;
} list;

/*
* Function: insert
* --------------------------
*	Inserts the given node in the given list
*
* 	l: pointer to a list
*	n: pointer to a node
*/
void insert( list *l , node *n );

/*
* Function: make_node
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for a node
*	and initializes its values with the given pointer to an arrays of chars
*
* 	n: pointer to a node
*	c: pointer to an array of chars
*/
void make_node( node *n , char *c  );

/*
* Function: make_list
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for a list
*	and initializes its values
*
* 	l: pointer to a list
*/
void make_list( list *l );

/*
* Function: find
* --------------------------
* 	Looks for the given word in the given list, if it finds it, it updates
*	the number of repetitions of that word by 1 and returns the new number of 
*	repetitions for that word. If it doesnt find it, returns 0.
*
* 	l: pointer lo a list
*	c: pointer to an array of char
*
*	returns: 0 if the words is not in the list or an int that represents
*			 the number of times that word appears in the list plus 1
*/
int find( list *l , char *c );

#endif