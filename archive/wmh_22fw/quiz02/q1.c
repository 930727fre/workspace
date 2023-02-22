#include <stdio.h>

int fc(int);
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        else{
            printf("%d\n",fc(n));
        }
    }
}

int fc(int n){
    int sum=0;
    if(n<10){
        return n;
    }
    while(n){
        sum+=(n%10);
        n=n/10;
    }
    return fc(sum);
}
/*
2
11
47
1234567892
0
*/