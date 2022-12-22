#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*input
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
*/
int main(){
    int flag=1;
    char str[10000];
    while(fgets(str,1000,stdin)){
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='"'){
                if(flag){
                    printf("``");
                }
                else{
                    printf("''");
                }
                flag=!flag;
            }
            else{
                printf("%c",str[i]);
            }
        }
    }
}