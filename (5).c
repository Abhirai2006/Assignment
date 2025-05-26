/*****
5). A program to sort elements of an array using quick sort and searching an
element using binary search.
****/
#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp, key, low, high, mid;

    // Input
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Quick Sort
    void quickSort(int a[], int low, int high) {
        if (low < high) {
            int pivot = a[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (a[j] < pivot) {
                    i++;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            temp = a[i + 1];
            a[i + 1] = a[high];
            a[high] = temp;

            int pi = i + 1;
            quickSort(a, low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    }

    // quickSort(arr, 0, n - 1);

    // Output sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Binary Search
    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        } else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (!found)
        printf("Element not found.\n");

    return 0;
}
