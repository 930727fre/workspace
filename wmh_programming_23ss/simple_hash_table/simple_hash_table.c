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

void HashtableSet(Hashtable *hashtable, char *key, int value)
{
    unsigned long hashValue=MurmurOAAT32(key);
    Element *currentElement=(hashtable->table)[hashValue]; 
    if(currentElement==NULL){
        (hashtable->table)[hashValue]=(Element*)malloc(sizeof(Element));
        Element *currentElement=(hashtable->table)[hashValue]; 
        currentElement->key=(char*)malloc(sizeof(key));
        strcpy(currentElement->key,key);
        currentElement->next=NULL;
        currentElement->value=value;
        hashtable->length++;
        return;
    }
    while(1){
        if(!strcmp(currentElement->key,key)){
            currentElement->value=value;
            return;
        }
        if(currentElement->next!=NULL){
            currentElement=currentElement->next;
        }
        else{
            currentElement->next=(Element*)malloc(sizeof(Element));
            currentElement=currentElement->next;
            currentElement->key=(char*)malloc(sizeof(key));
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
        return -9999;
    }
    while(1){
        if(!strcmp(currentElement->key,key)){
            return currentElement->value;
        }
        if(currentElement->next!=NULL){
            currentElement=currentElement->next;
        }
        else{
            return -9999; //unable to get the value of given key
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
                previousElement->next=currentElement->next;
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
        while(currentElement!=NULL){
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
    int arrayIndex=0;
    array->items=(Item*)malloc(hashtable->length*sizeof(Item));
    for(int i=0;i<TABLE_SIZE;i++){
        Element *currentElement=(hashtable->table)[i];
        if(currentElement==NULL){
            continue;
        }
        while(1){
            (array->items[arrayIndex]).key=(char*)malloc(sizeof(currentElement->key));
            strcpy((array->items[arrayIndex]).key,currentElement->key);
            array->items[arrayIndex].value=currentElement->value;
            arrayIndex++;
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
    ItemArray array1=HashtableGetItems(ht1);
    for(int i=0;i<ht1->length;i++){
        printf("%s %d\n",array1.items[i].key,array1.items[i].value);
        HashtableSet(newTable,array1.items[i].key,array1.items[i].value);
    }
    ItemArray array2=HashtableGetItems(ht2);
    for(int i=0;i<ht2->length;i++){
        printf("%s %d\n",array2.items[i].key,array2.items[i].value);
        HashtableSet(newTable,array2.items[i].key,array2.items[i].value);
    }

    return newTable;
}
