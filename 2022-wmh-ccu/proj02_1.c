#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateFourRandomNumber(int ax);
int verify(int bx,int cx);
int arr[5040],ans;
int mode,temp,counter,upperIndex,lowerIndex,index,flag,specialCode;

int main(){
    char ctemp;
    srand(time(NULL));
    while(1){
        printf("Mode:(1)Answer/(2)Guessing?\ninput:");
        //scanf("%c",&ctemp);
        printf("jieo");
        ctemp=48+1;

        if(ctemp!=48&&ctemp!=49){
            printf("Only integer between 0 to 9 is permitted.\nPlease enter again.\n");
            continue;
        }
        else if(ctemp==48){//Answer Mode
            generateFourRandomNumber(ans);
            printf("ans= %d\n",ans);
            counter=0;
            for(int i=0;i<10;i++){//initialize the whole array of 5040
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        for(int l=0;l<10;l++){
                            if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
                                arr[counter]=i*1000+j*100+k*10+l;
                                counter++;
                            }
                        }
                    }
                }
            }
            specialCode=verify(arr[5040-1],ans);
            upperIndex=0;
            lowerIndex=5040-2;
            index=5040-1;
            while(1){
                upperIndex=0;
                if(specialCode==-1){
                    break;
                }
                if(upperIndex==index-1){
                    index--;
                }
                if(index==0){
                    printf("CHEAT!\n");
                    break;
                }
                else{
                    if(verify(arr[index],arr[index-1])!=specialCode){
                        temp=arr[index];
                        arr[index]=arr[index-1];
                        arr[index-1]=temp;
                        index--;
                    }
                    else{
                        while(1){
                            if(verify(arr[upperIndex],arr[index])!=-1){
                                temp=arr[upperIndex];
                                arr[upperIndex]=arr[index-1];
                                arr[index-1]=temp;
                                temp=arr[index];
                                arr[index]=arr[index-1];
                                arr[index-1]=temp;
                                index--;
                                break;
                            }
                            upperIndex++;
                        }
                    }
                }
            }
            
        }
        else{//Guessing Mode
            generateFourRandomNumber(arr[0]);
            printf("ans=%d\n",arr[0]);
            while(1){
                temp=0;
                char ctemp;
                arr[1]=0;
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
                        arr[1]+=(ctemp-48)*(int)pow(10,i);
                    }
                }
                if(verify(arr[1],arr[0])==-1){
                    break;
                }
            }
        }
    }
}


void generateFourRandomNumber(int ax){
    int temp;
    ax=0;
    int a=0,b=0,c=0,d=0;

    while(1){
        if(a==b||a==c||a==d||b==c||b==d||c==d){
            a=rand() % (9-0 + 1) + 0;
            b=rand() % (9-0 + 1) + 0;
            c=rand() % (9-0 + 1) + 0;
            d=rand() % (9-0 + 1) + 0;
        }
    }
    ax=a*1000+b*100+c*10+d;
    //printf("%d",ax);
}

int verify(int bx,int cx){
    int a=0,b=0,temp;
    for(int i=0;i<4;i++){
        if((int)(bx/(int)pow(10,i))==(int)(cx%(int)pow(10,i))){
            a++;
        }
        else{
            temp=0;
            for(int j=0;j<4;j++){
                if((int)(bx/(int)pow(10,j))==(int)(cx%(int)pow(10,i))){
                    b++;
                    break;
                }
            }
        }
    }
    if(a==4){
        printf("YOU WIN\n");
        return -1;
    }
    else{
        printf("%dA%dB\n",a,b);
        return a*10+b;
    }
}