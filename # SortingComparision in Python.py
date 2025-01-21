import time
import random

# Bubble Sort
def bubble_sort(arr):
    size = len(arr)
    for i in range(size - 1):
        for j in range(size - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Selection Sort
def selection_sort(arr):
    size = len(arr)
    for i in range(size - 1):
        min_idx = i
        for j in range(i + 1, size):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Merge Sort
def merge(arr, left, mid, right):
    L = arr[left:mid + 1]
    R = arr[mid + 1:right + 1]

    i = j = 0
    k = left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

# Quick Sort
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Measure Time
def measure_time(sort_func, arr):
    start = time.time()
    sort_func(arr)
    end = time.time()
    return end - start

def measure_time_recursive(sort_func, arr, left, right):
    start = time.time()
    sort_func(arr, left, right)
    end = time.time()
    return end - start

# Generate Arrays
def generate_arrays(size):
    best_case = list(range(size))
    worst_case = list(range(size, 0, -1))
    average_case = [random.randint(0, size) for _ in range(size)]
    return best_case, average_case, worst_case

# Compare Sorting Algorithms
def compare_sorting_algorithms(size):
    best_case, average_case, worst_case = generate_arrays(size)

    print(f"Sorting Performance for Array Size {size}\n")

    # Bubble Sort
    print(f"Bubble Sort - Best Case: {measure_time(bubble_sort, best_case[:])} seconds")
    print(f"Bubble Sort - Average Case: {measure_time(bubble_sort, average_case[:])} seconds")
    print(f"Bubble Sort - Worst Case: {measure_time(bubble_sort, worst_case[:])} seconds\n")

    # Selection Sort
    print(f"Selection Sort - Best Case: {measure_time(selection_sort, best_case[:])} seconds")
    print(f"Selection Sort - Average Case: {measure_time(selection_sort, average_case[:])} seconds")
    print(f"Selection Sort - Worst Case: {measure_time(selection_sort, worst_case[:])} seconds\n")

    # Merge Sort
    print(f"Merge Sort - Best Case: {measure_time_recursive(merge_sort, best_case[:], 0, len(best_case) - 1)} seconds")
    print(f"Merge Sort - Average Case: {measure_time_recursive(merge_sort, average_case[:], 0, len(average_case) - 1)} seconds")
    print(f"Merge Sort - Worst Case: {measure_time_recursive(merge_sort, worst_case[:], 0, len(worst_case) - 1)} seconds\n")

    # Quick Sort
    print(f"Quick Sort - Best Case: {measure_time_recursive(quick_sort, best_case[:], 0, len(best_case) - 1)} seconds")
    print(f"Quick Sort - Average Case: {measure_time_recursive(quick_sort, average_case[:], 0, len(average_case) - 1)} seconds")
    print(f"Quick Sort - Worst Case: {measure_time_recursive(quick_sort, worst_case[:], 0, len(worst_case) - 1)} seconds\n")

if __name__ == "__main__":
    size = 1000
    compare_sorting_algorithms(size)
