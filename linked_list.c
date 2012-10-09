#include "linked_list.h"

int LL_Delete( Node **head, DATATYPE value, int (*compare) ( void *a, void *b ) )
{
	Node *current = *head;
	
	if ( compare( &( current -> data ) , &value ) == 0 ) 
	{
		*head = current -> next;
		free( head );
		return 0;
	}

	while ( current != NULL )
	{
		if ( compare( &( current -> next -> data ), &value ) == 0 )
		{
			current -> next = current -> next -> next;
			free( head );
		}
		current = current -> next;
	}	
}

/* Insert an element in the front of the list */
int LL_Insert_Front( Node **head, DATATYPE value ) 
{
	Node *new = (Node *) malloc( sizeof( Node ) );
	new -> data = value;
	new -> next = *head;
	
	*head = new;
}

/*  Insert an element in the correct place in the list according to passed comparison pointer.
 *  @Precondition: List must be in sorted order
 */
int LL_Insert( Node **head, int value, int (*compare) (void *a, void *b) ) 
{
	Node *current = *head;
	Node *prev = NULL;

	while ( current != NULL && compare( &( current->data ), &value ) > 0 ) {
		prev = current;			
		current = current->next;
	}

	Node *new = (Node *) malloc ( sizeof(struct Node) );
	if ( new == NULL ) {
		printf("Out of memory\n");
		return 1;
	}
		
	new->data = value;
	new->next = current;	

	if ( prev == NULL ) 
		*head = new;	
	else
		prev->next = new;
	
	return 0;
}

void print_list( Node *head ) 
{
	Node *cur = head;

	while ( cur != NULL ) {
		printf("Data: %d\n", cur->data);
		cur = cur->next;	
	}
}

int compare_ints( void *a, void *b ) 
{
	return ( *(int *) b - *(int *) a );
}

Node *LL_Create( DATATYPE value )
{
	Node *head = (Node *) malloc( sizeof(struct Node) );

	if ( head == NULL ) {
		printf("Out of memory\n");
		return NULL;
	}
	head->data = value;
	head->next = NULL;
	
	return head;
}

	

