#include <stdio.h>

int main() {
    int rows, cols, i, j;
    
    int first[10][10], second[10][10], difference[10][10];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element first[%d][%d]: ", i, j);
            scanf("%d", &first[i][j]);
        }
    }

    printf("\nEnter elements of the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element second[%d][%d]: ", i, j);
            scanf("%d", &second[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            difference[i][j] = first[i][j] - second[i][j];
        }
    }

    printf("\nResultant Matrix (First - Second):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", difference[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
