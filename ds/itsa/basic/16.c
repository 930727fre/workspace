#include <stdio.h>
#include <string.h>

// Function to split a string based on a pattern and count occurrences
void split(char* str, char* pattern, int* count) {
    *count = 0;
    char* temp = strstr(str, pattern);

    // Count occurrences of the pattern
    while (temp != NULL) {
        (*count)++;
        str = temp + 1;
        temp = strstr(str, pattern);
    }
}

int main() {
    char pattern[100], str[1000];

    // Input pattern and string
    scanf("%s %s", pattern, str);

    int count;

    // Call the split function to count occurrences
    split(str, pattern, &count);

    // Output the result
    printf("%d\n", count);

    return 0;
}
