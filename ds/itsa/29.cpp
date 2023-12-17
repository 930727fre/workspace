#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 函式原型
int checkID(char id_number[]);

int main() {
    // 測試範例
    char sample_input1[] = "A123456789";
    char sample_input2[] = "L163690274";

    // 呼叫檢查函式並輸出結果
    if (checkID(sample_input1)) {
        printf("CORRECT!!!\n");
    } else {
        printf("WRONG!!!\n");
    }

    if (checkID(sample_input2)) {
        printf("CORRECT!!!\n");
    } else {
        printf("WRONG!!!\n");
    }

    return 0;
}

// 身分證字號檢查函式
int checkID(char id_number[]) {
    // 字母對應的代號
    char letter_code[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z', 'I', 'O'};
    
    // 確認字數是否為10
    if (strlen(id_number) != 10) {
        return 0;
    }

    // 取得英文字母的代號
    char letter = id_number[0];
    int code = -1;
    for (int i = 0; i < 26; ++i) {
        if (letter == letter_code[i]) {
            code = 10 + i;
            break;
        }
    }

    // 如果找不到對應的字母，返回錯誤
    if (code == -1) {
        return 0;
    }

    // 取得 X1 和 X2
    int x1 = code / 10;
    int x2 = code % 10;

    // 計算檢查碼
    int check_sum = x1 * 1 + x2 * 9 + (id_number[1] - '0') * 8 + (id_number[2] - '0') * 7 + (id_number[3] - '0') * 6 +
                    (id_number[4] - '0') * 5 + (id_number[5] - '0') * 4 + (id_number[6] - '0') * 3 + (id_number[7] - '0') * 2 +
                    (id_number[8] - '0');

    // 判斷檢查碼是否正確
    return (check_sum % 10 == 0);
}
