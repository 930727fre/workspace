#include <stdio.h>
#include <string.h>

int main(){
    char a[251], b[251], c[502];
    int index,numA,numB, lenA, lenB;
    scanf("%s %s",a,b);
    lenA=strlen(a);
    lenB=strlen(b);
    for(int i=0;i<502;i++){
        c[i]=0;
    }
    for(int i=lenA-1;i>=0;i--){
        for(int j=lenB-1;j>=0;j--){
            numA=a[i]-'0';
            numB=b[j]-'0';
            c[i+j]+=numA*numB;
            c[i+j-1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }

    for(int i=0;i<502;i++){
        c[i]+='0';
    }
    if(c[0]==0){
        for(int i=0;i<500;i++){
            c[i]=c[i+2];
        }
        c[lenA+lenB]=0;
    }    
    else{
        c[lenA+lenB-1]=0;
    }
    printf("%s\n",c);
}