#include <stdio.h>

// Recursive approach (A)
int FibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}





int main() {
    int n = 10;

    // Recursive approach
    int resultRecursive = FibonacciRecursive(n);
    printf("Recursive Approach: Fibonacci(%d) = %d\n", n, resultRecursive);

    // Non-recursive approach using an array
    int resultNonRecursive = FibonacciNonRecursive(n);
    printf("Non-Recursive Approach (with array): Fibonacci(%d) = %d\n", n, resultNonRecursive);

    // Non-array approach with a constraint
    int resultConstraint = FibonacciConstraint(n);
    printf("Non-Recursive Approach (without array): Fibonacci(%d) = %d\n", n, resultConstraint);

    return 0;
}
