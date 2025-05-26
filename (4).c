/*****
4). Take a 2D array input from the user (using dynamic memory allocation) and
perform pointer arithmetic operations on it and print the results.
****/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int rows, cols;
    int i, j;

    // Get dimensions from the user
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate a 1D block for 2D data
    array = (int *)malloc(rows * cols * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements using pointer arithmetic
    printf("Enter elements for the 2D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", (array + i * cols + j));
        }
    }

    // Output elements using pointer arithmetic
    printf("\nArray using pointer arithmetic:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(array + i * cols + j));
        }
        printf("\n");
    }

    // Free memory
    free(array);
    return 0;
}
