/*****
2). Input two arrays of different sizes. Dynamically allocate a new array that
combines both and print the result.
****/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2;
    int size1, size2, i;

    // Input size of the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    // Allocate memory for the first array
    arr1 = (int *)malloc(size1 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed for first array.\n");
        return 1;
    }

    // Input elements for the first array
    printf("Enter elements of the first array:\n");
    for (i = 0; i < size1; i++) {
        printf("arr1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }

    // Input size of the second array
    printf("\nEnter the size of the second array: ");
    scanf("%d", &size2);

    // Allocate memory for the second array
    arr2 = (int *)malloc(size2 * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed for second array.\n");
        free(arr1);
        return 1;
    }

    // Input elements for the second array
    printf("Enter elements of the second array:\n");
    for (i = 0; i < size2; i++) {
        printf("arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }

    // Reallocate memory for arr1 to hold both arrays
    arr1 = (int *)realloc(arr1, (size1 + size2) * sizeof(int));
    if (arr1 == NULL) {
        printf("Reallocation failed.\n");
        free(arr2);
        return 1;
    }

    // Copy elements of arr2 into the end of arr1
    for (i = 0; i < size2; i++) {
        arr1[size1 + i] = arr2[i];
    }

    // Print the combined array
    printf("\nCombined array:\n");
    for (i = 0; i < size1 + size2; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr1);
    free(arr2);

    return 0;
}
