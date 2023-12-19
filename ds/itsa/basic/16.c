#include <stdio.h>
#include <string.h>

// split a string based on a pattern and count occurrences
void split(char* str, char* pattern, int* count) {
    *count = 0;
    char* temp = strstr(str, pattern);

    // Count occurrences
    while (temp != NULL) {
        (*count)++;
        str = temp + 1;
        temp = strstr(str, pattern);
    }
}

int main() {
    char pattern[100], str[1000];

    scanf("%s %s", pattern, str);

    int count;

    split(str, pattern, &count);

    printf("%d\n", count);

    return 0;
}
