#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void generateFourRandomNumber(int *ax);
int verify(int ax,int bx);
int extract(int ax,int bx);
int manualVerify(int ax);
char ctemp;

int main(){
    int temp,counter,upperIndex,index,flag,verificationCode;
    int arr[5040],ans;
    char ctemp;
    srand(time(NULL));
    while(1){
        //printf("Mode:(1)Answer/(2)Guessing?\ninput:");
        //scanf("%d",mode);
        ctemp=48;
        if(ctemp!=48&&ctemp!=49){
            printf("Only integer 1 and 2 is permitted.\nPlease enter again.\n");
            continue;
        }
        else if(ctemp==48){//Answer mode
            generateFourRandomNumber(&ans);
            printf("ans= ");
            if(ans/1000==0){
                printf("0");
            }
            printf("%d\n",ans);
            temp=0;
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        for(int l=0;l<10;l++){
                            if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
                                arr[temp]=1000*i+100*j+10*k+l;
                                temp++;
                            }
                        }
                    }
                }
            }
            index=5040-1;
            upperIndex=0;
            verificationCode=verify(arr[5039],ans);
            printf("ask: %d\n",arr[index]);
            while(index!=0){
                //printf("index= %d\n",index);
                if(verificationCode==40){
                    break;
                }
                upperIndex=0;
                if(verificationCode==verify(arr[index],arr[index-1])){
                    while(verificationCode==verify(arr[index],arr[upperIndex])){
                        if(upperIndex==index-1){
                            verificationCode=verify(arr[index-1],ans);
                            printf("ask: ");
                            if(arr[index-1]<1000){
                                printf("0");
                            }
                            printf("%d\n",arr[index-1]);
                            break;
                        }
                        upperIndex++;
                    }
                    if(verificationCode==40){
                        break;
                    }                
                    if(upperIndex!=index-1){
                        arr[upperIndex]=arr[index-1];
                        arr[index-1]=arr[index];
                    }
                }
                else{
                    arr[index-1]=arr[index];
                }
                index--;
            }
            if(verificationCode!=40){
                printf("Cheat!\n");
            }
            else{
                printf("Jackpot! ");
                if(ans/1000==0){
                    printf("0");
                }
                printf("%d\n",ans);                

            }
            break;
        }        
        
    }
}

void generateFourRandomNumber(int *ax){
    int a=0,b=0,c=0,d=0;
    while(a==b||a==c||a==d||b==c||b==d||c==d){
        a=rand() % (9-0 + 1) + 0;
        b=rand() % (9-0 + 1) + 0;
        c=rand() % (9-0 + 1) + 0;
        d=rand() % (9-0 + 1) + 0;
    }
    *ax=1000*a+100*b+10*c+d;
}

int verify(int ax, int bx){
    int a=0,b=0;
    for(int i=0;i<4;i++){
        if(extract(ax,i)==extract(bx,i)){
            a++;
        }
        for(int j=0;j<4;j++){
            if(j==i){
                continue;
            }
            else if(extract(ax,j)==extract(bx,i)){
                b++;
            }
        }
    }
    return a*10+b;
}

int extract(int ax, int bx){
    int temp;
    for(int i=0;i<4;i++){
        if(bx==i){
            return (int)(ax%10);
        }
        ax=(int)(ax/10);        

    }
    return 0;
}

int manualVerify(int ax){
    char ca,cb;
    printf("the programe guess: ");
    if(ax<1000){
        printf("0");
    }
    printf("%d\n",ax);
    printf("Please input the A and Bs\nenter:");
    scanf(" %c%c",&ca,&cb);
    printf("\n");
    while(ca<48||cb<48||ca>53||cb>53||96<ca+cb||ca+cb<101){
        printf("Only integers between 0 to 4 is permitted and 0<=A+B<=4.\nPlease input again\nenter:");
        scanf(" %c%c",&ca,&cb);
    }
    return 10*(ca-48)+(cb-48);
}