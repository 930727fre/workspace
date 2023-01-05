#include <stdio.h>
#include <string.h>
#include <ctype.h>// doesn't work on judge
#include <stdlib.h>
int main(){
    int t,flag=0,index;
    char str[1000],*token;
    fgets(str,1000,stdin);
    t=atoi(str);
    fflush(stdin);
    //t=5;
    for(int caseCounter=1;caseCounter<=t;caseCounter++){
        printf("Case #%d:\n",caseCounter);
        while(fgets(str,1000,stdin)!=NULL){
            fflush(stdin);
            if(str[0]=='\n'){
                if(!flag){
                    flag=1;
                    continue;
                }
                else{
                    break;
                }
            }
            else{
                index=0;
                for(int i=0;i<strlen(str);i++){//check if there are spaces at the front of str
                    if(str[i]!=' '){
                        token=strtok(&str[i]," \n");
                        break;
                    }
                }
                while(token!=NULL){
                    if(strlen(token)>=index+1){
                        printf("%c",token[index]);
                        index++;
                    }
                    token=strtok(NULL," ");
                }
                printf("\n");
            }
        }
        if(caseCounter!=t){
            printf("\n");
        }
    }
}
/*
Hey good lawyer
as I previously previewed
yam does a soup
First I give money to Teresa
after I inform dad of
your horrible soup*/