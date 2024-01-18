/**
 * @file maxmin.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief  This program is help to find miximum and minimum element from given array
 * @version 0.1
 * @date 2024-01-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* Aim 2: Find the minimum and maximum elements in the array*/
#include <stdio.h>
int main() {
  int arr[] = {5, 3, 9, 2, 8, 6, 1, 7, 4, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  int max = arr[0];
  int min = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  printf("Maximum element: %d\n", max);
  printf("Minimum element: %d\n", min);

  return 0;
}