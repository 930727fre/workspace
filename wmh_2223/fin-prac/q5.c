#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n,isOdd,sum,temp;
    char str[4];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<4;j++){
            scanf("%s",str);
            isOdd=1;
            for(int k=0;k<4;k++){
                if(isOdd){
                    temp=2*(str[k]-'0');
                    if(temp>=10){
                        sum+=temp/10;
                    }
                    sum+=temp%10;
                    isOdd=0;
                }
                else{
                    sum+=(str[k]-'0');
                    isOdd=1;
                }
            }           
        }
        if(sum%10!=0){
            printf("Invalid\n");
        }
        else{
            printf("Valid\n");
        }
    }
}

/*
2
5181 2710 9900 0012
5181 2710 9900 0017
*/