/**
 * @file seperation.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-18
 * @copyright Copyright (c) 2024
 * 
 */
/* Aim : Seperate the odd and even integers into seperate arrays by using recursion and without recursion*/
#include <list>
#include <iostream>
int main() {
    std::list<int> even;
    std::list<int> odd;
    int arr[]={1,2,3,4,5,6,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }
    std::cout<< "The even no list\n";
    for (int elem : even) {
        std::cout << elem << " "<<"\n";
    }
    std::cout<< "The odd no list\n";
     for (int elem : odd) {
        std::cout << elem << " ";
    }
    return 0;
}



