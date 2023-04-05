#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_hash_table.h"

unsigned long MurmurOAAT32(char *key)
{
    unsigned long h = 3323198485ul;
    for (; *key; ++key) {
        h ^= *key;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h % TABLE_SIZE;
}

Hashtable *newHashtable()
{
    
}

void HashtableSet(Hashtable *hashtable, char *key, int value)
{
    
}

int HashtableGet(Hashtable *hashtable, char *key)
{
    
}

void HashtableDelete(Hashtable *hashtable, char *key)
{
    
}

void HashtableClear(Hashtable *hashtable)
{
    
}

ItemArray HashtableGetItems(Hashtable *hashtable)
{
    
}

Hashtable *mergeHashtable(Hashtable *ht1, Hashtable *ht2)
{
    
}