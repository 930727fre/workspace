#include <string.h>
#include <stdio.h>

int main () {
    char str[80] = "This is - www.tutorialspoint.com - website";
    const char s[] = " ";
    char *token;
    
    /* get the first token */
    token = strtok(str, s);
    
    /* walk through other tokens */
    while( token != NULL ) {
        for(int i=0;i<sizeof(token);i++){
            printf("%c",token[i]);
        }
        printf("\n%s\n\n",token);
        
        token = strtok(NULL, s);
    }
    
    return(0);
}