//https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/  and insertion and bubble from same site

#include <stdbool.h>
#include <stdio.h>
#include <string.h> // Required for memcpy

int m;

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        printf("array after iteration i = %d: \n",i);
        printArray(arr, n);
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
        {
            printf("No more comparisons needed - breaking \n");
            break;
        }

    }
}

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            //printf("comparison for right position of the element \n");
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        printf("array after iteration i = %d: \n",i);
        printArray(arr, n);

    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }

        // Move minimum element to its
        // correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        printf("array after iteration i = %d: \n",i);
        printArray(arr, n);
    }
}

// partition function
int partition(int arr[], int low, int high) {

    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;
    int j=low;
    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to
    // i are smaller after every iteration
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    //printf("In partition after looping -- i=%d   j=%d  and pivot = %d   ", i,j, pivot);

    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
    printf("In Quicksort low = %d and high = %d  ",low,high);
    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        printf("Pivot Index computed = %d and Array after partition is ",pi);
        //printf("pi = %d  and Array after partition is ",pi);
        printArray(arr,m);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    printf("Returning from Quicksort low = %d and high = %d  \n",low,high);
}



// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){

    printf("Calling merge with l=%d   m=%d   r=%d \n",l,m,r);

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r){
    //printf("Calling mergeSort with l=%d  r=%d \n",l,r);
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


// Function to heapify the tree
void heapify(int array[], int size, int i) {
  if (size == 1) {
    //printf("Single element in the heap");
    return;
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

void build_maxheap(int Arr[ ], int size)
{
    //printArray(Arr, size);
    int N=size;
    for(int i = (N/2-1) ; i >= 0 ; i-- )
    {
        //max_heapify (Arr, i) ;
        heapify(Arr, size, i);
    }
}


void heap_sort(int Arr[], int size)
{
    int heap_size = size;
    build_maxheap(Arr, size);
    for(int i = size-1; i>=1 ; i-- )
    {
        swap(&Arr[ 0 ], &Arr[ i ]);
        heap_size = heap_size-1;
        //max_heapify(Arr, 1, heap_size);
        heapify(Arr, heap_size, 0);
    }
}


// Function to print an array
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){

    //int unsortedArr[] = { 4,4,4,4 };
    //int unsortedArr[] = { 50,40,30,20,10 };
    //int unsortedArr[] = { 10,20,30,40,50 };
    //int unsortedArr[] = { 10,21,18,11,14 };
    int unsortedArr[] = { 30,70,80,50,20,10,90,50,40 };
    int n = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    int arr[n];
    m=n;


    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: BUBBLE SORT \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");

    // Copy the entire block of memory
    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: INSERTION SORT \n");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");

    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: SELECTION SORT \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");


    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: QUICK SORT Lomuto Partition \n");
    printArray(arr, n);
    quickSort(arr, 0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");

    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: Merge Sort \n");
    printArray(arr, n);
    mergeSort(arr, 0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");

    memcpy(arr, unsortedArr, sizeof(unsortedArr));
    printf("Original array: Heap Sort \n");
    printArray(arr, n);
    heap_sort(arr,n);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("\n");

    return 0;
}
