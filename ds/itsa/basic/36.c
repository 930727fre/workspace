#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n % 400 == 0) {
        printf("Bissextile Year");
    } else {
        if (n % 100 == 0) {
            printf("Common Year");
        } else {
            if (n % 4 == 0) {
                printf("Bissextile Year");
            } else {
                printf("Common Year");
            }
        }
    }

    printf("\n");

    return 0;
}
