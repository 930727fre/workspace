#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BST{
    int val;
    struct BST *left;
    struct BST *right;
}bst;

int level=1, num=1;
int enQueue(int, bst*);
int main(){
    bst* tree=(bst*)malloc(sizeof(bst));
    int n, a, temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(i==0){
            tree->val=a;
        }
        else{
            enQueue(a, tree);
        }
    }
    if(num==pow(2,level-1)){
        temp=1;
        n-=1;
        level--;
        while(n!=0){
            temp*=2;
            n-=temp;
            level--;
        }
        if(level==0){
            printf("PERFECT\n");
        }
        else{
            printf("NOT PERFECT\n");
        }
    }
    else{
        printf("NOT PERFECT\n");
    }
}


int enQueue(int val, bst* root){

    bst* leaf=root;
    int levelIndex=1;

    while(1){
        // printf("%d\n", leaf->val);
        levelIndex++;
        if(val<leaf->val){
            if(leaf->left==NULL){
                leaf->left=(bst*)malloc(sizeof(bst));
                leaf=leaf->left;
                leaf->val=val;
                if(levelIndex>level){
                    level=levelIndex;
                    num=1;
                }
                else if(level==levelIndex){
                    num++;
                }
                break;
            }
            else{
                leaf=leaf->left;
            }
        }
        else{
            if(leaf->right==NULL){
                leaf->right=(bst*)malloc(sizeof(bst));
                leaf=leaf->right;
                leaf->val=val;
                if(levelIndex>level){
                    level=levelIndex;
                    num=1;
                }
                else if(level==levelIndex){
                    num++;
                }
                break;                
            }
            else{
                leaf=leaf->right;
            }
        }        
    }
    return 0;
}