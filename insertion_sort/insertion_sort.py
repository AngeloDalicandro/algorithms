import random
import time


def insertion_sort(arr):  

    for step in range(1, len(arr)):
        key = arr[step]
        j = step - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j = j - 1

        arr[j + 1] = key


def generate_random_array(length):
    array = list(range(1, length + 1))  
    random.shuffle(array)  
    return array

def compare_arrays(array1, array2):
    if len(array1) != len(array2):
        return False

    for i in range(len(array1)):
        if array1[i] != array2[i]:
            return False

    return True

def test():
    random_array = generate_random_array(50000)

    correct_array = list(range(1, 500001)) 

    start_time = time.time()
    insertion_sort(random_array)
    end_time = time.time()
    execution_time = end_time - start_time


    print(compare_arrays(random_array, correct_array)) 
    print(f"Function execution time: {execution_time:.6f} seconds")

test()
