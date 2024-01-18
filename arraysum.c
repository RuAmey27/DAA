/**
 * @file arraysum.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief  This program helps to find the sum of array element using recursion
 * @version 0.1
 * @date 2024-01-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*Aim 2: Find the sum of array elements using the recursion*/
#include <stdio.h>

int sum(int *a, int size, int index) {
    if (index < size) {
        return a[index] + sum(a, size, index + 1);
    } else {
        return 0;
    }
}

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int len = sizeof(a) / sizeof(a[0]);
    int addition = sum(a, len, 0);//here  initial parameters are passed
    printf("%d", addition);

    return 0;
}