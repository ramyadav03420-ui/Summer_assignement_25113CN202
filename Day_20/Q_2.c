#include <stdio.h>

int main() {
    int rows, cols;
    int isSymmetric = 1;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("The matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; 
                break; 
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }

    if (isSymmetric) {
        printf("\nThe given matrix is a SYMMETRIC matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a symmetric matrix.\n");
    }

    return 0;
}
