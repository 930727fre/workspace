#ifndef SIMPLE_HASH_TABLE
#define SIMPLE_HASH_TABLE

#define TABLE_SIZE 100

typedef struct element
{
    char *key;
    int value;
    struct element *next;
} Element;

typedef struct hashtable
{
    Element **table; // the hash function is MurmurOAAT32 mod TABLE_SIZE
    int length; // count of elements
} Hashtable;

typedef struct item
{
    char *key;
    int value;
} Item;

typedef struct itemArray
{
    Item *items;
    int length; // count of items
} ItemArray;

Hashtable *newHashtable();

void HashtableSet(Hashtable *hashtable, char *key, int value);

int HashtableGet(Hashtable *hashtable, char *key);

void HashtableDelete(Hashtable *hashtable, char *key);

void HashtableClear(Hashtable *hashtable);

ItemArray HashtableGetItems(Hashtable *hashtable);

Hashtable *mergeHashtable(Hashtable *ht1, Hashtable *ht2);

#endif