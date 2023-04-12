#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>

long long counter[7];
void traverse(char* path){
    // printf("traverse: %s\n",path);
    DIR *dir;
    struct dirent *entry;
    struct stat buf;
    int fd=open(path,O_RDONLY);

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0){
            continue;
        }
        if(fstatat(fd,entry->d_name,&buf,AT_SYMLINK_NOFOLLOW)==0){
            if(S_ISREG(buf.st_mode)){
                counter[0]++;
            }
            else if(S_ISDIR(buf.st_mode)){
                counter[1]++;
                char* nextpath;
                nextpath=(char*)malloc(strlen(path)+strlen(entry->d_name)+2);
                strcpy(nextpath,path);
                strcat(nextpath,entry->d_name);
                nextpath[strlen(path)+strlen(entry->d_name)]='/';
                nextpath[strlen(path)+strlen(entry->d_name)+1]='\0';
                traverse(nextpath);
                free(nextpath);
            }
            else if(S_ISCHR(buf.st_mode)){
                counter[2]++;
            }
            else if(S_ISBLK(buf.st_mode)){
                counter[3]++;
            }
            else if(S_ISFIFO(buf.st_mode)){
                counter[4]++;
            }
            else if(S_ISSOCK(buf.st_mode)){
                counter[5]++;
            }
            else if(S_ISLNK(buf.st_mode)){
                counter[6]++;
            }
            else{
                printf("none of each\n");
                exit(0);
            }                            
        }         
    }

    closedir(dir);
   

    close(fd);
}

int main(){
    traverse("/");
    char words[7][100]={"regular file","directory","Character special file","Block special file","FIFO","socket","symbolic link"};
    for(int i=0;i<7;i++){
        printf("%s:%lld\n",words[i],counter[i]);
    }
}
