#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

const int n = 50000;

void bubbleSort(int (&arr)[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j +1];
                arr[j + 1] = temp;
            }
        }
    }    

    // for (const auto& e : arr) {
    // std::cout << e << " - " << std::ends;
    // }
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
    bubbleSort(randomArray);
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