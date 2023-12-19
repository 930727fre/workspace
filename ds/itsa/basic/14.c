#include <stdio.h>
#include <string.h>

// check if a string is a palindrome
int palindrome(char str[]) {
    int flag = 1;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[100];

    scanf("%s", str);

    if (palindrome(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
