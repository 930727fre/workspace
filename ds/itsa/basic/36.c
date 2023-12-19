#include <stdio.h>

int main() {
    int n;

    // Input the year
    scanf("%d", &n);

    // Check if the year is divisible by 400
    if (n % 400 == 0) {
        printf("Bissextile Year");
    } else {
        // Check if the year is divisible by 100
        if (n % 100 == 0) {
            printf("Common Year");
        } else {
            // Check if the year is divisible by 4
            if (n % 4 == 0) {
                printf("Bissextile Year");
            } else {
                printf("Common Year");
            }
        }
    }

    // Output a newline
    printf("\n");

    return 0;
}
