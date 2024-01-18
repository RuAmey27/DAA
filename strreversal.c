/**
 * @file strreversal.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief This impements the logic of reversing the given string using recursion
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* Aim 1:Use recursion to reverse the given string */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

int main() {
    char *input = NULL;
    size_t bufferSize = 0;
    getline(&input, &bufferSize, stdin);
    size_t length = strlen(input);
    printf("Original String: %s\n", input);

    reverseString(input, 0, length - 1);

    printf("Reversed String: %s\n", input);
    free(input);
    return 0;
   
}
