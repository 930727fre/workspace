#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*input
32764
45897458973958
*/

int main(){
    int digit,temp,index;
    char bangla[20];
    while(scanf("%s",bangla)){
        digit=strlen(bangla);
        while(digit){
            index=strlen(bangla)-digit;
            if(digit<2){
                printf("hi");
                printf("%d\n",atoi(&bangla[digit]));
                break;
            }
            else{
                switch ((digit-2)%7){
                    case 0:
                        digit-=2;
                        printf("%c%c kuti ",bangla[digit+2],bangla[digit+1]);
                        break;
                    case 6:
                        digit--;
                        printf("%c kuti ",bangla[digit+1]);
                        break;
                    case 5:
                        digit-=2;
                        printf("%c%c lakh ",bangla[digit+2],bangla[digit+1]);
                        break;
                    case 4:
                        digit--;
                        printf("%c lakh ",bangla[digit+1]);
                        break;
                    case 3:
                        digit-=2;
                        printf("%c%c hajar ",bangla[digit+2],bangla[digit+1]);
                        break;
                    case 2:
                        digit--;
                        printf("%c hajar ",bangla[digit+1]);
                        break;
                    case 1:
                        digit--;
                        printf("%c shata ",bangla[digit+1]);
                        break;
                }
            }
        }
    }
}