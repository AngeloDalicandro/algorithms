import random
import time
import sys

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
 
    L = [0] * (n1)
    R = [0] * (n2)
 
    for i in range(0, n1):
        L[i] = arr[l + i]
 
    for j in range(0, n2):
        R[j] = arr[m + 1 + j]
 
    i = 0   
    j = 0     
    k = l     
 
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
 
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
 
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
 
def merge_sort(arr, l, r):
    if l < r:
 
        m = l+(r-l)//2
 
        merge_sort(arr, l, m)
        merge_sort(arr, m+1, r)
        merge(arr, l, m, r)
 


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
    merge_sort(random_array, 0, n - 1)
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