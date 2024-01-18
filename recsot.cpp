/**
 * @file recsot.cpp
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <list>
#include <iostream>

std::list<int> even;
std::list<int> odd;

void seperate(int* a, int size, int index) {
    if (index >= size) {
        return;  
    } else {
        if (a[index] % 2 == 0) {
            even.push_back(a[index]);
        } else {
            odd.push_back(a[index]);
        }
        seperate(a, size, index + 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    seperate(arr, n, 0);

    std::cout << "The even no list\n";
    for (int elem : even) {
        std::cout << elem << " ";
    }

    std::cout << "\nThe odd no list\n";
    for (int elem : odd) {
        std::cout << elem << " ";
    }

    return 0;
}
