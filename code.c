#include <stdio.h>
#include <stdlib.h>
//print array(after merge and quick sort)
void printArray(int array[], int size) {
    for (int index = 0; index < size; ++index) {
        printf("%d", array[index]);
        if (index + 1 == size) printf("\n");
        else printf(" ");
    }
}
//to merge array 
void merge(int array[], int temp[], int left, int middle, int right, long long *mergeComparisons) {
    int leftPartitionIndex = left;
    int rightPartitionIndex = middle + 1;
    int tempIndex = left;

    while (leftPartitionIndex <= middle && rightPartitionIndex <= right) {
        (*mergeComparisons)++;//how many times compare left side element with right side element
        if (array[leftPartitionIndex] <= array[rightPartitionIndex])
            temp[tempIndex++] = array[leftPartitionIndex++];
        else
            temp[tempIndex++] = array[rightPartitionIndex++];
    }
    while (leftPartitionIndex <= middle) temp[tempIndex++] = array[leftPartitionIndex++];
    while (rightPartitionIndex <= right) temp[tempIndex++] = array[rightPartitionIndex++];

    for (int index = left; index <= right; ++index)
        array[index] = temp[index];
}
//merge sort
void MergeSort(int array[], int temp[], int left, int right, long long *mergeComparisons) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    MergeSort(array, temp, left, middle, mergeComparisons);
    MergeSort(array, temp, middle + 1, right, mergeComparisons);
    merge(array, temp, left, middle, right, mergeComparisons);
}
//to swap 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//to find pivot index number 
int partition(int array[], int left, int right, long long *quickComparisons) {
    int pivot = array[right]; // last element as pivot
    int smallerindex = left - 1;

    for (int scanindex = left; scanindex < right; scanindex++) {
        (*quickComparisons)++;// how many times compare each element with pivot
        if (array[scanindex] < pivot) {
            smallerindex++;
            swap(&array[smallerindex], &array[scanindex]);
        }
    }
    swap(&array[smallerindex + 1], &array[right]);
    return smallerindex + 1;
}
//quick sort
void quicksort(int array[], int left, int right, long long *quickComparisons) {
    if (left >= right) return;
    int pivotindex = partition(array, left, right, quickComparisons);
    quicksort(array, left, pivotindex - 1, quickComparisons);
    quicksort(array, pivotindex + 1, right, quickComparisons);
}

// merge array of  original and new batch in ascending order
void finalmergeSorted(int a[], int n, int b[], int m, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i < n) result[k++] = a[i++];
    while (j < m) result[k++] = b[j++];
}
// Main function 
int main(void) {
    long long mergeComparisons = 0;
    long long quickComparisons = 0;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return 1;
    }

    int size, m;
    fscanf(file, "%d %d", &size, &m);

    int original[size], mergeArr[size], quickArr[size], temp[size];
    int newBatch[m + 1], updated[size + m + 1];

    for (int index = 0; index < size; ++index)
        fscanf(file, "%d", &original[index]);
    for (int index = 0; index < m; ++index)
        fscanf(file, "%d", &newBatch[index]);
    fclose(file);

    for (int index = 0; index < size; ++index) {
        mergeArr[index] = original[index];
        quickArr[index] = original[index];
    }

    MergeSort(mergeArr, temp, 0, size - 1, &mergeComparisons);
    quicksort(quickArr, 0, size - 1, &quickComparisons);

    printf("Merge Sort: ");
    printArray(mergeArr, size);
    printf("Quick Sort: ");
    printArray(quickArr, size);
    printf("Merge Comparisons: %lld\n", mergeComparisons);
    printf("Quick Comparisons: %lld\n", quickComparisons);

    finalmergeSorted(mergeArr, size, newBatch, m, updated);
    printf("Updated Array: ");
    printArray(updated, size + m);

    return 0;
}
