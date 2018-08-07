#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

void* create_hashtab_linked(int slots)
{
	void* ht_addr = NULL;
	HASH_TABLE *ht_head = NULL;

	ht_addr = malloc(slots * sizeof(HASH_TABLE_SLOT_LINKED*));
	if (!ht_addr)
	{
		return NULL;
	}
	memset(ht_addr, 0, slots * sizeof(void*));

	ht_head = malloc(sizeof(HASH_TABLE));
	if (!ht_head)
	{
		free(ht_addr);
		return NULL;
	}

	ht_head->addr = ht_addr;
	ht_head->len = slots;

	return ht_head;
}

void delete_hashtab_linked(HASH_TABLE* ht)
{
	HASH_TABLE_SLOT_LINKED *cur_slot = NULL;
	HASH_TABLE_SLOT_LINKED *next_slot = NULL;

	if (!ht || !ht->addr)
		return;

	for (int i = 0; i < ht->len; ++i)
	{
		cur_slot = ht->addr[i];
		while (cur_slot)
		{
			next_slot = cur_slot->next;
			free(cur_slot);
			cur_slot = next_slot;
		}
		ht->addr[i] = NULL;
	}

	if (ht->len)
	{
		free(ht->addr);
	}

	free(ht);
}

void insert_hashtab_linked(int val, HASH_TABLE *ht)
{
	
}



int ht_oa_insert(HT_OPENADDR *ht, int k)
{
    int j = 0;

    for (int i = 0; i < ht->size; ++i) 
    {
        // j = hashfn(k, i)
        if (ht->arr[j] == NIL)
        {
            ht->arr[j] = k;
            return j;
        }
    }

    return -1;
}


int ht_oa_search(HT_OPENADDR *ht, int k)
{
    int i = 0;
    int j = 0;

    do
    {
        // j = hashfn(k, i)
        if (k == ht->arr[j])
            return j;

        ++i;
    } while (i < ht->size && ht->arr[j]);   

    return -1;
}
