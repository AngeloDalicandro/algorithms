#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "test.h"

int* generateArray(int n) 
{

    int* arr = (int*)malloc(n * sizeof(int)); 

    if (arr == NULL) 
    {
        perror("Memory allocation failed");
        exit(1); 
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = i + 1;
    }

    return arr;
}

int* generateRandomArray(int n) 
{

    int* arr = generateArray(n);

    srand(time(NULL));

    for (int i = n - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return arr;
}

bool compareArrays(int arr1[], int arr2[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr1[i] != arr2[i]) {
            return false; 
        }
    }
    return true; 
}