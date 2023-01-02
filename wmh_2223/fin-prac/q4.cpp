#include <stdio.h>
#include <string.h>
/*input
2
Hey good lawyer
as I previously previewed
yam does a soup
First I give money to Teresa
after I inform dad of
your horrible soup
*/
int main(){
    char str[1000],*token;
    int t,counter,flag;
    scanf(" %d",&t);
    for(int i=0;i<t;i++){
        printf("Case #%d:\n",i+1);
        flag=0;
        fflush(stdin);
        while(fgets(str,1000,stdin)!=NULL){
            fflush(stdin);
            counter=0;
            if(strlen(str)==1){
                if(flag){
                    printf("\n");
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                flag=1;
                token=str;
                while(token[0]==' '){
                    token=&token[1];
                }
                strtok(token," ");
                //printf("%s %d\n",token,strlen(token));
                if(strlen(token)>=counter+1){
                    printf("%c",token[counter]);
                    counter++;
                }
                while(1){
                    token = strtok(NULL," ");
                    if(token){
                        //printf("%s %lu\n",token,strlen(token));
                        if(strlen(token)>=counter+1){
                            printf("%c",token[counter]);
                            counter++;
                        }                     
                    }
                    else{
                        printf("\n");
                        break;
                    }

                }
                                               
            }

        }
    }
    
}