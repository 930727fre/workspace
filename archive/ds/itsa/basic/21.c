#include <stdio.h>
#include <float.h>

int main() {
    float min = FLT_MAX, max = -FLT_MAX, num;

    for (int i = 0; i < 10; i++) {
        scanf("%f", &num);
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }

    printf("maximum: %.2f\n", max);
    printf("minimum: %.2f\n", min);

    return 0;
}
