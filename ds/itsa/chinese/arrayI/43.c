#include <stdio.h>

int power(int m, int n) {
    if (n == 0) {
        return 1;
    } else {
        return m * power(m, n - 1);
    }
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF) {
        int result = power(m, n);
        printf("%d\n", result);
    }

    return 0;
}
