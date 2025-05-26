/*****
6) Dynamically allocate a 3D array using triple pointers and store values in it.
Traverse and print the 3D array using pointer arithmetic.
****/

//Gemini

#include <stdio.h>  // For standard input/output functions
#include <stdlib.h> // For dynamic memory allocation (malloc, free)

int main() {
    int dim1, dim2, dim3; // Dimensions for the 3D array

    // Get dimensions from the user
    printf("Enter dimension 1 (depth/planes): ");
    scanf("%d", &dim1);
    printf("Enter dimension 2 (rows): ");
    scanf("%d", &dim2);
    printf("Enter dimension 3 (columns): ");
    scanf("%d", &dim3);

    // --- Dynamic Allocation of 3D Array (Triple Pointer) ---

    // Step 1: Allocate memory for dim1 number of 2D planes (array of int** pointers)
    int ***arr3D = (int ***)malloc(dim1 * sizeof(int **));
    if (arr3D == NULL) {
        printf("Memory allocation failed for dim1 pointers!\n");
        return 1;
    }

    // Step 2: For each dim1 pointer, allocate memory for dim2 number of rows (array of int* pointers)
    for (int i = 0; i < dim1; i++) {
        arr3D[i] = (int **)malloc(dim2 * sizeof(int *));
        if (arr3D[i] == NULL) {
            printf("Memory allocation failed for dim2 pointers in plane %d!\n", i);
            // Free previously allocated dim1 pointers and their contents
            for (int k = 0; k < i; k++) {
                // Before freeing arr3D[k], free its dim2 pointers (rows)
                for (int l = 0; l < dim2; l++) {
                    if (arr3D[k][l] != NULL) { // Check if row was allocated
                        free(arr3D[k][l]);
                    }
                }
                free(arr3D[k]);
            }
            free(arr3D);
            return 1;
        }

        // Step 3: For each dim2 pointer (row), allocate memory for dim3 number of columns (array of int)
        for (int j = 0; j < dim2; j++) {
            arr3D[i][j] = (int *)malloc(dim3 * sizeof(int));
            if (arr3D[i][j] == NULL) {
                printf("Memory allocation failed for dim3 elements in plane %d, row %d!\n", i, j);
                // Free memory for previously allocated parts if an error occurs
                for (int k_plane = 0; k_plane <= i; k_plane++) {
                    int limit_row = (k_plane == i) ? j : dim2;
                    for (int l_row = 0; l_row < limit_row; l_row++) {
                        if (arr3D[k_plane][l_row] != NULL) {
                            free(arr3D[k_plane][l_row]);
                        }
                    }
                    if (arr3D[k_plane] != NULL) {
                         free(arr3D[k_plane]);
                    }
                }
                free(arr3D);
                return 1;
            }
        }
    }

    printf("\n3D array successfully allocated (%d x %d x %d).\n", dim1, dim2, dim3);

    // --- Store values in the 3D array ---
    printf("\nEnter values for the 3D array:\n");
    for (int i = 0; i < dim1; i++) { // Iterate through planes
        for (int j = 0; j < dim2; j++) { // Iterate through rows
            for (int k = 0; k < dim3; k++) { // Iterate through columns
                printf("Enter value for arr3D[%d][%d][%d]: ", i, j, k);
                // Using array-like notation for input is generally clearer
                scanf("%d", &arr3D[i][j][k]);
            }
        }
    }

    // --- Traverse and Print the 3D array using Pointer Arithmetic ---
    printf("\n--- Contents of the 3D Array ---\n");
    for (int i = 0; i < dim1; i++) { // Iterate through planes
        printf("Plane %d:\n", i);
        for (int j = 0; j < dim2; j++) { // Iterate through rows
            for (int k = 0; k < dim3; k++) { // Iterate through columns
                // Pointer arithmetic for 3D array:
                // (arr3D + i) -> pointer to the (i-th) int** (plane pointer)
                // *(arr3D + i) -> dereferences to the (i-th) int** (the base address of the 2D array for that plane)
                // *(arr3D + i) + j -> pointer to the (j-th) int* (row pointer) within that plane
                // *(*(arr3D + i) + j) -> dereferences to the (j-th) int* (the base address of the 1D array for that row)
                // *(*(arr3D + i) + j) + k -> pointer to the (k-th) int element within that row
                // *(*(*(arr3D + i) + j) + k) -> dereferences to the actual int value
                printf("%d\t", *(*(*(arr3D + i) + j) + k));
            }
            printf("\n"); // Newline after each row
        }
        printf("\n"); // Extra newline after each plane for better readability
    }

    // --- Free Dynamically Allocated Memory (Crucial!) ---
    // Free in reverse order of allocation: innermost first
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            free(arr3D[i][j]); // Free columns (dim3) for each row
        }
        free(arr3D[i]); // Free rows (dim2) for each plane
    }
    free(arr3D); // Free the top-level array of plane pointers (dim1)
    arr3D = NULL; // Set the pointer to NULL after freeing

    printf("Memory successfully freed.\n");

    return 0; // Indicate successful execution
}
