//ALI RAZA KHAN
//SORTING ALGORITHMS COMPARISON//

#include <iostream>
#include <ctime>  
#include <cstdlib>  

using namespace std;
//C:\Users\malir\source\repos\Algorithms\Sorting.cpp
// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double measureTime(void (*sortFunc)(int[], int), int arr[], int size) {
    clock_t start = clock();
    sortFunc(arr, size);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

double measureTimeRecursive(void (*sortFunc)(int[], int, int), int arr[], int left, int right) {
    clock_t start = clock();
    sortFunc(arr, left, right);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void generateArrays(int bestCase[], int averageCase[], int worstCase[], int size) {
    for (int i = 0; i < size; i++) {
        bestCase[i] = i;                    // Best case: already sorted
        worstCase[i] = size - i;             // Worst case: reverse sorted
    }

    srand(time(0));
    for (int i = 0; i < size; i++) {         // Average case: random values
        averageCase[i] = rand() % size;
    }
}

// Main function to compare sorting algorithms
void compareSortingAlgorithms(int size) {
    int bestCase[1000], averageCase[1000], worstCase[1000];
    generateArrays(bestCase, averageCase, worstCase, size);

    // Arrays to copy data into
    int arr[1000];

    cout << "Sorting Performance for Array Size " << size << "\n\n";

    // Bubble Sort
    copyArray(bestCase, arr, size);
    cout << "Bubble Sort - Best Case: " << measureTime(bubbleSort, arr, size) << " seconds\n";
    copyArray(averageCase, arr, size);
    cout << "Bubble Sort - Average Case: " << measureTime(bubbleSort, arr, size) << " seconds\n";
    copyArray(worstCase, arr, size);
    cout << "Bubble Sort - Worst Case: " << measureTime(bubbleSort, arr, size) << " seconds\n\n";

    // Selection Sort
    copyArray(bestCase, arr, size);
    cout << "Selection Sort - Best Case: " << measureTime(selectionSort, arr, size) << " seconds\n";
    copyArray(averageCase, arr, size);
    cout << "Selection Sort - Average Case: " << measureTime(selectionSort, arr, size) << " seconds\n";
    copyArray(worstCase, arr, size);
    cout << "Selection Sort - Worst Case: " << measureTime(selectionSort, arr, size) << " seconds\n\n";

    // Merge Sort
    copyArray(bestCase, arr, size);
    cout << "Merge Sort - Best Case: " << measureTimeRecursive(mergeSort, arr, 0, size - 1) << " seconds\n";
    copyArray(averageCase, arr, size);
    cout << "Merge Sort - Average Case: " << measureTimeRecursive(mergeSort, arr, 0, size - 1) << " seconds\n";
    copyArray(worstCase, arr, size);
    cout << "Merge Sort - Worst Case: " << measureTimeRecursive(mergeSort, arr, 0, size - 1) << " seconds\n\n";

    // Quick Sort
    copyArray(bestCase, arr, size);
    cout << "Quick Sort - Best Case: " << measureTimeRecursive(quickSort, arr, 0, size - 1) << " seconds\n";
    copyArray(averageCase, arr, size);
    cout << "Quick Sort - Average Case: " << measureTimeRecursive(quickSort, arr, 0, size - 1) << " seconds\n";
    copyArray(worstCase, arr, size);
    cout << "Quick Sort - Worst Case: " << measureTimeRecursive(quickSort, arr, 0, size - 1) << " seconds\n\n";
}

int main() {
    int size = 1000;
    compareSortingAlgorithms(size);
    return 0;
}
