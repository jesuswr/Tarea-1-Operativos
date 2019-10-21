/*
*	File:			ordered_list.h
*	Description:	header file that contains the signatures of the functions
*					and structures of the ordered linked list
*	Author:			Jesus Wahrman 15-11540
*	Date:			29 / 07 / 19
*/


#ifndef _OL_LIST_H
#define _OL_LIST_H

typedef struct ol_node {
	struct ol_node *next;
	char *word;
} ol_node;

typedef struct {
	ol_node *head;
} ordered_list;

/*
* Function: ol_insert
* --------------------------
* 	Inserts the given node in the given list in order
*
* 	l: pointer to the ordered list
*	np: pointer to the ordered list node to insert
*/
void ol_insert( ordered_list *l , ol_node *np );

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
void ol_make_node( ol_node *np , char *c );

/*
* Function: ol_make_list
* --------------------------
* 	Gets the pointer to the address of a memory block allocated for an ordered
*	list and initializes its values
*
* 	l: pointer to an ordered list
*/
void ol_make_list( ordered_list *l );

#endif