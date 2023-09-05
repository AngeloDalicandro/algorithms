#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "test.h"

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int temp;

            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

int main(int argc, char *argv[]) {
    
    int n = atoi(argv[1]);

    int* correctArray = generateArray(n);

    int* randomArray = generateRandomArray(n);

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    bubbleSort(randomArray, n);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    bool isCorrect = compareArrays(randomArray, correctArray, n);

    free(correctArray);
    free(randomArray);

    if (isCorrect) {
        printf("Correct, boi\n");
    } else {
        printf("Wrong, boi\n");
    }

    printf("Execution Time: %f seconds\n", cpu_time_used);
}
