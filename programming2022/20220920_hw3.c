#include <stdio.h>


int main(){
    char a[5];
    for (int counter=0; counter <5; counter+=1){
        scanf("%s", &a[counter]);

    }
    for(int counter =0; counter<5; counter+=1){
        
        if(a[counter]>=65 && a[counter]<=90){
            printf("%c",32+a[counter]);
        }
        else if(a[counter]>=97&&a[counter]<=122){
            printf("%c", a[counter]-32);
        }
        else{
            printf("%c", a[counter]);
        }

        if(counter!=4){
            printf(" ");
        }
        
    }
    return 0;
}