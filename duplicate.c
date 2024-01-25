/**
 * @file aim.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*Aim : write a program to find the duplictes and their count of repetition count */
#include <stdio.h>

void findRepeatedElements(int arr[], int size) {
    // Traverse the array
    for (int i = 0; i < size; i++) {
        // Skip elements that have been processed
        if (arr[i] == -1) {
            continue;
        }

        int count = 1; // Initialize count for the current element

        // Check for repetition starting from the next element
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1; // Mark the repeated element to avoid duplicate counting
            }
        }

        // If count is greater than 1, the element is repeated
        if (count > 1) {
            printf("Element %d is repeated %d times\n", arr[i], count);
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find repeated elements and their counts
    findRepeatedElements(arr, size);

    return 0;
}
