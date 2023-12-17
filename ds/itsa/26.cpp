#include <stdio.h>

// 函式原型
int calculateDigitSum(int num);
void sortNumbers(int arr[], int n);

int main() {
    int N;

    // 讀入 N
    scanf("%d", &N);

    // 讀入 N 個整數
    int numbers[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numbers[i]);
    }

    // 按照規則排序
    sortNumbers(numbers, N);

    // 輸出排序結果
    for (int i = 0; i < N; ++i) {
        if(i!=0){
            printf(" ");
        }
        printf("%d", numbers[i]);
    }

    return 0;
}

// 計算各位數字和的函式
int calculateDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// 按照規則排序的函式
void sortNumbers(int arr[], int n) {
    // 使用插入排序
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // 根據各位數字和和數值進行排序
        while (j >= 0 && (calculateDigitSum(arr[j]) > calculateDigitSum(key) || (calculateDigitSum(arr[j]) == calculateDigitSum(key) && arr[j] > key))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
