#include <stdio.h>

int main() {
    int a, b, c, d;
    int time = 0, ans = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    time = c * 60 + d - a * 60 - b;

    if (time > 120) {
        ans += 120;
        time -= 120;
    } else {
        ans += (time / 30) * 30;
        time = 0;
    }

    if (time > 120) {
        ans += 160;
        time -= 120;
    } else {
        ans += (time / 30) * 40;
        time = 0;
    }

    ans += (time / 30) * 60;

    printf("%d\n", ans);

    return 0;
}
