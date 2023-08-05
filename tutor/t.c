#include <stdio.h>

int main(){
    p=jolly[n]-jolly[n+1];
    if(delta[p]==1){
        printf("not Jolly\n");
        break;
    }
    else{
        delta[p]=1;
    }
}


//
/*
n=4
input =1,3,4,7
delta 

n=4
input =1,3,5
delta 2 2
delat[2]=1;
*/