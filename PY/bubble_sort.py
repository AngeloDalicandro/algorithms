import random
import time
import sys

def bubble_sort(arr):   
  for i in range(len(arr)):
    for j in range(0, len(arr) - i - 1):
      if arr[j] > arr[j + 1]:
        temp = arr[j]
        arr[j] = arr[j+1]
        arr[j+1] = temp

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

def test(n):

    n = int(n);    

    random_array = generate_random_array(n)

    correct_array = list(range(1, n + 1)) 

    start_time = time.time()
    bubble_sort(random_array)
    end_time = time.time()
    execution_time = end_time - start_time


    print(compare_arrays(random_array, correct_array)) 
    print(f"Function execution time: {execution_time:.6f} seconds")

if len(sys.argv) < 2:
    print("Usage: python script.py <argument>")
    sys.exit(1)

script_name = sys.argv[0]
argument = sys.argv[1]

test(argument)

print("Script name:", script_name)
print("Argument:", argument)