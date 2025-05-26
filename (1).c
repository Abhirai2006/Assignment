/***
1. Write a program that dynamically allocates a 2D array of size m × n. Fill it
with user input and print it using double-pointer notation (int **)
***/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int m, n, i, j;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    // Allocate memory for the row pointers
    arr = (int **)malloc(m * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate memory for each row
    for (i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            // Free previously allocated memory before exiting
            for (j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    // Read elements from the user
    printf("Enter elements of the %d x %d matrix:\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the matrix
    printf("\nThe matrix is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

