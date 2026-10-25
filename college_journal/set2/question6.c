#include <stdio.h>

int main() {
    int m, n, n2, p;

    printf("Enter rows and columns for first matrix (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and columns for second matrix (n p): ");
    scanf("%d %d", &n2, &p);

    if (n != n2) {
      printf("Matrix multiplication not possible.\n");
      return 1;
    }

    int a[m][n], b[n][p], result[m][p];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < p; j++) {
        result[i][j] = 0;
        for (int k = 0; k < n; k++) {
          result[i][j] += a[i][k] * b[k][j];
        }
      }
    }

    printf("Resultant matrix (%d x %d):\n", m, p);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < p; j++) {
        printf("%d\t", result[i][j]);
      }
      printf("\n");
    }

    return 0;
}