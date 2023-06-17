#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bst
{
    struct bst* left;
    struct bst* right;
    int key;
}BST;

void traverse(BST* leaf){
    if(leaf->left!=NULL){
        traverse(leaf->left);
    }
    printf("%d\n",leaf->key);
    if(leaf->right!=NULL){
        traverse(leaf->right);
    }
    free(leaf);
}

int main(){
    int arr[100],temp;
    BST *root=(BST*)malloc(sizeof(BST)), *leaf;
    srand(time(NULL));
    for(int i=0;i<100;i++){
        arr[i]=i+1;
    }
    for(int i=0;i<100;i++){
        int j=rand()%100;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    root->key=arr[0];
    for(int i=1;i<100;i++){
        leaf=root;
        while(1){
            if(leaf->key>arr[i]){
                if(leaf->left==NULL){
                    leaf->left=(BST*)malloc(sizeof(BST));
                    leaf->left->key=arr[i];
                    break;
                }
                else{
                    leaf=leaf->left;
                    continue;
                }
                
            }
            else{
                if(leaf->right==NULL){
                    leaf->right=(BST*)malloc(sizeof(BST));
                    leaf->right->key=arr[i];
                    break;
                }
                else{
                    leaf=leaf->right;
                    continue;
                }
            }
        }
    }
    traverse(root);
}