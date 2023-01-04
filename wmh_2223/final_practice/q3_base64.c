#include <stdio.h>
#include <string.h>

int map(char);
int main(){
    unsigned char str[1000],temp;
    int offset,index;
    fgets((char*)str,1000,stdin);
    str[strlen((char*)str)-1]='\0';
    offset=2;
    index=0;
    for(int i=0;i<strlen((char*)str)*8/6+(4-strlen((char*)str)*8/6%4)%4;i++){
        if(offset==8){
            offset=0;
        }
        if(index>strlen((char*)str)){
            printf("=");
        }
        else{
            if(offset<=2){
                temp = (str[index]<<(2-offset));
                temp=temp>>2;
            }
            else{
                if(index==strlen((char*)str)){
                    temp=(str[index-1]<<(10-offset));
                    temp=temp>>2;
                    index++;
                }
                else{
                    temp=(str[index-1]<<(10-offset));
                    temp=temp>>2;
                    temp+=(str[index]>>offset);
                }
            }
            printf("%c",map(temp));
            if(offset<=5){
                index++;
            }
            offset+=2;
        }
    }
    printf("\n");
}

int map(char c){
    if(0<=c&&c<=25){
        return c+'A';
    }
    else if(26<=c&&c<=51){
        return c+'a'-26;
    }
    else if(52<=c&&c<=61){
        return c+'0'-52;
    }
    else if(c==62){
        return '+';
    }
    else if(c==63){
        return '/';
    }
    return -1;
}