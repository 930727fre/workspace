#include <stdio.h>

int check(int v[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == v[i][1] && v[i][1] == v[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (v[0][i] == v[1][i] && v[1][i] == v[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (v[0][0] == v[1][1] && v[2][2] == v[1][1]) {
        return 1;
    }
    if (v[0][2] == v[1][1] && v[2][0] == v[1][1]) {
        return 1;
    }

    return 0;
}

int main() {
    int v[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    if (check(v)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
