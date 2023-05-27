#include <stdio.h>

int main() {
    char buffer[BUFSIZ];
    char str[100];
    setvbuf(stdout, buffer, _IOLBF, BUFSIZ);
    scanf("%s\n",str);
    printf("%s",buffer);

    // Rest of the code...

    return 0;
}
