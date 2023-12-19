#include <stdio.h>

int main() {
    int n, ans = 0;

    // Input an integer
    scanf("%d", &n);

    // Calculate the sum of multiples of 3 up to n
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            ans += i;
        }
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
