#include <stdio.h>
#include <limits.h>

int main() {
    int num, min_even = INT_MAX, min_odd = INT_MAX;

    // Read the sequence of positive integers
    int numbers[100];
    int i = 0;
    printf("input: ");
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;
        numbers[i++] = num;
    }

    // Find the minimum even and odd numbers
    for (int j = 0; j < i; j++) {
        if (numbers[j] % 2 == 0 && numbers[j] < min_even)
            min_even = numbers[j];
        else if (numbers[j] % 2 != 0 && numbers[j] < min_odd)
            min_odd = numbers[j];
    }

    // Check if even or odd numbers were found
    if (min_even == INT_MAX)
        min_even = -1;
    if (min_odd == INT_MAX)
        min_odd = -1;

    // Print the results
    printf("%d %d\n", min_even, min_odd);

    return 0;
}
