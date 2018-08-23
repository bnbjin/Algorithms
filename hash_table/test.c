#include "hash.h"
#include "hash_fn.h"
#include <stdio.h>
#include <assert.h>

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

void test_hash_linked_mul2()
{
    int slot = 0;
    HASH_TABLE *ht = NULL;

    ht = create_hashtab_linked(1024);
    assert(ht);

    slot = hash_fn_mul2(123, 1024);
    printf("mul2(k=123, m=1024), slot=%d\n", slot);
    
    delete_hashtab_linked(ht);
}

void test_hash_unvsl()
{
    int slot = 0;
    HASH_TABLE *ht = NULL;
    
    ht = create_hashtab_linked(2048);
    assert(ht);

    hash_fn_unvsl_init(12211);

    slot = hash_fn_unvsl(365, 2048);
    printf("unvsl(k=365, m=2048, p=12211), slot=%d\n", slot);

    slot = hash_fn_unvsl(3365, 2048);
    printf("unvsl(k=3365, m=2048, p=12211), slot=%d\n", slot);

    delete_hashtab_linked(ht);
}

int main(int argc, char *argv[])
{
	test_hashtab_linked_div();
	test_hash_linked_mul();
    test_hash_linked_mul2();
    test_hash_unvsl();

	return 0;
}
