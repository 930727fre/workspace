#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[1000];
    char *tok;
    int n;
    while(fgets(str, 1000, stdin)!=NULL){
        str[strlen(str)-1]='\0';
        printf("%sQ\n",str);
        n=0;
        int sequence[10];
        int count[100] = {0};
        tok=strtok(str, " ");
        while(tok!=NULL){
            printf("%d\n", atoi(tok));
        if ( atoi( ar ) < 0 ) fnum = -fnum;

            sequence[n]=atoi(tok);
            count[sequence[n]]++;
            tok=strtok(NULL, " ");
            n++;
        }
        // Check for the majority element
        int majorityElement = -1;
        for (int i = 0; i < n; i++) {
            if (count[sequence[i]] > n / 2) {
                majorityElement = sequence[i];
                break;
            }
        }

        // Output the result
        if (majorityElement != -1) {
            printf("%d\n", majorityElement);
        } else {
            printf("NO\n");
        }
    }
}
