#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merchandise[1000];
int buyerMode();
int sellerMode();
int inverse(int);
void slice(char*,char*);
int Index;
int main(){
    char mode;
    while(1){
        printf("(1)Seller Mode/ (2) Buyer Mode\nenter:");
        scanf(" %c",&mode);
        if(mode==49){
            sellerMode();
        }
        else if(mode==50){
            buyerMode();
        }
        else{
            printf("Wrong input!\nPlease input 1, 2, or 3.\n");
        }
    }
    printf("process end");
}

int sellerMode(){
    char cmd[1000],*token,*ptr,arg[4][1000],*tokenTemp;
    int quotationFlag,quotationCounter,argCounter;


    while(1){
        fflush(stdin);
        printf("seller mode>");
        fgets(cmd,1000,stdin);
        quotationFlag=1;
        quotationCounter=0;
        argCounter=0;
        for(int i=0;i<4;i++){
            strcpy(arg[i],"-1");
        }
        ptr=strpbrk(cmd,"\"");
        while(ptr){
            quotationCounter++;
            ptr=strpbrk(ptr+1,"\"");
        }
        if(quotationCounter==0){
            token=strtok(cmd," ");
            while(token){
                if(argCounter==4){
                    strcpy(arg[argCounter],"-1");//result in warning.
                    break;
                }
                strcpy(arg[argCounter],token);
                argCounter++;
                token=strtok(NULL," ");
                //printf("%d %s\n",argCounter,token);
            }
        }
        else{
            token=strtok(cmd,"\"");
            while(token){
                tokenTemp=strtok(token," ");
                while(!quotationFlag){
                    
                }
            }
        }
        char tempString[1000];
        strcpy(tempString,strtok(arg[argCounter-1],"\n"));//delete "\n" in the fgets
        strcpy(arg[argCounter-1],tempString);
        printf("args[]\n");
        for(int i=0;i<4;i++){
            printf("%s\n",arg[i]);
        }
        break;
    }



    /*
        if(strncmp(cmd,"?",strlen(cmd)-1)==0){
            printf("\ncmds: description\n?: Show the man page of current mode.\nadd <product> <num>: add <product> with <num> quantities.\nbuyer mode: enter buyer mode. \ndelete <product>: delete <product> merchandise.\nexit: exit the script. \nincome: print current total income.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory. \nnew <product> <price> [<num>]: add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default. \npasswd: change the password if original password given is correct.\n\n");
        }
        else if(strncmp(cmd,"add",3)==0){///////////////////
            printf("enter add command\n");        

        }
        else if(strncmp(cmd,"buyer mode",strlen(cmd)-1)==0){

        }
        else if(strncmp(cmd,"delete",6)==0){
        }
        else if(strncmp(cmd,"exit",strlen(cmd)-1)==0){
            
        }
        else if(strncmp(cmd,"help",strlen(cmd)-1)==0){
            
        }
        else if(strncmp(cmd,"income",strlen(cmd)-1)==0){
            
        }
        else if(strncmp(cmd,"list",4)==0){
            //cmdCheck(cmd,0);
        }
        else if(strncmp(cmd,"new",3)==0){
            //cmdCheck(cmd,0);
        }
        else if(strncmp(cmd,"passwd",strlen(cmd)-1)==0){
            
        }
        else{
            printf("Wrong input!\n");
        }
    }    
    */


    return 0;
}

int buyerMode(){
    return 0;
}

int inverse(int a){
    if(a){
        return 0;
    }
    else{
        return 1;
    }
}

/*
cmds/description
?/ Show the man page of current mode.
add <product> <num>/ add <product> with <numb> quantities.
buyer mode/ enter buyer mode.
delete <product>/ delete <product> merchandise.
exit/ exit the script.
income/ print current total income.
list [inc|dec] [name|price|quantity]/ show the list of merchandises, including goods name, price, and inventory.
new <product> <price> [<num>]/ add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default.
passwd/ change the password if original password is given correct.
*/