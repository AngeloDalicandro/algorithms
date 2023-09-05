#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void merge(int* arr, int lo, int hi, int mid)
{

    int* temp = (int*)malloc((hi-lo+1) * sizeof(int));

    if (arr == NULL) 
    {
        perror("Memory allocation failed");
        exit(1); 
    }

    int i, j, k;
    i = lo;
    k = 0;
    j = mid + 1;
 
    while (i <= mid && j <= hi)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
 
    while (j <= hi)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
 
    for (i = lo; i <= hi; i++)
    {
        arr[i] = temp[i-lo];
    }

    free(temp);
}


void mergeSort(int* arr, int lo, int hi) 
{

    int mid;

    if (lo < hi) 
    {
        mid = (lo + hi) / 2;

        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
 
        merge(arr, lo, hi, mid);
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
    mergeSort(randomArray, 0, n-1);
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
