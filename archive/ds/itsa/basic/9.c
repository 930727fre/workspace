#include <stdio.h>

int main() {
    int n, ans = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            ans += i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
