#include <stdio.h>
#include <string.h>
#include <math.h>

int map(char);
int main(){
    char str[20]="23456abc";
    scanf("%s",str);
    unsigned long long dec=0,power=1,temp;
    for(int i=0;i<strlen(str)-1;i++){
        power*=58;
    }
    for(int i=0;i<strlen(str);i++){
        dec+=map(str[i])*power;
        power/=58;

    }
    //printf("dec = %llu\n",dec);
    for(int i=15;i>=0;i--){
        temp=dec;
        temp = temp<<(4*(15-i));
        temp = temp>>60;
        printf("%llx",temp);
        if(i!=0&&i%2==0){
            printf(" ");
        }
    }
    printf("\n");
}

int map(char w){
    if('1'<=w&&w<='9'){
        return w-'1';
    }
    else if('A'<=w&&'H'>=w){
        return w-'A'+9;
    }
    else if('J'<=w&&'N'>=w){
        return w-'J'+17;
    }
    else if('Q'<=w&&w<='Z'){
        return w-'Q'+23;
    }
    else if('a'<=w&&w<='k'){
        return w-'a'+33;
    }
    else{
        return w-'m'+44;
    }
}
