#include <stdio.h>

int main() {
    char str[101];
    int n;

    fgets(str, sizeof(str), stdin);

    // Read the number of positions to shift
    scanf("%d", &n);

    for (int i = 0; str[i] != '\0'; i++) {
        // If it is a letter
        if (isalpha(str[i])) {
            // Preserve the case and shift by the specified number of positions
            if (isupper(str[i])) {
                printf("%c", ((str[i] - 'A' + n) % 26) + 'A');
            } else {
                printf("%c", ((str[i] - 'a' + n) % 26) + 'a');
            }
        }
        // If it is a digit
        else if (isdigit(str[i])) {
            // Preserve the digit and shift by the specified number of positions
            printf("%c", ((str[i] - '0' + n) % 10) + '0');
        }
        // If it is another character
        else {
            // Preserve it unchanged
            printf("%c", str[i]);
        }
    }

    printf("\n");

    return 0;
}
