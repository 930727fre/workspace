#include <stdio.h>

// Function to invert an array of 8 elements
void invert(int ref[8]) {
    for (int i = 0; i < 8; i++) {
        if (ref[i] == 1) {
            ref[i] = 0;
        } else {
            ref[i] = 1;
        }
    }
}

int main() {
    int input, arr[8];

    // Initialize
    for (int i = 0; i < 8; i++) {
        arr[i] = 0;
    }

    scanf("%d", &input);

    // Convert the positive integer to binary representation
    if (input > 0) {
        for (int i = 7; i >= 0; i--) {
            if (input >= pow(2, i)) {
                arr[i] = 1;
                input -= pow(2, i);
            }
        }
    } else { // case of negative integer
        input *= -1;

        // Convert the absolute value of the negative integer to binary representation
        for (int i = 7; i >= 0; i--) {
            if (input >= pow(2, i)) {
                arr[i] = 1;
                input -= pow(2, i);
            }
        }

        // Invert the binary representation, add 1, and handle carry
        invert(arr);
        arr[0] += 1;
        for (int i = 0; i <= 7; i++) {
            if (arr[i] == 2) {
                arr[i] = 0;
                if (i != 7) {
                    arr[i + 1]++;
                }
            }
        }
    }

    // Output
    for (int i = 7; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
