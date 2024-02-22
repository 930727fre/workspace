#include <stdio.h>
#include <string.h>

void evaluateGuess(char answer[], char guess[]);

int main() {
    char answer[5];
    char guess[5];

    scanf("%s", answer);

    while (1) {
        scanf("%s", guess);

        if (guess[0] == '0') {
            break;
        }
        evaluateGuess(answer, guess);
    }

    return 0;
}

void evaluateGuess(char answer[], char guess[]) {
    int A = 0, B = 0;

    // Check each position
    for (int i = 0; i < 4; ++i) {
        // If both position and value are the same, increment A
        if (guess[i] == answer[i]) {
            A++;
        } else {
            // Check if there is a matching value in a different position, increment B
            for (int j = 0; j < 4; ++j) {
                if (guess[i] == answer[j] && i != j) {
                    B++;
                    break;
                }
            }
        }
    }

    printf("%dA%dB\n", A, B);
}
