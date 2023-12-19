#include <stdio.h>

int main() {
    int a, b, temp;

    // Input two integers
    scanf("%d %d", &a, &b);

    // Swap a and b if a is smaller than b
    if (a < b) {
        temp = b;
        b = a;
        a = temp;
    }

    // Calculate the greatest common divisor using Euclidean algorithm
    while (a % b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    // Output the greatest common divisor
    printf("%d\n", b);

    return 0;
}
