#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    int fd;
    char str[100]="hello!\nworld!hi\n";
    char output[100];
    fd=open("test.out",O_RDWR|O_CREAT|O_TRUNC,2);
    close(fd);
}
