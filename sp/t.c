#include <stdio.h>
#include <setjmp.h>

jmp_buf jumpBuffer;

void functionB() {
    printf("Function B\n");
    longjmp(jumpBuffer, 1);  // Perform the non-local jump
    printf("hi\n");
}

void functionA() {
    printf("Function A\n");
    functionB();
    printf("Function A resumed\n");
}

int main() {
    if (setjmp(jumpBuffer) == 0) {
        functionA();
    } else {
        printf("Back in main\n");
    }
    
    return 0;
}
