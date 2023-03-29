#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    int fd,fd2,temp;
    fd=open("test.out",O_RDWR|O_CREAT,0777);
    printf("%d %d\n",fd,fd2);
    fd2=dup2(fd,5);
    printf("%d %d",fd,fd2);
    close(fd2);
    close(fd);
}
