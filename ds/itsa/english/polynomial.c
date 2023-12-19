#include <stdio.h>
#include <math.h>

// Function to calculate the binomial coefficient (n choose k)
long long int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
    }
}

// Function to compute coefficients of the polynomial
void computeCoefficients(int a, int b, int c, int d) {
    for (int i = 0; i <= d; ++i) {
        int coefficient = binomialCoefficient(d, i);
        coefficient *= pow(a, d - i) * pow(c, i);
        printf("%d ", coefficient);
    }
    printf("\n");
}

int main() {
    // Reading input values
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Computing and printing coefficients
    computeCoefficients(a, b, c, d);

    return 0;
}
