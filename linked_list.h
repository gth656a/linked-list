#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int

typedef struct Node {
	struct Node *next;
	DATATYPE data;
} Node;

void print_list( Node *head ); 
Node *LL_Create( DATATYPE value );
int LL_Delete( Node **head, DATATYPE value, int (*comp) (void *a, void *b) );
int LL_Insert_Front( Node **head, DATATYPE);
int LL_Insert( Node **head, DATATYPE, int (*comp) (void *a, void *b) );
int compare_ints( void *a, void *b );
