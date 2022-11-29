#include <stdio.h>//regex complete
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int buyerMode();
int sellerMode();
int reservedWord(char*,int );
char password[1000]="$", goods[20][2][100];
int main(){
    char mode[100];
    while(1){
        printf("(1)Seller Mode/ (2) Buyer Mode\nenter:");
        fgets(mode,100,stdin);
        fflush(stdin);

        if(mode[0]==49){
            sellerMode();
        }
        else if(mode[0]==50){
            buyerMode();
        }
        else{
            printf("Wrong input!\nPlease input 1, 2, or 3.\n");
        }
    }
    printf("process end");
}

int sellerMode(){
    char cmd[1000],*token,arg[4][1000],temp[1000]="$";
    int quotationFlag,argCounter,j,end, upperFlag=0,lowerFlag=0,numberFlag=0,symbolFlag=0,lengthFlag=0;
    if(strcmp(password,"$")==0){//first time using seller mode.
        for(int i=0;i<20;i++){//initialize the array of goods
            for(int j=0;j<2;j++){
                strcpy(goods[i][j],"0");
            }
        }
        printf("First time using seller mode, please set up a password for vendor.\n");
        do{
            printf("enter:");
            fgets(temp,1000,stdin);
            fflush(stdin);
            upperFlag=0;
            lowerFlag=0;
            numberFlag=0;
            symbolFlag=0;
            lengthFlag=0;
            if(strlen(temp)>=6&&strlen(temp)<=20){
                lengthFlag=1;
            }
            else{
                printf("The length of password should be longer than 6 and shorter than 20\n");
                continue;
            }
            for(int i=0;i<strlen(temp);i++){
                if(isupper(temp[i])){
                    upperFlag=1;
                }
                if(islower(temp[i])){
                    lowerFlag=1;
                }
                if(isgraph(temp[i])&&(!isdigit(temp[i]))&&(!isupper(temp[i]))&&(!islower(temp[i]))){
                    symbolFlag=1;
                }
                if(isdigit(temp[i])){
                    numberFlag=1;
                }                     
            }
            if(!(upperFlag&&lowerFlag&&numberFlag&&symbolFlag)){
                printf("The password must contain number, symbol, upper character, lower character, and only the character below are accepted.(A-Z、a-z、0-9、∼、@、#、_、^、*、%%、/、.、+、:、=)\nPlease input again.\n");
                continue;
            }
        }while(!reservedWord(temp,0)||!(upperFlag&&lowerFlag&&numberFlag&&symbolFlag&&lengthFlag));
        strcpy(password,temp);
        printf("Password set!\n");
        
    }
    printf("Please input the password for seller mode\nenter:");
    fgets(temp,1000,stdin);
    fflush(stdin);    
    while(strcmp(temp,password)!=0){
        printf("Wrong password!\nPlease input again.\nenter:");
        fgets(temp,1000,stdin);
        fflush(stdin);

    }

    while(1){
        printf("seller mode>");
        fgets(cmd,1000,stdin);
        fflush(stdin);

        quotationFlag=0;
        argCounter=-1;
        j=0;//index of each arg[argCount][]
        end=-1;
        for(int i=0;i<4;i++){
            strcpy(arg[i],"-1");
        }

        for(int i=0;i<strlen(cmd);i++){
            if(cmd[i]=='\n'){
                printf("argCounter = %d\n",argCounter);
                break;
            }
            if((!((cmd[i]>=69&&cmd[i]<=90)||(cmd[i]>=97&&cmd[i]<=122)||cmd[i]==32||cmd[i]==34||(cmd[i]>=48&&cmd[i]<=57)||cmd[i]==63))&&i!=0&&i!=strlen(cmd)-1){
                printf("The character %c is prohibited.\nPlease input again.\n",cmd[i]);
                break;
            }

            if(cmd[i]=='"'){
                if(quotationFlag){
                        while(arg[argCounter][j-1]==' '){
                            j--;
                        }
                        arg[argCounter][j]='\0';  
                        j=0; 
                }
                quotationFlag=(!quotationFlag);
            } 
            else if(cmd[i]==' '){
                if(quotationFlag){
                    if(j!=0){
                        arg[argCounter][j]=' ';
                        j++;
                    }
                }
                else if(j!=0){
                    while(arg[argCounter][j-1]==' '){
                        j--;
                    }
                    arg[argCounter][j]='\0';                          
                    j=0;

                }
            }
            else{
                if(j==0){
                    argCounter++;
                    if(argCounter==4){
                        break;
                    }                    
                }
                arg[argCounter][j]=cmd[i];
                j++;
            }
            if(cmd[i+1]=='\n'&&j!=0){
                    while(arg[argCounter][j-1]==' '){
                        j--;
                    }                    
                    arg[argCounter][j]='\0';            
                    j=0;                    
            }
                            
        }  
        for(int i=0;i<=argCounter&&i<4;i++){
            printf("%s\n",arg[i]);   
            printf("strlen(arg[%d] = %lu\n",i,strlen(arg[i]));

        }
        for(int i=0;i<10;i++){
            printf("-");
        }
        printf("\n");
        if(argCounter>3){
            printf("too many arguments\n");
        }
        else if(strcmp(arg[0],"?")==0){
            printf("\ncmds: description\n?: Show the man page of current mode.\nadd <product> <num>: add <product> with <num> quantities.\nbuyer mode: enter buyer mode. \ndelete <product>: delete <product> merchandise.\nexit: exit the script. \nincome: print current total income.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory. \nnew <product> <price> [<num>]: add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default. \npasswd: change the password if original password given is correct.\n\n");
        }
        else if(strcmp(arg[0],"add")==0){
            printf("enter add command\n");        

        }
        else if(strcmp(arg[0],"buyer mode")==0){
            printf("in buyer mode\n");
        }
        else if(strcmp(arg[0],"delete")==0){
        }
        else if(strcmp(arg[0],"exit")==0){
            break;
        }
        else if(strcmp(arg[0],"help")==0){
            printf("\ncmds: description\n?: Show the man page of current mode.\nadd <product> <num>: add <product> with <num> quantities.\nbuyer mode: enter buyer mode. \ndelete <product>: delete <product> merchandise.\nexit: exit the script. \nincome: print current total income.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory. \nnew <product> <price> [<num>]: add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default. \npasswd: change the password if original password given is correct.\n\n");
        }
        else if(strcmp(arg[0],"income")==0){
            
        }
        else if(strcmp(arg[0],"list")==0){
            printf("enter list command\n");
        }
        else if(strcmp(arg[0],"new")==0){
            //cmdCheck(cmd,0);
        }
        else if(strcmp(arg[0],"passwd")==0){
            
        }
        else{
            printf("No such command!\n");
        }
    }    
    return 0;
}

int reservedWord(char* str, int mode){
    for(int i=0;i<strlen(str)-1;i++){
        int temp=str[i];
        if(mode==0){//reserved word of password input
            if(!((temp>=65&&temp<=90)||(temp>=97&&temp<=122)||(temp>=48&&temp<=57)||strpbrk(str,"~@#_^*%%/.+:="))){
                printf("The characters ~@#_^*%%/.+:= are prohibited.\nPlease input again\n");
                return 0;
            }
        }
        else if(mode==2){//reserved word of command input
            if(!((temp>=69&&temp<=90)||(temp>=97&&temp<=122)||temp==32||(temp>=48&&temp<=57)||temp==63)){
                printf("The character %c is prohibited.\nPlease input again.\n",temp);
                return 0;
            }
        }
    }
    return 1;
}

int buyerMode(){
    return 0;
}
