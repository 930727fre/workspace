#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char str[1005];
    int n,counter;
    fgets(str,1005,stdin);
    n=atoi(str);
    for(int i=0;i<n;i++){
        fgets(str,1005,stdin);
        str[strlen(str)-1]='\0';
        counter=0;
        for(int j=0;j<strlen(str);j++){
            if(str[j]=='('){

                counter++;
            }
            else if(str[j]==')'){
                counter--;
            }
            if(counter<0){
                break;
            }
        }
        // printf("%d\n",counter);
        if(counter==0){
            printf("T\n");
        }
        else{
            printf("F\n");
        }

    }
}