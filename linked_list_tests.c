#include "linked_list.h"
#include "assert.h"

void testCreate() {
	Node *head = LL_Create( 4 );
	assert( head -> data == 4 );
	assert( head -> next == NULL );
}
	
void testInsert() {
	Node *head = LL_Create( 4 );

	LL_Insert( &head, 2, compare_ints );
	LL_Insert( &head, 8, compare_ints );
	assert( head -> data == 2 );
	
	LL_Insert_Front( &head, 1 );
	print_list( head );
	assert( head -> data == 1 );
}

int main() {
	testCreate();

	// TODO insert duplicate
	testInsert();

	// Linked list head delete test
	/*LL_Delete( &head, 2, compare_ints );*/
	/*LL_Delete( &head, 8, compare_ints );*/

	/*LL_show(head);*/

	printf("\nEnd of program.");

	// 2 4 8
	return EXIT_SUCCESS;
}

