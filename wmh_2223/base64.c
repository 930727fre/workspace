#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map(int);
int main(){
    //char str[1000]="I see, I come, I conquer.";
    char str[1000]="M";    
    unsigned char temp;
    int offset=2,length,index=0;
    //scanf("%s",str);
    length=strlen(str)*8/6+(4-strlen(str)*8/6)%4;
    for(int i=0;i<length;i++){
        //printf("offset = %d / index = %d\n",offset,index);
        //printf("%d",6*i-8*strlen(str));
        if((int)(6*i-8*strlen(str))>=6){
            printf("=");
        }
        else{
            if(offset<=2){
                temp=str[index]<<(2-offset);
                temp=temp>>2;
            }
            else{
                //printf("last:%d\n",str[index-1]);
                temp=str[index-1]<<(10-offset);
                //printf("!%d",temp);
                temp=temp>>2;
                //printf("!%d",temp);
                temp+=str[index]>>offset;
                //printf("!%d\n",temp);

            }
            printf("%c",map(temp));

        }
        offset+=2;
        if(offset!=8){
            index++;
        }
        offset=offset%8;
    }
    printf("\n");
}

int map(int index){
    if(0<=index&&index<=25){
        return index+'A';
    }
    else if(26<=index&&index<=51){
        return index+'a'-26;
    }
    else if(52<=index&&index<=61){
        return index+'0'-52;
    }
    else if(index==62){
        return '+';
    }
    else if(index==63){
        return '/';
    }
    else{
        return -1;
    }
}