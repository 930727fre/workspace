#include <stdio.h>//buy quantity <0 eroor/ dec list error
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int buyerMode();
int sellerMode();
int reservedWord(char*,int );
int argumentWarning(int);
int stringIsDigit(char*);
void sort(char*);
void passwd(void);
char password[1000]="$";
int changePasswordFlag=0,goodsIndex=0,income=0;
typedef struct{
    char name[32];
    int price ;
    int quantity;
} merchandise;

merchandise goods[20]; //initialize the inventory
merchandise goodsTemp;
int main(){

    char mode[100];
    for(int i=0;i<20;i++){
        strcpy(goods[i].name,"");
        goods[i].price=0;
        goods[i].quantity=0;
    }

    while(1){
        printf("(1)Seller Mode/ (2) Buyer Mode\nenter:");
        fgets(mode,100,stdin);
        fflush(stdin);

        if(mode[0]==49){
            if(!sellerMode()){
                break;
            }
        }
        else if(mode[0]==50){
            if(!buyerMode()){
                break;
            }            
        }
        else{
            printf("Wrong input!\nPlease input 1, 2, or 3.\n");
        }
    }
    printf("process end");
}

int sellerMode(){
    char cmd[1000],*token,arg[4][1000],temp[1000]="$";
    int quotationFlag,argCounter,j,index,errorInputFlag=0;

    if(!changePasswordFlag){
        passwd();
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
        errorInputFlag=0;
        j=0;//index of each arg[argCount][]
        for(int i=0;i<4;i++){
            strcpy(arg[i],"-1");
        }
        for(int i=0;i<strlen(cmd);i++){
            if(cmd[i]=='\n'){
                //printf("argCounter = %d\n",argCounter);
                break;
            }
            if((!((cmd[i]>=69&&cmd[i]<=90)||(cmd[i]>=97&&cmd[i]<=122)||cmd[i]==32||cmd[i]==34||(cmd[i]>=48&&cmd[i]<=57)||cmd[i]==63))&&i!=0&&i!=strlen(cmd)-1){
                printf("The character %c is prohibited.\nPlease input again.\n",cmd[i]);
                errorInputFlag=1;
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
        //printf("argCounter==%d\n",argCounter);
        if(argCounter==-1){
            continue;
        }
        if(errorInputFlag){
            continue;
        }  
        
        if(argCounter>3){//stag(start argument)
            argumentWarning(1);
            continue;
        }
        else if(strcmp(arg[0],"?")==0){
            printf("\ncmds: description\n?: Show the man page of current mode.\nadd <product> <num>: add <product> with <num> quantities.\nbuyer mode: enter buyer mode. \ndelete <product>: delete <product> merchandise.\nexit: exit the script. \nincome: print current total income.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory. \nnew <product> <price> [<num>]: add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default. \npasswd: change the password if original password given is correct.\n\n");
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
        }
        else if(strcmp(arg[0],"add")==0){
            if(argCounter>2){
                argumentWarning(1);
                continue;
            }             
            if(argCounter<2){
                argumentWarning(0);
                continue;
            }
            if(!stringIsDigit(arg[2])){
                printf("Only digits are acceptable in <num> argument\n");
                continue;
            }

            //printf("enter add command\n");

            for(int i=0;i<=goodsIndex;i++){
                if(strcmp(goods[i].name,arg[1])==0){
                    if(goods[i].quantity+atoi(arg[2])>1000){
                        printf("The maximum quantity of \"%s\" is 1000, %d remaining.\nPlease input again.\n",goods[i].name,1000-goods[i].quantity);
                    }
                    else{
                        goods[i].quantity+=atoi(arg[2]);
                    }
                    break;
                }
                else if(i==goodsIndex){
                    printf("Product \"%s\" can't be found in the inventory.\n",arg[1]);
                }
            }
        }
        else if(strcmp(arg[0],"buyer mode")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
            //printf("enter buyer mode command\n");
            if(!buyerMode()){
                return 0;
            }
        }
        else if(strcmp(arg[0],"delete")==0){
            if(argCounter>1){
                argumentWarning(1);
                continue;

            }
            else if(argCounter<1){
                argumentWarning(0);
                continue;

            }
            //printf("enter delete command\n");
            for(int i=0;i<=goodsIndex;i++){
                if(!strcmp(goods[i].name,arg[1])){
                    for(int j=i;j<goodsIndex;j++){
                        goods[j]=goods[j+1];
                    }
                    strcpy(goods[goodsIndex].name,"-1");
                    goods[goodsIndex].price=0;
                    goods[goodsIndex].quantity=0;
                    goodsIndex--;
                    break;
                }
                if(i==goodsIndex){
                    printf("Product \"%s\" can't be found in inventory\n",arg[1]);
                }
            }

        }
        else if(strcmp(arg[0],"exit")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
            return 0;
        }
        else if(strcmp(arg[0],"help")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
            printf("\ncmds: description\n?: Show the man page of current mode.\nadd <product> <num>: add <product> with <num> quantities.\nbuyer mode: enter buyer mode. \ndelete <product>: delete <product> merchandise.\nexit: exit the script. \nincome: print current total income.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory. \nnew <product> <price> [<num>]: add item <product_name> with price <price> and number <num>. if <quantity> is skipped, the number is set 0 by default. \npasswd: change the password if original password given is correct.\n\n");
        }
        else if(strcmp(arg[0],"income")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }    
            //printf("enter income command\n");
            printf("income = %d\n",income);

        }
        else if(!strcmp(arg[0],"list")){
            if(argCounter==0){
                strcpy(arg[2],"name");
                strcpy(arg[1],"inc");
                sort(arg[2]);
            }
            else if(argCounter==1){
                if(strcmp(arg[1],"inc")&&strcmp(arg[1],"dec")&&strcmp(arg[1],"name")&&strcmp(arg[1],"price")&&strcmp(arg[1],"quantity")){
                        printf("<%s> argument is not acceptable.\n",arg[1]);
                        continue;                    
                }
                else if(!strcmp(arg[1],"inc")&&!strcmp(arg[1],"dec")){
                    strcpy(arg[2],"name");
                    strcpy(arg[1],"inc");
                }
                sort(arg[2]);                    
            }
            else if(argCounter==2){
                    if(strcmp(arg[1],"inc")&&strcmp(arg[1],"dec")){
                        printf("<%s> argument is not acceptable.\n",arg[1]);
                        continue;
                    }
                    else{
                        sort(arg[2]);
                    }                
            }
            else {
                argumentWarning(1);
                continue;                
            }  
            //printf("enter list command\n");
            printf("---product/price/quantity---\n");
            if(!strcmp(arg[1],"dec")){
                for(int i=goodsIndex-1;i>=0;i--){
                    printf("%s %d %d\n",goods[i].name,goods[i].price,goods[i].quantity);
                }                
            }
            else if(!strcmp(arg[1],"inc")){
                for(int i=0;i<goodsIndex;i++){
                    printf("\"%s\" %d %d\n",goods[i].name,goods[i].price,goods[i].quantity);
                }                
            }
        }
        else if(strcmp(arg[0],"new")==0){
            if(argCounter>3){
                argumentWarning(0);
                continue;
            } 
            if(argCounter<2){
                argumentWarning(0);
                continue;
            }
            if(!stringIsDigit(arg[2])){
                printf("Only digits are acceptable in <price> argument\n");
                continue;
            }
            if(!stringIsDigit(arg[3])&&argCounter==3){
                printf("Only digits are acceptable in <quantity> argument\n");
                continue;
            }            

            if(goodsIndex==20){
                printf("The inventory is full, try delete some product before adding new product in the vending machine\n");
                continue;
            }
            int inInventoryFlag=0;
            for(int i=0;i<=goodsIndex;i++){
                if(!strcmp(goods[i].name,arg[1])){
                    printf("Product \"%s\" is already added in the inventory, please try another name.\n",arg[1]);
                    inInventoryFlag=1;
                    break;
                }
            }
            if(inInventoryFlag){
                continue;
            }
            if(atoi(arg[2])>10000){
                printf("The price of \"%s\" should be lower than 10000.\nPlease input again.\n",arg[1]);
                continue;
            }
            //printf("enter new command\n");
            if(strcmp(arg[3],"-1")){
                if(!stringIsDigit(arg[2])){
                    printf("Only digits are acceptable in <num> argument\n");
                    continue;
                }
                goods[goodsIndex].quantity=atoi(arg[3]);
            }
            else{
                goods[goodsIndex].quantity=0;                
            }
            strcpy(goods[goodsIndex].name,arg[1]);
            goods[goodsIndex].price=atoi(arg[2]);            
            goodsIndex++;
        }
        else if(strcmp(arg[0],"passwd")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            } 
            //printf("enter passwd command\n");
            printf("Please input the original password in order to change the password.\nenter:");
            fgets(temp,1000,stdin);
            fflush(stdin);    
            if(!strcmp(temp,password)){
                passwd();
            }
            else{
                printf("Wrong password!\n");
            }
        }
        else{
            printf("No \"%s\" command!\n",arg[0]);
        }
    }    
    return 1;
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
        else if(mode==1){//reserved word of command input
            if(!((temp>=69&&temp<=90)||(temp>=97&&temp<=122)||temp==32||(temp>=48&&temp<=57)||temp==63)){
                printf("The character %c is prohibited.\nPlease input again.\n",temp);
                return 0;
            }
        }
    }
    return 1;
}
int argumentWarning(int a){
    if(a){
        printf("There were too many arguments\n");
    }
    else{
        printf("There were too few arguments\n");
    }
    return 0;
}

void passwd(void){
    char temp[100];
    int upperFlag=0,lowerFlag=0,numberFlag=0,symbolFlag=0,lengthFlag=0;
    if(!changePasswordFlag){//first time using seller mode.
        printf("First time using seller mode, please set up a password for vendor.\n");
    }
    else{
        printf("Please input the new password\nenter:");
    }
    do{
        printf("enter:");
        fgets(temp,1000,stdin);
        fflush(stdin);
        upperFlag=0;
        lowerFlag=0;
        numberFlag=0;
        symbolFlag=0;
        lengthFlag=0;
        if(strlen(temp)>=7&&strlen(temp)<=21){//there's a \n in temp
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
    changePasswordFlag++;
        
}

void sort(char* order){
    printf("sort by %s\n",order);
    if(strcmp(order,"name")==0){
        
        for(int i=0;i<goodsIndex;i++){
            for(int j=0;j<goodsIndex-i-1;j++){
                if(goods[j].name[0]>goods[j+1].name[0]){
                    goodsTemp=goods[j];
                    goods[j]=goods[j+1];
                    goods[j+1]=goodsTemp;
                }
            }
        }
    }
    else if(strcmp(order,"price")==0){
        for(int i=0;i<goodsIndex;i++){
            for(int j=0;j<goodsIndex-i-1;j++){
                if(goods[j].price==goods[j+1].price&&goods[j].name[0]>goods[j+1].name[0]){
                    goodsTemp=goods[j];
                    goods[j]=goods[j+1];
                    goods[j+1]=goodsTemp;
                }
                else if(goods[j].price>goods[j+1].price){
                    goodsTemp=goods[j];
                    goods[j]=goods[j+1];
                    goods[j+1]=goodsTemp;
                }
            }
        }
    }
    else if(strcmp(order,"quantity")==0){
        for(int i=0;i<goodsIndex;i++){
            for(int j=0;j<goodsIndex-i-1;j++){
                if(goods[j].quantity==goods[j+1].quantity&&goods[j].name[0]>goods[j+1].name[0]){
                    goodsTemp=goods[j];
                    goods[j]=goods[j+1];
                    goods[j+1]=goodsTemp;
                }                
                else if(goods[j].quantity>goods[j+1].quantity){
                    goodsTemp=goods[j];
                    goods[j]=goods[j+1];
                    goods[j+1]=goodsTemp;
                }
            }
        }
    }     
}
int stringIsDigit(char *str){
    for(int i=0;i<strlen(str);i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}
int buyerMode(){
    int j=0,quotationFlag=0,argCounter=-1;
    char arg[4][1000],cmd[1000];
   
    while(1){
        printf("buyer mode>");
        fgets(cmd,1000,stdin);
        fflush(stdin);
        quotationFlag=0;
        argCounter=-1;
        j=0;//index of each arg[argCount][]
        for(int i=0;i<4;i++){
            strcpy(arg[i],"-1");
        }
        for(int i=0;i<strlen(cmd);i++){
            if(cmd[i]=='\n'){
                //printf("argCounter = %d\n",argCounter);
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

        if(argCounter==-1){
            continue;
        }
        if(!strcmp(arg[0],"seller mode")){
            if(!sellerMode()){
                return 0;
            }
        }
        else if(strcmp(arg[0],"buy")==0){
            if(argCounter>2){
                argumentWarning(1);
                continue;
            }             
            if(argCounter<2){
                argumentWarning(0);
                continue;
            }
            if(!stringIsDigit(arg[2])){
                printf("Only digits are acceptable in <quantity> argument\n");
                continue;
            }
            //printf("enter buy command\n");

            for(int i=0;i<=goodsIndex;i++){
                if(strcmp(goods[i].name,arg[1])==0){
                    goods[i].quantity-=atoi(arg[2]);
                    income+=atoi(arg[2])*goods[i].price;
                    break;
                }
                else if(i==goodsIndex){
                    printf("Product \"%s\" can't be found in the inventory.\n",arg[1]);
                }
            }
        }     
        else if(strcmp(arg[0],"?")==0){
            printf("\ncmds: description\n?: Show the man page of current mode.\nhelp: Show the man page of current mode.\nseller mode: enter seller mode.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory.\nbuy <product> <num>: buy <num> quantity of <product>.\n\n");
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
        }
        else if(strcmp(arg[0],"help")==0){
            if(argCounter>0){
                argumentWarning(1);
                continue;
            }
            printf("\ncmds: description\n?: Show the man page of current mode.\nhelp: Show the man page of current mode.\nseller mode: enter seller mode.\nlist [inc|dec] [name|price|quantity]: show the list of merchandises, including goods name, price, and inventory.\nbuy <product> <num>: buy <num> quantity of <product>.\n\n");
        }                
        else if(!strcmp(arg[0],"list")){
            if(argCounter==0){
                strcpy(arg[2],"name");
                strcpy(arg[1],"inc");
                sort(arg[2]);
            }
            else if(argCounter==1){
                if(strcmp(arg[1],"inc")&&strcmp(arg[1],"dec")&&strcmp(arg[1],"name")&&strcmp(arg[1],"price")&&strcmp(arg[1],"quantity")){
                        printf("<%s> argument is not acceptable.\n",arg[1]);
                        continue;                    
                }
                else if(!strcmp(arg[1],"inc")&&!strcmp(arg[1],"dec")){
                    strcpy(arg[2],"name");
                    strcpy(arg[1],"inc");
                }
                sort(arg[2]);                    
            }
            else if(argCounter==2){
                    if(strcmp(arg[1],"inc")&&strcmp(arg[1],"dec")){
                        printf("<%s> argument is not acceptable.\n",arg[1]);
                        continue;
                    }
                    else{
                        sort(arg[2]);
                    }                
            }
            else {
                argumentWarning(1);
                continue;                
            }  
            //printf("enter list command\n");
            printf("---product/price/quantity---\n");
            if(!strcmp(arg[1],"dec")){
                for(int i=goodsIndex-1;i>=0;i--){
                    printf("%s %d %d\n",goods[i].name,goods[i].price,goods[i].quantity);
                }                
            }
            else if(!strcmp(arg[1],"inc")){
                for(int i=0;i<goodsIndex;i++){
                    printf("\"%s\" %d %d\n",goods[i].name,goods[i].price,goods[i].quantity);
                }                
            }
        }
        else{
            printf("No \"%s\" command!\n",arg[0]);
        }        
    }
    return 0;
}

