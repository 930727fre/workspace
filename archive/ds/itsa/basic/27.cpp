#include <stdio.h>
#include <string.h>

// Function prototype
void evaluateGuess(char answer[], char guess[]);

int main() {
    // Define arrays to store the answer and the guess
    char answer[5];
    char guess[5];

    // Input the answer
    scanf("%s", answer);

    // Enter the guessing loop
    while (1) {
        // Input a guess
        scanf("%s", guess);

        // Check if the game should end
        if (guess[0] == '0') {
            break;
        }

        // Evaluate the guess
        evaluateGuess(answer, guess);
    }

    return 0;
}

// Function to evaluate a guess
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

    // Output the result
    printf("%dA%dB\n", A, B);
}
