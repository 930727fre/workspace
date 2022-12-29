#include <stdio.h>
#include <math.h>
#include <string.h>

int map(char);
int main(){
    //char str[50]="2kQE4C";
    char str[50]="23456abc";

    unsigned long long digit=0,dec=0,temp;
    //scanf("%s",str);
    digit = strlen(str);
    for(int i=0;i<digit;i++){
        printf("%llu\n",map(str[i])*pow(58,digit-i-1));
        dec+=map(str[i])*pow(58,digit-i-1);
    }
    //printf("dec = %llu\n",dec);
    temp = dec;
    printf("%llu %llx\n",dec,dec);
    for(int i=7;i>=0;i--){
        temp=dec;
        temp = temp<<(8*(31-i));
        temp = temp>>56;        
        if(temp<10){
            printf("0");
        }
        printf("%llx ",temp);

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


/*

10010

*/
//30 31