#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    char buf[10000];
    pid_t pid;
    int status;
    char *token, *arg[1000], *command;
    int counter=0;

    printf("## ");
    while(fgets(buf,10000,stdin)!=NULL){
        counter=0;
        if(buf[strlen(buf)-1]=='\n'){
            buf[strlen(buf)-1]='\0';
        }
        token=strtok(buf," ");
        command=token;
        while(token!=NULL){
            arg[counter]=token;
            counter++;
            token=strtok(NULL," ");
        }
        arg[counter]=NULL;

        pid=fork();
        if(pid<0){
            exit(EXIT_FAILURE);
        }
        else{
            if(pid==0){
                execvp(command,arg);
            }
            else{
				if ((pid = waitpid(pid, &status, 0)) < 0)
					printf("waitpid error");
				printf("## ");
            }

        }
    }

    exit(EXIT_SUCCESS);
}