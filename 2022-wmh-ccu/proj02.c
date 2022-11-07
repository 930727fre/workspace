#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateFourRandomNumber(int arr[4]);

int main(){
    int mode,temp,input[4],a,b;
    char ctemp;
    srand(time(NULL));
    while(1){
        printf("Mode:(1)Answer/(2)Guessing?\ninput:");
        scanf("%d",&mode);
        //mode=2;
        if(mode!=1&&mode!=2){
            printf("Please enter the number 1 or 2\n");
            continue;
        }
        else if(mode==1){   
            


        }
        else{
            int arr[4];
            generateFourRandomNumber(arr);
            printf("arr[]=");
            for(int i=0;i<4;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            while(1){
                temp=0;
                for(int i=0;i<4;i++){
                    if(i==0){
                        printf("Guess four number:\nenter:");
                    }
                    scanf(" %c",&ctemp);
                    if(ctemp<48||ctemp>57){
                        printf("Only integer between 0 to 9 is permitted.\nPlease enter again.\n");
                        i=-1;
                        continue;
                    }
                    else{
                        input[i]=ctemp-48;
                    }
                }
                a=0;
                b=0;
                for(int i=0;i<4;i++){
                    if(arr[i]==input[i]){
                        a++;
                    }
                    else{
                        temp=0;
                        for(int j=0;j<4;j++){
                            if(input[i]==arr[j]){
                                temp=1;
                                break;
                            }
                        }
                        if(temp==1){
                            b++;
                        }
                    }
                }
                if(a==4){
                    printf("YOU WIN\n");
                    break;
                }
                else{
                    printf("%dA%dB\n",a,b);
                }
            }
        }
    }
}

void generateFourRandomNumber(int ax[4]){
    int temp;
    for(int i=0;i<4;i++){
        ax[i]=-1;
    }
    for(int i=0;i<4;i++){
        temp=rand() % (9-0 + 1) + 0;
        while(ax[0]==temp||ax[1]==temp||ax[2]==temp||ax[3]==temp){
            temp=rand() % (9-0 + 1) + 0;
        }
        ax[i]=temp;
    }
}
