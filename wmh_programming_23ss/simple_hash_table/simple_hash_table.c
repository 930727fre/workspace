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
        if(currentElement->key!=NULL&&!strcmp(currentElement->key,key)){
            if(previousElement!=NULL){
                previousElement->next=currentElement->next;
            }
            free(currentElement);
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
        Element *nextElement;
        currentElement->key=NULL;
        currentElement=currentElement->next;
        while(currentElement!=NULL){
            nextElement=currentElement->next;
            free(currentElement);
            currentElement=nextElement;
        }
    }
}

ItemArray HashtableGetItems(Hashtable *hashtable)
{
    ItemArray *array=(ItemArray*)malloc(sizeof(ItemArray));
    int arrayIndex=0;
    for(int i=0;i<TABLE_SIZE;i++){
        Element *currentElement=(hashtable->table)[i];
        if(currentElement->key==NULL){
            continue;
        }
        while(1){
            array->length++;
            if(currentElement->next==NULL){
                break;
            }
            else{
                currentElement=currentElement->next;
            }
        }
    }
    array->items=(Item*)malloc(array->length*sizeof(Item));
    for(int i=0;i<TABLE_SIZE;i++){
        Element *currentElement=(hashtable->table)[i];
        if(currentElement->key==NULL){
            continue;
        }
        while(1){
            strcpy((array->items[arrayIndex]).key,currentElement->key);
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
    
}

int main(){
    Hashtable *table=newHashtable();
    HashtableSet(table,"dog",5);
    
}