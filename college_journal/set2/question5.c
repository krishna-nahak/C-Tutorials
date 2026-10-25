#include <stdio.h>

// Matrix Addition or subtraction rule
// they must have same order

int main() {

  int rows, columns;
  printf("Enter no. of Rows (n): ");
  scanf("%d", &rows);

  printf("Enter no. of Columns (m): ");
  scanf("%d", &columns);

  int matrix1[rows][columns];
  int matrix2[rows][columns];
  int res[rows][columns];

  printf("Enter elements for matrix1\n");
  for(int i=0; i<rows; i++) {
    for(int j=0; j<columns; j++) {
      printf("matrix1[%d][%d]: ", i, j);
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Enter elements for matrix2\n");
  for(int i=0; i<rows; i++) {
    for(int j=0; j<columns; j++) {
      printf("matrix2[%d][%d]: ", i, j);
      scanf("%d", &matrix2[i][j]);
    }
  }

  printf("Choose an options: \n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");

  int choice;
  printf("Your choice (1/2): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Sum of two matrix is\n");
      printf("Enter elements for matrix2\n");
      for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
          res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
      }
      break;

    case 2:
      printf("Sum of two matrix is\n");
      printf("Enter elements for matrix2\n");
      for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
          res[i][j] = matrix1[i][j] - matrix2[i][j];
        }
      }
      break;

    default:
      printf("Invalid choice.\n");
  }


  for(int i=0; i<rows; i++) {
    for(int j=0; j<columns; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }

  return 0;
}