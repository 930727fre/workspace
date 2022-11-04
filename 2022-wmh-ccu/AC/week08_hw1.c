#include <stdio.h>

int main(){
    char str[200000],temp;
    int counter=0,ans=1;
    while(scanf(" %c",&temp)!=EOF){
        if(temp>=97&&temp<=122){
            str[counter]=temp;
            //printf("%c",str[counter]);
            counter++;

        }
        else if(temp>=65&&temp<=90){
            str[counter]=temp+32;
            //printf("%c",str[counter]);
            counter++;
        }    
        
    }
    //printf("%d",counter);
    for(int i=0;i<counter/2;i++){
        if(str[i]!=str[counter-i-1]){
            ans=0;
            //printf("\n%d %c %d %c\n",i,str[i],counter-i,str[counter-i]);
            break;
        }
    }
    if(ans==0){
        printf("NO");
    }
    else{
        printf("YES");
    }

}


//0 1 2 3 4, counter=5