#include <stdio.h>
#include <string.h>

int gcd(int, int);
int main(){
    int n,num1,num2;
    char str1[1000],str2[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        num1=0;
        num2=0;
        scanf("%s",str1);
        scanf("%s",str2);
        for(int j=0;j<strlen(str1);j++){
                num1 = num1<<1;
            if(str1[j]-'0'){
                num1+=1;
            }
        }
        for(int j=0;j<strlen(str2);j++){
                num2 = num2<<1;
            if(str2[j]-'0'){
                num2+=1;
            }
        }
        printf("Pair #%d: ",i+1);
        if(gcd(num1,num2)==1){
            printf("Love is not all you need!\n");
        }
        else{
            printf("All you need is love!\n");
        }        
    }
}

int gcd(int a, int b){
    int temp=1;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}