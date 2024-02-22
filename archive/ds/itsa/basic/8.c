#include <stdio.h>
#include <math.h>

int main() {
    int flag = 0, i;

    scanf("%d", &i);

    // Check for prime by iterating from 2 to the square root of i
    for (int j = 2; j <= sqrt(i); j++) {
        if (i % j == 0) {
            printf("NO\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("YES\n");
    }

    return 0;
}
