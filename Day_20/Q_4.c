#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j, colSum;

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nYour Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nColumn-wise Sum:\n");
    for (j = 0; j < cols; j++) {
        colSum = 0; 
        for (i = 0; i < rows; i++) {
            colSum += matrix[i][j]; 
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
