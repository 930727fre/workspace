#include <stdio.h>

int main() {
    int dice[4];
    int i, j;
    
    // 輸入四顆骰子的點數
    for (i = 0; i < 4; ++i) {
        scanf("%d", &dice[i]);
    }

    // 檢查通殺的情況
    if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3]) {
        printf("WIN\n");
    }
    // 檢查無意義的情況
    else if ((dice[0] == dice[1] && dice[1] == dice[2]) || (dice[1] == dice[2] && dice[2] == dice[3])||(dice[0] == dice[1] && dice[1] == dice[3])||(dice[0] == dice[2] && dice[2] == dice[3])) {
        printf("R\n");
    }
    // 計算點數
    else {
        int sum = 0;
        for (i = 0; i < 4; ++i) {
            for (j = i + 1; j < 4; ++j) {
                if (dice[i] == dice[j]) {
                    sum += dice[i];
                }
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
