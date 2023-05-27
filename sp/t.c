#include <stdio.h>

int main() {
    char buffer[BUFSIZ];
    setvbuf(stdout, buffer, _IOLBF, BUFSIZ);

    // Rest of the code...

    return 0;
}
