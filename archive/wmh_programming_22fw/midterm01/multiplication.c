#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*input
32 * 3
100 * 6
70 * 8
*/

int main(){
    char *a,*b,str[1000],ans[200];
    int index=0;
    while(fgets(str,1000,stdin)!=NULL){
        str[strlen(str)-1]='\0';
        for(int i=0;i<200;i++){
            ans[i]=0;
        }        
        a=strtok(str," *");
        b=strtok(NULL," *");
        //printf("%s * %s = \n",a,b);
        for(int i=strlen(b)-1;i>=0;i--){
            index=strlen(b)-1-i-1;
            for(int j=strlen(a)-1;j>=0;j--){
                index++;
                ans[index]+=(b[i]-48)*(a[j]-48);
                ans[index+1]+=ans[index]/10;
                ans[index]=ans[index]%10;                
            }
        }
        for(int i=199;i>=0;i--){
            if(ans[i]!=0){
                index=i;
                break;
            }
        }
        for(int i=index;i>=0;i--){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}

/*
2469135802469135802469135308641975308641975308642
2469135802469135802469135308641975308641975308642
*/