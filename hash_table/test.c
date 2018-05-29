#include <stdio.h>
#include <assert.h>
#include "hash.h"
#include "hash_fn.h"

void test_hashtab_linked_div()
{
	HASH_TABLE *ht = NULL;
	
	ht = create_hashtab_linked(31);
	assert(ht);

	delete_hashtab_linked(ht);
}

void test_hash_linked_mul()
{
	int res = hash_fn_mul(123, 2 << 3);
}

int main(int argc, char *argv[])
{
	test_hashtab_linked_div();
	test_hash_linked_mul();

	return 0;
}
