/**
 * @file recursort.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief '
 * Here basic problem is that to find all evens and odds we have to parse whole array i.e n iterations 
 * but at same time if we have to put new arrays indices goes mismatch try to solve the iss *
 * The another approach is using the malloc function. This is correctly working code try using malloc fun also. 
 * @version 0.1
 * @date 2024-01-18
 * @copyright Copyright (c) 2024
 */
#include<stdio.h>
int* fill(int* a,int value,int* b){
    *b=value;
    b++;
    return b;
}//new function definition 

int main(){
int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
int n = sizeof(arr) / sizeof(arr[0]);
int aeven[n],aodd[n];
    int even=0, odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    int* counter1=aeven;
    int* counter2=aodd;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            counter1=fill(aeven,arr[i],counter1);
        }
        else{
            counter2=fill(aodd,arr[i],counter2);
        }
    }
    printf("Even : ");
    for(int i=0;i<even;i++){
        printf("%d\t",aeven[i]);
    }
    printf("\nOdd :");
    for(int i=0;i<odd;i++){
        printf("%d\t",aodd[i]);
    }
}