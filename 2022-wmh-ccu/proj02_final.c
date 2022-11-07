#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void generateFourRandomNumber(int *ax);// generate four distinctive numbers by calling by reference
int verify(int ax,int bx);//verify the a and b's between the input and return the value in integer
int extract(int ax,int bx);//extract bx'th number in ax, which is a integer
int manualVerify(int ax);//let the user input the a and b's of ax and return in integer format
char ctemp;

int main(){
    int temp,upperIndex,index,verificationCode;//verificationCode= store the a and b's of given two inputs
    int arr[5040],ans;//arr[5040] = store all the possible combination
    srand(time(NULL));//set the srand seed by time(NULL)
    while(1){
        generateFourRandomNumber(&ans);
        printf("Mode:(1)Answer/(2)Guessing(3)Quit?\ninput:");
        scanf(" %c",&ctemp);
        if(ctemp!=49&&ctemp!=50&&ctemp!=51){//ascii code 49 = 1 in decimal
            printf("Only integer 1 and 2 is permitted.\nPlease enter again.\n");
            continue;
        }
        else if(ctemp==49){//Answer mode
            printf("Answer mode\n");
            temp=0;
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        for(int l=0;l<10;l++){
                            if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
                                arr[temp]=1000*i+100*j+10*k+l;//generate all combinations and store in arr
                                temp++;
                            }
                        }
                    }
                }
            }
            index=5040-1;//the index starts at the end of the array
            upperIndex=0;
            verificationCode=manualVerify(arr[5039]);//verify the a and b's by user
            while(index!=0){
                //printf("index= %d\n",index);
                if(verificationCode==40){//if the output is 4A0B, then break
                    break;
                }
                upperIndex=0;
                if(verificationCode==verify(arr[index],arr[index-1])){//verify the arr[index] and arr[index-1]
                    while(verificationCode==verify(arr[index],arr[upperIndex])){//if the verificationCode between the twos are same as the answer's then verify the arr[upperIndex]
                        if(upperIndex==index-1){
                            verificationCode=manualVerify(arr[index-1]);//let the user input the a and b's manually
                            break;
                        }
                        upperIndex++;
                    }
                    if(verificationCode==40){//if it's a 4A0B, the break
                        break;
                    }                
                    if(upperIndex!=index-1){
                        arr[upperIndex]=arr[index-1];//swap arr[upperIndex] and arr[index-1], replace arr[index-1] with arr[index]
                        arr[index-1]=arr[index];
                    }
                }
                else{
                    arr[index-1]=arr[index];
                }
                index--;//index moves on
            }
            if(verificationCode!=40){//if there is no more possible combinations, then it's a cheat
                printf("YOU CHEAT\n");
            }
            else{
                printf("PC WIN\n");

            }
        }
        else if(ctemp==50){//Guessing mode
            while(1){
                temp=0;
                char string[4];
                arr[1]=0;
                while(1){
                    temp=1;
                    printf("Guess four number: (no space required)\nenter:");
                    scanf(" %s",string);
                    //printf("\n");
                    for(int i=0;i<4;i++){
                        if(string[i]<48||string[i]>57){
                            printf("Only integer between 0-9 is acceptible.\nPlease input again.\n");//fool-proof
                            temp=0;
                            break;
                        }
                        for(int j=i+1;j<4;j++){
                            if(string[i]==string[j]){
                                printf("There are overlapping numbers in the input.\nPlease input again.\n");//fool-proof
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
                    arr[1]+=(int)((string[i]-48)*pow(10,3-i));//convert the input into integers 
                }
                temp=verify(arr[1],ans);//store the verificationCode in temp
                if(temp==40){
                    printf("YOU WIN\n");
                    break;
                }
                else{
                    printf("%dA%dB\n",(int)(temp/10),temp%10);
                }
            }
        }
        else if(ctemp==51){//quit the programme
            break;
        }
        
    }
}

void generateFourRandomNumber(int *ax){
    int a=0,b=0,c=0,d=0;
    while(a==b||a==c||a==d||b==c||b==d||c==d){//generate four distinctive numbers
        a=rand() % (9-0 + 1) + 0;
        b=rand() % (9-0 + 1) + 0;
        c=rand() % (9-0 + 1) + 0;
        d=rand() % (9-0 + 1) + 0;
    }
    *ax=1000*a+100*b+10*c+d;//store in decimal way
}

int verify(int ax, int bx){
    int a=0,b=0;
    for(int i=0;i<4;i++){
        if(extract(ax,i)==extract(bx,i)){//check if the numbers of same index are the same, if so, a++
            a++;
        }
        else{
            for(int j=0;j<4;j++){
                if(j==i){
                    continue;
                }
                else if(extract(ax,j)==extract(bx,i)){//check if there is a same number at other index, if so, b++
                    b++;
                }
            }
        }

    }
    return a*10+b;
}

int extract(int ax, int bx){//extract bx'th number of ax and return
    //printf("ax%d\n",ax);
    int temp;
    if(ax<1000&&bx==3){//since there is no 0 before numbers smaller than 1000, i just return 0 right away
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

int manualVerify(int ax){//the the user input a and b's manually
    char ca,cb;
    printf("the programe guess: ");
    if(ax<1000){
        printf("0");
    }
    printf("%d\n",ax);
    printf("Please input the A and Bs(space is required)\nenter:");
    scanf(" %c",&ca);
    scanf(" %c",&cb);

    while(ca<48||cb<48||ca>52||cb>52||96>ca+cb||ca+cb>100){//fool-proof
        printf("Only integers between 0 to 4 is permitted and 0<=A+B<=4.\nPlease input again\nenter:");
        scanf(" %c%c",&ca,&cb);
    }
    return 10*(ca-48)+(cb-48);//return in deciaml way
}