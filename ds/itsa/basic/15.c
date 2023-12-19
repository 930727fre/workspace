#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to split a string into a vector based on a pattern
void split(char* str, char* pattern, char* result[], int* count) {
    char* token = strtok(str, pattern);
    *count = 0;

    // Split the string using strtok
    while (token != NULL) {
        result[(*count)++] = token;
        token = strtok(NULL, pattern);
    }
}

int main() {
    char str[1000];
    char* result[100];
    char* pattern = " ";
    int ans[26];

    // Input a line
    fgets(str, sizeof(str), stdin);

    int count;

    // Split the string into words
    split(str, pattern, result, &count);

    // Output the number of words
    printf("%d\n", count);

    // Initialize the ans array
    for (int i = 0; i < 26; i++) {
        ans[i] = 0;
    }

    // Count the occurrence of each letter
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < strlen(result[i]); j++) {
            if (isalpha(result[i][j])) {
                ans[tolower(result[i][j]) - 'a']++;
            }
        }
    }

    // Output the result
    for (int i = 0; i < 26; i++) {
        if (ans[i]) {
            printf("%c : %d\n", 'a' + i, ans[i]);
        }
    }

    return 0;
}
