/**
 * @file recsot.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
// new function definition to put/place a value in the array with
int *fill(int *arr_original, int value, int *b)
{
    *b = value;//placing the new value to address stored in b
    b++;//moving to next pointer
    return b;
} 

void seperate(int *a, int size, int index, int *even, int *odd)
{
    if (index >= size)
    {
        return; //base case to terminate the recursion
    }
    else
    {
        if (a[index] % 2 == 0)
        {
            even = fill(even, a[index], even);//fun call to fill the array
        }
        else
        {
            odd = fill(odd, a[index], odd);// fun call to fill the array
        }
        seperate(a, size, index + 1, even, odd);// recursive call for the function 
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int aeven[n], aodd[n];
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    int *counter1 = aeven;
    int *counter2 = aodd;
    seperate(arr, n, 0, counter1, counter2);

    printf("Even : ");
    for (int i = 0; i < even; i++)
    {
        printf("%d\t", aeven[i]);
    }
    printf("\nOdd :");
    for (int i = 0; i < odd; i++)
    {
        printf("%d\t", aodd[i]);
    }
}
