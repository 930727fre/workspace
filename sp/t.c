#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signum) {
    printf("Received SIGALRM signal.\n");
    // Additional signal handling code...
}

int main() {
    int sec = alarm(4);
    // alarm(0);
    printf("%d",sec);
}
