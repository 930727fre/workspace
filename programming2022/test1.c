#include <stdio.h>
using namespace std;

int main(){
    char a;
    for(int counter =0; counter<5; counter+=1){
        scanf("%c", &a);
        if(a>=65 && a<=90){
            printf("%c",32+a);
        }
        else if(a>=97&&a<=122){
            printf("%c", a-32);
        }
        else{
            printf("%c", a);
        }
        printf("\ncounter: %d", counter);
    }

}