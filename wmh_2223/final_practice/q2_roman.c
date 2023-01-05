#include <stdio.h>
#include <string.h>
/*input
XVII
XIX
MMMCCCXXXIII
*/

int map(char);
int main(){
    char str[100]="XVII";
    int ans,temp;
    while(scanf("%s",str)!=EOF){
        ans=0;
        temp=0;
        for(int i=0;i<strlen(str);i++){
            if(i==strlen(str)-1){
                ans+=map(str[i]);
                if(map(str[i-1])==map(str[i])){
                    ans+=temp;
                }
                break;
            }
            else{
                if(map(str[i])>map(str[i+1])){
                    temp+=map(str[i]);
                    ans+=temp;
                    temp=0;
                }
                else if(map(str[i])==map(str[i+1])){
                    temp+=map(str[i]);
                }
                else{
                    temp+=map(str[i]);
                    ans-=temp;
                    temp=0;
                }
            }
            //printf("tempans = %d\n",ans);

        }
        printf("%d\n",ans);
    }
    
}

int map(char c){
    switch(c){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }
    return -1;
}
/*
XVII
XIX
MMMCCCXXXIII
17
19
3333

last word
facing bigger one
facing smaller one
*/