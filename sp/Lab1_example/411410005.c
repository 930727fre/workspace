#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    printf("## ");
    char buf[10000];
    pid_t pid;
    int status;

    while(fgets(buf,10000,stdin)!=NULL){
        printf("## ");
        if(buf[strlen(buf)-1]=='\n'){
            buf[strlen(buf)-1]='\0';
        }
        pid=fork();
        if(pid<0){
            exit(EXIT_FAILURE);
        }
        else{
            if(pid==0){
                execlp(buf, buf, (char *)0);
            }
            else{
				if ((pid = waitpid(pid, &status, 0)) < 0)
					printf("waitpid error");
				printf("%% ");
            }

        }
    }

    exit(EXIT_SUCCESS);
}