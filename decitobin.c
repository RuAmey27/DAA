/**
 * @file decitobin.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief This program implements the logic to get binary of given decimal using the recursion
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* Aim 1 : TO convert the decimal input to the binary and show the output*/
#include<stdio.h>
int decimalToBinary(int n) {
  if (n == 0) {
    return 0;
  } else {
    return decimalToBinary(n / 2) * 10 + n % 2;
  }
}

int main() {
  int n;
  printf("Enter a decimal number: ");
  scanf("%d", &n);
  printf("The binary equivalent of %d is %d\n", n, decimalToBinary(n));
  return 0;
}