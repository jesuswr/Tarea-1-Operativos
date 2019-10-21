/*
*	File:			main. c
*	Description:	file with the main function of the program, this one reads
*					the files and uses list and ordered_list to solve the
*					problem
*	Author:			Jesus Wahrman 15-11540
*	Date:			29 / 07 / 19
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "ordered_list.h"

/* This value can be changed to allow bigger words */
#define MAX_WORD_LENGTH 30
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

int main( int argc , char ** argv )
{
	int nfiles , i , maxreps = 0 , repetitions;
	FILE *fp;
	char w[MAX_WORD_LENGTH] , *w2;
	list *l;
	node *np , *np2;
	ordered_list **listsptr;
	ol_node *olnp , *olnp2;

	/* Verifies the values were given when the executable was called */
	if ( argc == 1 )
	{
		printf("No se dieron los valores necesarios para correr el ");
		printf("programa.\n");
		exit(-2);
	}

	nfiles = atoi(argv[1]);
	/* Verifies if the amount of files given is less than the number given */
	if ( nfiles + 2 > argc )
	{
		printf("La cantidad de archivos que se deberian pasar no ");
		printf("coinciden con la cantidad de archivos recibidos. Se ");
		printf("realizara el proceso solamente con los dados.\n");
		nfiles = argc - 2;
	}

	l = ( list * )malloc( sizeof( list ) );
	/* Verifies that the memory was allocated */
	if ( !l )
	{
		printf("Error en la asignacion de memoria.\n");
		exit(-1);
	}
	make_list( l );

	for ( i = 2 ; i < nfiles + 2 ; i++ )
	{
		fp = fopen( argv[i] , "r" );
		if ( fp == NULL )
		{
			printf("El archivo llamado %s no existe, se continuara", argv[i]);
			printf(" el proceso sin este.\n");
		}
		else
		{
			while ( fscanf( fp , "%s" , w ) != EOF )
			{
				repetitions = find( l , w );

				/* Here we save the maximun number of times a word appears
				   for later use */
				maxreps = max( maxreps , repetitions );
			
				/* Adds the word to the list if 
				   the return value of find is 0 */
				if ( repetitions == 0 )
				{
					w2 = ( char * )malloc( sizeof( char ) * strlen( w ) );
					/* Verifies that the memory was allocated */
					if ( !w2 )
					{
						printf("Error en la asignacion de memoria.\n");
						exit(-1);
					}
					
					np = ( node * )malloc( sizeof( node ) );
					/* Verifies that the memory was allocated */
					if ( !np )
					{
						printf("Error en la asignacion de memoria.\n");
						exit(-1);
					}
					
					/* Copies the word to the allocated space, to insert it
					   to the list */
					strcpy( w2 , w );
					make_node( np , w2 );
					insert( l , np );
				}
			}
			fclose( fp );
		}
	}
	
	/* Here we allocate the memory for an array of pointers to
	   ordered lists */
	listsptr = ( ordered_list ** )malloc( sizeof( ordered_list ) * maxreps );
	/* Verifies that the memory was allocated */
	if ( !listsptr )
	{
		printf("Error en la asignacion de memoria.\n");
		exit(-1);
	}

	/* Initializes the value of the pointers to the ordered lists */
	for ( i = 0 ; i < maxreps ; i++ )
	{
		listsptr[i] = NULL; 
	}
	
	/* For each node in the list, if the number of repetitions of the
	   word of that node is x, we insert the word in the ordered_list pointed
	   by listsptr[x-1] */
	np = l->head;
	while ( np != NULL )
	{
		if ( listsptr[ np->reps - 1 ] == NULL )
		{
			listsptr[ np->reps - 1 ] 
				= ( ordered_list * )malloc( sizeof( ordered_list ) );
			/* Verifies that the memory was allocated */
			if ( !listsptr[ np->reps - 1 ] )
			{
				printf("Error en la asignacion de memoria.\n");
				exit(-1);
			}
			ol_make_list( listsptr[ np->reps - 1 ] );
		}
		
		olnp = ( ol_node * )malloc( sizeof( ol_node ) );
		/* Verifies that the memory was allocated */
		if ( !olnp )
		{
			printf("Error en la asignacion de memoria.\n");
			exit(-1);
		}
		ol_make_node( olnp , np->word );
		ol_insert( listsptr[ np->reps - 1] , olnp );

		np2 = np;
		np = np->next;
		/* Free the memory block of the already used node */
		free( np2 );
	}
	
	/* free the space of the original list */
	free( l );

	/* Here we print the words in the wanted order */
	for ( i = maxreps - 1 ; i >= 0 ; i-- )
	{
		if ( listsptr[ i ] != NULL )
		{
			olnp = listsptr[ i ]->head;
			while ( olnp != NULL )
			{
				printf("%s %d\n", olnp->word , i + 1 );
				
				olnp2 = olnp;
				olnp = olnp->next;
				
				/* Free the space of the used word and node */
				free( olnp2->word );
				free( olnp2 );
			}
			/* Free the space of the used ordered list */
			free( listsptr[ i ] );
		}
	}

	/* Free the space of the array of pointers to ordered lists */
	free( listsptr );

	return 0;
}