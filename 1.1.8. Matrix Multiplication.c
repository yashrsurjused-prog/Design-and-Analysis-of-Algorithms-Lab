#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Read Matrix A
    int A[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of Matrix B
    int r, p;
    if (scanf("%d %d", &r, &p) != 2) return 0;

    // Check if matrix multiplication is valid (cols of A == rows of B)
    if (n != r) {
        printf("Invalid input\n");
        return 0;
    }

    // Read Matrix B
    int B[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Compute Matrix Multiplication: C = A * B
    int C[100][100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d%s", C[i][j], (j == p - 1) ? "" : " ");
        }
        printf(" \n");
    }

    return 0;
}
