#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int listening, reading, speaking;
        scanf("%d %d %d", &listening, &reading, &speaking);

        // 判斷通過測驗、補考、無法通過的條件
        if ((listening >= 60 && reading >= 60 && speaking >= 60) ||
            (listening + reading + speaking > 220) ||
            (listening >= 80 || reading >= 80 || speaking >= 80)) {
            printf("P\n"); // 通過測驗
        } else if ((listening < 60 && reading < 60 && speaking < 60) ||
                   (listening + reading + speaking <= 220 && listening < 80 && reading < 80 && speaking < 80)) {
            printf("F\n"); // 無法通過測驗
        } else {
            printf("M\n"); // 補考
        }
    }

    return 0;
}
