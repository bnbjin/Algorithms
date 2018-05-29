#ifndef __HASH_H__
#define __HASH_H__

#define NIL NULL

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

#endif // __HASH_H__
