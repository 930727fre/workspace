#include <stdio.h>

void move(int n, int from, int to){
    int temp;
    if(n==0){
        return;
    }
    else{
        if(from*to==2){
            temp=3;
        }
        else if(from*to==3){
            temp=2;
        }
        else{
            temp=1;
        }
        move(n-1, from, temp);
        printf("%c->%c\n",'A'+from-1, 'A'+to-1);
        move(n-1, temp, to);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    move(n,1,3);
}