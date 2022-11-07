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
    srand(time(NULL));
    //printf("extract 512 3 %d\n",extract(512,3));
    while(1){
        generateFourRandomNumber(&ans);
        printf("Mode:(1)Answer/(2)Guessing?\ninput:");
        scanf(" %c",&ctemp);
        if(ctemp!=49&&ctemp!=50){
            printf("Only integer 1 and 2 is permitted.\nPlease enter again.\n");
            continue;
        }
        else if(ctemp==49){//Answer mode
            printf("Answer mode\nans= ");
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
                printf("PC WIN\n");
                if(ans/1000==0){
                    printf("0");
                }
                printf("%d\n",ans);                

            }
        }
        else{
            printf("ans= ");
            if(ans/1000==0){
                printf("0");
            }
            printf("%d\n",ans);     
            while(1){
                temp=0;
                /*for(int i=0;i<4;i++){
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
                        arr[1]+=(ctemp-48)*(int)pow(10,4-i);
                    }
                    for(int j=1;j<i+1;j++){
                        if(extract(arr[1],j)==extract(arr[1],0)){
                            printf("This number is used. Please change a number.\n");
                            i=-1;
                            continue;
                        }
                    }
                }*/
                char string[4];
                arr[1]=0;
                while(1){
                    temp=1;
                    printf("Guess four number:\nenter:");
                    scanf(" %s",string);
                    //printf("\n");
                    for(int i=0;i<4;i++){
                        if(string[i]<48||string[i]>57){
                            printf("Only integer between 0-9 is acceptible.\nPlease input again.\n");
                            temp=0;
                            break;
                        }
                        for(int j=i+1;j<4;j++){
                            if(string[i]==string[j]){
                                printf("There are overlapping numbers in the input.\nPlease input again.\n");
                                temp=0;
                                break;
                            }
                        }
                        if(temp==0){
                            break;
                        }
                    }
                    if(temp==1){
                        break;;
                    }

                }

                for(int i=0;i<4;i++){
                    arr[1]+=(int)((string[i]-48)*pow(10,3-i));
                }
                temp=verify(arr[1],ans);
                if(temp==40){
                    printf("YOU WIN\n");
                    break;
                }
                else{
                    printf("%dA%dB\n",(int)(temp/10),temp%10);
                }
            }
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
        else{
            for(int j=0;j<4;j++){
                if(j==i){
                    continue;
                }
                else if(extract(ax,j)==extract(bx,i)){
                    b++;
                }
            }
        }

    }
    //printf("verify: %d %d\n",a,b);
    return a*10+b;
}

int extract(int ax, int bx){
    //printf("ax%d\n",ax);
    int temp;
    if(ax<1000&&bx==3){
    //printf("extract(%d,%d)=%d\n",ax,bx,0);
        return 0;
    }
    for(int i=0;i<4;i++){
        if(bx==i){
        //printf("extract(%d,%d)=%d\n",ax,bx,(int)(ax%10));

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