#include <stdio.h>
#include <string.h>

// 函式原型
void evaluateGuess(char answer[], char guess[]);

int main() {
    // 定義答案和猜測陣列
    char answer[5];
    char guess[5];

    // 讀入答案
    scanf("%s", answer);

    // 進入猜測迴圈
    while (1) {
        // 讀入猜測
        scanf("%s", guess);

        // 檢查是否結束
        if (guess[0] == '0') {
            break;
        }

        // 評估猜測
        evaluateGuess(answer, guess);
    }

    return 0;
}

// 評估猜測的函式
void evaluateGuess(char answer[], char guess[]) {
    int A = 0, B = 0;

    // 檢查每一位
    for (int i = 0; i < 4; ++i) {
        // 如果位置和數值都相同，則A加一
        if (guess[i] == answer[i]) {
            A++;
        } else {
            // 檢查是否有相同的數值但位置不同，則B加一
            for (int j = 0; j < 4; ++j) {
                if (guess[i] == answer[j] && i != j) {
                    B++;
                    break;
                }
            }
        }
    }

    // 輸出結果
    printf("%dA%dB\n", A, B);
}
