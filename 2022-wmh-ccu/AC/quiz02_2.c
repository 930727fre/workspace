#include <stdio.h>

int calc(int a){
    if(a==0||a==1){
        return 2;
    }
    else{
        return calc(a-1)+calc(a-2);
    }
}

int main(){
    int n,temp;
    while(scanf(" %d",&n)!=EOF){
        printf("%d\n",calc(n));
    }
}

//2 2 4 6 10 16