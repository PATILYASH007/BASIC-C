#include <stdio.h>

// Function to perform Insertion Sort on a character array
void insertionSort(char arr[], int size) {
    for (int i = 1; i < size; i++) {
        char key = arr[i];
        int j = i - 1;

        // Move elements greater than the key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place the key in its correct position
        arr[j + 1] = key;
    }
}


int main() {
    char arr[] = {'z', 'x', 'y', 'c', 't'};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    // Perform Insertion Sort
    insertionSort(arr, size);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    return 0;
}
