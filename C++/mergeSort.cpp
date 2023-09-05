#include "iostream"
#include "chrono"
#include "algorithm"
#include "random"

const int n = 2000000;


void merge(int (&arr)[n], int lo, int hi, int mid)
{
    int i, j, k, temp[hi-lo+1];
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
}


void mergeSort(int (&arr)[n], int lo, int hi) {

    int mid;

    if (lo < hi) {

        mid = (lo + hi) / 2;
        // Split the data into two half.
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid+1, hi);
 
        // Merge them to get sorted output.
        merge(arr, lo, hi, mid);
    }
}

void generateRandomArray(int array[], int length) {
    // Fill the array with numbers from 1 to length
    for (int i = 0; i < length; ++i) {
        array[i] = i + 1;
    }
    
    // Shuffle the array using the random device as seed
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(array, array + length, gen);
}

void generateOrderedArray(int array[], int length) {
    // Fill the array with numbers from 1 to length
    for (int i = 0; i < length; ++i) {
        array[i] = i + 1;
    }
}

bool compareArrays(const int array1[], const int array2[], int length) {
    for (int i = 0; i < length; ++i) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}


int main(void) {

    int randomArray[n]; 
    int correctArray[n]; 
    generateRandomArray(randomArray, n);
    generateOrderedArray(correctArray, n);

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(randomArray, 0, n-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    bool isCorrect = compareArrays(randomArray, correctArray, n);

    if (isCorrect) {
        std::cout << "Correct, boi" << std::endl;
    } else {
        std::cout << "Wrong, boi" << std::endl;
    }

    std::cout << "Function execution time: " << duration.count() << " milliseconds" << std::endl;
}