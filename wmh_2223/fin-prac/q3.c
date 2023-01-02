#include <stdio.h>

int map(char);
int main(){
    char str[1000]="CSIE CCU";
    
}

int map(char w){
    if('A'<=w&&w<='Z'){
        return w-'A';
    }
    else if('a'<=w&&w<='z'){
        return w-'a'+26;
    }
    else if('0'<=w&&w<='9'){
        return w-'0'+52;
    }
    else if(w=='+'){
        return 62;
    }
    else if(w=='/'){
        return 63;
    }
}