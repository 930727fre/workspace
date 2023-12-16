#include <stdio.h>

int main() {
    char input[100];
    scanf("%s", input);

    // 建立右邊字元查詢表
    char keyboard_mapping[128] = {
        ' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ':', ';', '<', '=', '>', '?',
        '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
        '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 127
    };

    for (int i = 0; input[i] != '\0'; i++) {
        char current_char = input[i];

        // 查詢右邊字元
        char next_char = keyboard_mapping[current_char];

        // 若右邊字元為不可視或不存在，保持原樣輸出
        if (next_char == 127) {
            printf("%c", current_char);
        } else {
            printf("%c", next_char);
        }
    }

    // 換行
    printf("\n");

    return 0;
}
