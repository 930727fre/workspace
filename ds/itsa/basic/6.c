#include <stdio.h>

int main() {
    int n;

    // Input an integer
    scanf("%d", &n);

    // Check the season based on the month
    if (n >= 3 && n <= 5) {
        printf("Spring");
    } else if (n >= 6 && n <= 8) {
        printf("Summer");
    } else if (n >= 9 && n <= 11) {
        printf("Autumn");
    } else if (n == 12 || n <= 2) {
        printf("Winter");
    }

    printf("\n");

    return 0;
}
