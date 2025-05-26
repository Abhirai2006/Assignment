/*****
3). Dynamically allocate two matrices of same row count and different column
count. Concatenate them horizontally into a third dynamically allocated matrix.
****/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat1, **mat2, **result;
    int rows, cols1, cols2, i, j;

    // Input number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns in Matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter number of columns in Matrix 2: ");
    scanf("%d", &cols2);

    // Allocate memory for mat1
    mat1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        mat1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // Allocate memory for mat2
    mat2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        mat2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Allocate memory for result matrix
    result = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        result[i] = (int *)malloc((cols1 + cols2) * sizeof(int));
    }

    // Input Matrix 1
    printf("\nEnter elements of Matrix 1 (%d x %d):\n", rows, cols1);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols1; j++) {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input Matrix 2
    printf("\nEnter elements of Matrix 2 (%d x %d):\n", rows, cols2);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols2; j++) {
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Print Matrix 1
    printf("\nMatrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    // Print Matrix 2
    printf("\nMatrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // Horizontal concatenation
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols1; j++) {
            result[i][j] = mat1[i][j];
        }
        for (j = 0; j < cols2; j++) {
            result[i][cols1 + j] = mat2[i][j];
        }
    }

    // Print the result matrix
    printf("\nHorizontally concatenated matrix (%d x %d):\n", rows, cols1 + cols2);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols1 + cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(result[i]);
    }
    free(mat1);
    free(mat2);
    free(result);

    return 0;
}

