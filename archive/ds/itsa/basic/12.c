#include <stdio.h>

// Recursive function to calculate the result
int fn(int n) {
    if (n == 1 || n == 0) {
        return n + 1;
    } else {
        return fn(n - 1) + fn(n / 2);
    }
}

int main() {
    int k;

    scanf("%d", &k);

    printf("%d\n", fn(k));

    return 0;
}
