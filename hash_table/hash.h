#ifndef __HASH_H__
#define __HASH_H__

#define NIL NULL


// chaining

typedef struct _HASH_TABLE_SLOT_LINKED
{
	int								val;
	struct _HASH_TABLE_SLOT_LINKED	*next;
} HASH_TABLE_SLOT_LINKED;

typedef struct _HASH_TABLE 
{
	HASH_TABLE_SLOT_LINKED	**addr;	
	int						len;
} HASH_TABLE;

void* create_hashtab_linked(int slots);

void delete_hashtab_linked(HASH_TABLE* ht);


// open addressing

typedef struct _HT_OPENADDR
{
    int *arr;
    int size;
} HT_OPENADDR;


int ht_oa_insert(HT_OPENADDR *ht, int k);

int ht_oa_search(HT_OPENADDR *ht, int k);

#endif // __HASH_H__
