#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 31

void addLargeIntegers(char num1[], char num2[], char result[]) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLength = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < len1) ? (num1[len1 - i - 1] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - i - 1] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[maxLength] = carry + '0';
        result[maxLength + 1] = '\0';
    } else {
        result[maxLength] = '\0';
    }

    // Reverse the result string
    int resultLength = strlen(result);
    for (int i = 0; i < resultLength / 2; i++) {
        char temp = result[i];
        result[i] = result[resultLength - i - 1];
        result[resultLength - i - 1] = temp;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char num1[MAX_DIGITS], num2[MAX_DIGITS], result[MAX_DIGITS + 1];
        scanf("%s %s", num1, num2);

        addLargeIntegers(num1, num2, result);

        printf("%s\n", result);
    }

    return 0;
}
