#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; ++t) {
        int T, m, k;
        scanf("%d %d %d", &T, &m, &k);

        int prices[k];
        for (int i = 0; i < k; ++i) {
            scanf("%d", &prices[i]);
        }

        // 將價格升序排序
        qsort(prices, k, sizeof(int), compare);

        int total_cost = 0;
        int purchased = 0;

        // 選購禮品
        for (int i = 0; i < k; ++i) {
            if (purchased < m) {
                total_cost += prices[i];
                purchased++;
            } else {
                break;
            }
        }

        // 判斷是否有足夠預算購買足夠量的禮物
        if (purchased < m) {
            printf("Impossible\n");
        } else {
            printf("%d\n", total_cost);
        }
    }

    return 0;
}
