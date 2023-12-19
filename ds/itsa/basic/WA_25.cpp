#include <stdio.h>
#include <string.h>

char inputString[33]; // 最多32字元 + 結束字元

int calculateASCIISum(void) {
    int sum = 0;
    // 遍歷字串，計算每個字元的ASCII編碼數值總和
    for (int i = 0; i < strlen(inputString); ++i) {
        if(inputString[i]=='\n'){
            return sum;
        }
        sum += (int)inputString[i];
    }

    return sum;
}

int main() {
    int numTests;

    // 讀入測試數量
    scanf("%d\n",&numTests);//This will consume the '\n' char


    // 處理每一筆測試
    for (int i = 0; i < numTests; ++i) {
        // 讀入測試字串
        fgets(inputString,sizeof(inputString),stdin);

        // 計算並輸出ASCII編碼總和
        int result = calculateASCIISum();
        printf("%d\n", result);
    }

    return 0;
}
