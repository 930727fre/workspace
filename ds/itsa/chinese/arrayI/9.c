#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// compare digits for sorting in descending order
int compareDigits(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char input[15];
    int digits[7];

    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, ",");
    int count = 0;

    while (token != NULL && count < 7) {
        digits[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // in descending order
    qsort(digits, count, sizeof(int), compareDigits);

    int maxNumber = 0, minNumber = 0;

    for (int i = 0; i < count; i++) {
        maxNumber = maxNumber * 10 + digits[i];
        minNumber = minNumber * 10 + digits[count - 1 - i];
    }

    printf("%d\n", maxNumber - minNumber);

    return 0;
}
