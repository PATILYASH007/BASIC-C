#include <stdio.h>

// Function to perform Bubble Sort on a character array
void bubbleSort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                // Swap the characters
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char arr[] = {'d', 'b', 'a', 'c', 'e'};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    // Perform Bubble Sort
    bubbleSort(arr, size);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    return 0;
}
