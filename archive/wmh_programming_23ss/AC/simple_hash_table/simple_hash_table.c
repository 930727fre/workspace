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

Hashtable *newHashtable() // malloc a new hash table and arrign a array of Element** to it.
{
    Hashtable *newTable=(Hashtable*)malloc(sizeof(Hashtable));
    Element **tableArray=(Element**)malloc(TABLE_SIZE*sizeof(Element*));
    newTable->table=tableArray;
    newTable->length=0;
    // for(int i=0;i<TABLE_SIZE;i++){
    //     tableArray[i]->key=NULL;
    //     tableArray[i]->value=0;
    //     tableArray[i]->next=NULL;
    // }

   return newTable;
}

void HashtableSet(Hashtable *hashtable, char *key, int value) // set the given key to `value`
{
    unsigned long hashValue=MurmurOAAT32(key);
    Element *currentElement=(hashtable->table)[hashValue]; 
    if(currentElement==NULL){ // if the given hashValue is NULL
        (hashtable->table)[hashValue]=(Element*)malloc(sizeof(Element));
        Element *currentElement=(hashtable->table)[hashValue]; 
        currentElement->key=(char*)malloc(sizeof(key));
        strcpy(currentElement->key,key);
        currentElement->next=NULL;
        currentElement->value=value;
        hashtable->length++;
        return;
    }
    while(1){ // find the key in that given hashValue's linked list
        if(!strcmp(currentElement->key,key)){
            currentElement->value=value; // modify the value to the new one
            return;
        }
        if(currentElement->next!=NULL){
            currentElement=currentElement->next;
        }
        else{
            currentElement->next=(Element*)malloc(sizeof(Element));  // malloc a new node
            currentElement=currentElement->next;
            currentElement->key=(char*)malloc(sizeof(key)); // malloc a new char key memory
            strcpy(currentElement->key,key);
            currentElement->next=NULL;
            currentElement->value=value;
            hashtable->length++;
            return;
        }
    }

}

int HashtableGet(Hashtable *hashtable, char *key)
{
    unsigned long hashValue=MurmurOAAT32(key);
    Element *currentElement=(hashtable->table)[hashValue];
    if(currentElement==NULL){
        return -9999; // unable to get the value of given key 
    }
    while(1){
        if(!strcmp(currentElement->key,key)){
            return currentElement->value; // return the value
        }
        if(currentElement->next!=NULL){
            currentElement=currentElement->next;
        }
        else{
            return -9999; // unable to get the value of given key
        }
    }
}

void HashtableDelete(Hashtable *hashtable, char *key)
{
    Element *currentElement=(hashtable->table)[MurmurOAAT32(key)];
    Element *previousElement=NULL;

    while(1){
        if(!strcmp(currentElement->key,key)){
            if(previousElement!=NULL){
                previousElement->next=currentElement->next; // delete the node in the linked list
            }
            if((hashtable->table)[MurmurOAAT32(key)]==currentElement){
                (hashtable->table)[MurmurOAAT32(key)]=NULL;
            }
            free(currentElement);
            hashtable->length--;
            return;
        }
        if(currentElement->next!=NULL){
            previousElement=currentElement;
            currentElement=currentElement->next;
        }
        else{
            return; //unable to delete given key
        }
    }    
}

void HashtableClear(Hashtable *hashtable)
{
    for(int i=0;i<TABLE_SIZE;i++){
        Element *currentElement=(hashtable->table)[i];
        Element *tempElement;
        while(currentElement!=NULL){ // delete all node in that linked list
            tempElement=currentElement;
            currentElement=currentElement->next;
            free(tempElement);
        }
        (hashtable->table)[i]=NULL;
    }
    hashtable->length=0;
    return;
}

ItemArray HashtableGetItems(Hashtable *hashtable)
{
    ItemArray *array=(ItemArray*)malloc(sizeof(ItemArray));
    array->length=0;
    array->items=(Item*)malloc(hashtable->length*sizeof(Item)); // malloc a array of hashtable->length size
    for(int i=0;i<TABLE_SIZE;i++){
        Element *currentElement=(hashtable->table)[i];
        if(currentElement==NULL){
            continue;
        }
        while(1){
            (array->items[array->length]).key=(char*)malloc(sizeof(currentElement->key)); // if there's a node, store it into the array
            strcpy((array->items[array->length]).key,currentElement->key);
            array->items[array->length].value=currentElement->value;
            array->length++;
            if(currentElement->next==NULL){
                break;
            }
            else{
                currentElement=currentElement->next;
            }
        }
    }    

    return *array;
}

Hashtable *mergeHashtable(Hashtable *ht1, Hashtable *ht2)
{
    Hashtable *newTable=newHashtable();
    ItemArray array1=HashtableGetItems(ht1); //GETITEMS from ht1 and store each entry to newTable
    for(int i=0;i<ht1->length;i++){

        HashtableSet(newTable,array1.items[i].key,array1.items[i].value);
    }
    ItemArray array2=HashtableGetItems(ht2); //GETITEMS from ht2 and store each entry to newTable
    for(int i=0;i<ht2->length;i++){
        HashtableSet(newTable,array2.items[i].key,array2.items[i].value);
    }

    return newTable;
}