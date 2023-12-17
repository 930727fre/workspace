#include <stdio.h>

float calculate_standard_weight(int height, int gender) {
    float standard_weight;
    
    if (gender == 1) {
        standard_weight = (height - 80) * 0.7;
    } else if (gender == 2) {
        standard_weight = (height - 70) * 0.6;
    }

    return standard_weight;
}

int main() {
    int height, gender;
    
    // 讀取輸入
    while (scanf("%d %d", &height, &gender)!=EOF)
    {
        // 計算標準體重並輸出結果
        float result = calculate_standard_weight(height, gender);
        
        if (result != -1) {
            printf("%.1f\n", result);
        }
    }



    return 0;
}
