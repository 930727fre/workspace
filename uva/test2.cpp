#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*input
23764
45897458973958
*/

int main(){
    int digit,temp,index,counter=1;
    char bangla[20];
    while(scanf("%s",bangla)){
        printf("%d. ",counter++);

        digit=strlen(bangla);
        while(digit){
            index=strlen(bangla)-digit;
            if(digit<=2){
                printf("%d\n",atoi(&bangla[strlen(bangla)-digit]));
                break;
            }
            else{
                switch ((digit-2)%7){
                    case 0:
                        digit-=2;
                        if(bangla[strlen(bangla)-(digit+2)]=='0'){
                            printf("%c kuti ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        else{
                            printf("%c%c kuti ",bangla[strlen(bangla)-(digit+2)],bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                    case 6:
                        digit--;
                        if(bangla[strlen(bangla)-(digit+1)]!='0'){
                            printf("%c kuti ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                    case 5:
                        digit-=2;
                        if(bangla[strlen(bangla)-(digit+2)]=='0'){
                            printf("%c lakh ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        else{
                            printf("%c%c lakh ",bangla[strlen(bangla)-(digit+2)],bangla[strlen(bangla)-(digit+1)]);
                        }                        break;
                    case 4:
                        digit--;
                        if(bangla[strlen(bangla)-(digit+1)]!='0'){
                            printf("%c lakh ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                    case 3:
                        digit-=2;
                        if(bangla[strlen(bangla)-(digit+2)]=='0'){
                            printf("%c hajar ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        else{
                            printf("%c%c hajar ",bangla[strlen(bangla)-(digit+2)],bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                    case 2:
                        digit--;
                        if(bangla[strlen(bangla)-(digit+1)]!='0'){
                            printf("%c hajar ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                    case 1:
                        digit--;
                        if(bangla[strlen(bangla)-(digit+1)]!='0'){
                            printf("%c shata ",bangla[strlen(bangla)-(digit+1)]);
                        }
                        break;
                }
            }
        }
    }
}