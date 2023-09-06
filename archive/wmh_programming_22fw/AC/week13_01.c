#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char str[11];
    long long int dec;
    while(1){
        dec=0;
        scanf("%s",str);
        if(str[0]=='-'){
            break;
        }
        else if(str[1]=='x'){//
            for(int i=strlen(str)-1;i>1;i--){
                if(str[i]>=97&&str[i]<=102){
                    dec+=(str[i]-87)*(int)pow(16,strlen(str)-i-1);

                }
                else if(str[i]>=65&&str[i]<=70){
                    dec+=(str[i]-55)*(int)pow(16,strlen(str)-i-1);
                }
                else{
                    dec+=(str[i]-48)*(int)pow(16,strlen(str)-i-1);
                }
            }
            printf("%lld\n",dec);
        }
        else{
            //printf("0x");
            dec=atoi(str);
            int index=0;
            printf("0x");
            while(dec/(int)pow(16,index+1)){
                index++;
            }
            for(int i=index;dec;i--){
                if(dec/(int)pow(16,i)>=10){
                    printf("%c", (int)dec/(int)pow(16,i)+55);
                }
                else{
                printf("%lld",dec/(int)pow(16,i));
                }
                dec=dec%(int)pow(16,i);
            }
            printf("\n");
        }
    }
}