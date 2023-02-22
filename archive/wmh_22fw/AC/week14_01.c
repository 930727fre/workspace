#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*input
999999999999999999999
9
9999999999999999999999999999998
837
0
*/

int fc(char*);
int flag;
int main(){
    char str[1000];
    int ans;
    while(1){
        scanf("%s",str);
        if(!strcmp(str,"0")){
            break;
        }
        else{
            printf("%s ",str);
            flag=0;
            ans=fc(str);
            if(!ans){
                printf("is not a multiple of 9.\n");
            }
            else{
                printf("is a multiple of 9 and has 9-degree %d.\n",ans);
            }
        }
    }
}

int fc(char *str){
    int sum=0,temp,numOfDigit;
    for(int i=0;i<strlen(str);i++){
        sum+=str[i]-48;
    }
    //printf("sum = %d\n",sum);
    if(sum==9){
        return flag+1;
    }
    else if(sum%9!=0){
        if(!flag){
            return 0;
        }
        else{
            return flag;
        }
    }
    else{
        temp=sum;
        numOfDigit=1;
        while(1){
            temp=temp/10;
            if(temp){
                numOfDigit++;
            }
            else{
                break;
            }
        }
        str[numOfDigit]='\0';
        for(int i=0;i<numOfDigit;i++){
            str[numOfDigit-i-1]=48+sum%10;
            sum=sum/10;
        }
        //printf("sum of sum = %s\n",str);
        flag++;
        return fc(str);
    }
}