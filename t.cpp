#include <iostream>
#include <unistd.h>

int main(){
    execvp("cat","cat","test.1cpp");
}
