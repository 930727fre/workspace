#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int pid=fork();
    printf("%d\n",getpid());
    if(pid!=0){
        printf("child");
    }
    else{
        printf("parent");
    }
    exit(127);
}