#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (sqrt(x * x + y * y) <= 100) {
        printf("inside\n");
    } else {
        printf("outside\n");
    }

    return 0;
}
