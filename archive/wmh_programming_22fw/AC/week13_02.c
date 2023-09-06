#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*input
DPP,KMT,loli,hentai,Tsai EE,VTuber
*/

int cmp(char*,char*);

int main(){
    char str[550],topic[100][100],ban[100][100],*token;
    int banMaxIndex=0,topicMaxIndex=0,counter;
    fgets(str,500,stdin);
    fflush(stdin);
    str[strlen(str)-1]='\0';
    token=strtok(str,",");
    strcpy(ban[banMaxIndex],token);
    while(token){
        token=strtok(NULL,",");
        if(token){
            banMaxIndex++;
            strcpy(ban[banMaxIndex],token);
        }

    }

    for(int i=0;i<=banMaxIndex;i++){
        //printf("\"%s\"\n",ban[i]);
    }

    while(fgets(str,550,stdin)){
        counter=0;
        topicMaxIndex=0;
        fflush(stdin);
        str[strlen(str)-1]='\0';
        token=strtok(str,",");
        //printf("token = %s\n",token);
        strcpy(topic[topicMaxIndex],token);
        while(token){
            token=strtok(NULL,",");
            if(token){
                topicMaxIndex++;
                strcpy(topic[topicMaxIndex],token);
            }

        }
        /*for(int i=0;i<10;i++){
            printf("-");
        }
        printf("\n");
        for(int i=0;i<=topicMaxIndex;i++){
            printf("%s\n",topic[topicMaxIndex]);
        }*/
        for(int i=0;i<=topicMaxIndex&&counter<=3;i++){
            for(int j=0;j<=banMaxIndex&&counter<=3;j++){
                if(cmp(topic[i],ban[j])){
                    counter++;
                    //printf("snitch: %s\n",topic[i]);
                    break;
                }

            }
        }
        //printf("\n");
        if(counter==1||counter==2){
            printf("WARNING\n");
        }
        else if(counter>=3){
            printf("DANGER\n");
        }  
        else{
            printf("SAFE\n");
        }      
           
    }

}

int cmp(char* topic, char* ban){
    //printf("topic = %s\n",topic);
    if(strlen(topic)!=strlen(ban)){
        //printf("%s %s|length error\n",topic,ban);
        return 0;
    }
    for(int i=0;i<strlen(topic);i++){
        if(!(tolower(topic[i])==tolower(ban[i]))){
            //printf("%s %s|%c %cerror\n",topic,ban,topic[i],ban[i]);
            return 0;
        }
    }
    return 1;
}

/*
0A
HENTAI,VTuber
DPP,KP,kmt,Korean Fish,Tsai EE

*/