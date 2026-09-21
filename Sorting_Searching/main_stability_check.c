#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

// struct for stability
typedef struct
{
    int value;
    int originalPos;
} Element;



void swap_261100690007(Element *xp, Element *yp)
{
    Element temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// print array
void printArray_261100690007(Element arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d(%d) ", arr[i].value, arr[i].originalPos);
    }
    printf("\n");
}


// print value
void printValues_261100690007(Element arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}


// Bubble sort
void bubbleSort_261100690007(Element arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].value > arr[j + 1].value)
            {
                swap_261100690007(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        printf("Array after iteration i = %d:\n", i);
        printArray_261100690007(arr, n);
        if (swapped == false)
        {
            printf("No more comparisons needed - breaking\n");
            break;
        }
    }
}



// Insertion Sort
void insertionSort_261100690007(Element arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Element key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].value > key.value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Array after iteration i = %d:\n", i);
        printArray_261100690007(arr, n);
    }
}


// Selection sort
void selectionSort_261100690007(Element arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].value < arr[min_idx].value)
            {
                min_idx = j;
            }
        }
        swap_261100690007(&arr[i], &arr[min_idx]);
        printf("Array after iteration i = %d:\n", i);
        printArray_261100690007(arr, n);
    }
}


// Partition for Quick Sort
int partition_261100690007(Element arr[], int low, int high)
{
    int pivot = arr[high].value;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].value < pivot)
        {
            i++;

            swap_261100690007(&arr[i], &arr[j]);
        }
    }
    swap_261100690007(&arr[i + 1], &arr[high]);
    return i + 1;
}


// Quick Sort
void quickSort_261100690007(Element arr[], int low, int high, int n)
{
    printf("In Quicksort low = %d and high = %d\n", low, high);
    if (low < high)
    {
        int pi = partition_261100690007(arr, low, high);
        printf("Pivot Index computed = %d\n", pi);
        printf("Array after partition:\n");
        printArray_261100690007(arr, n);
        quickSort_261100690007(arr, low, pi - 1, n);
        quickSort_261100690007(arr, pi + 1, high, n);
    }
    printf("Returning from Quicksort low = %d and high = %d\n", low, high);
}



// Merge function
void merge_261100690007(Element arr[], int l, int mid, int r)
{
    printf("Calling merge with l=%d m=%d r=%d\n",l, mid, r);
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    Element L[n1];
    Element R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].value <= R[j].value)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Merge Sort
void mergeSort_261100690007(Element arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort_261100690007(arr, l, mid);
        mergeSort_261100690007(arr, mid + 1, r);
        merge_261100690007(arr, l, mid, r);
    }
}


// Heapify Function
void heapify_261100690007(Element array[], int size, int i)
{
    if (size == 1)
    {
        return;
    }

    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size &&
        array[l].value > array[largest].value)
    {
        largest = l;
    }
    if (r < size &&
        array[r].value > array[largest].value)
    {
        largest = r;
    }
    if (largest != i)
    {
        swap_261100690007(&array[i], &array[largest]);
        heapify_261100690007(array, size, largest);
    }
}


// Max Heap
void build_maxheap_261100690007(Element arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify_261100690007(arr, size, i);
    }
}


// Heap Sort
void heap_sort_261100690007(Element arr[], int size)
{
    int heap_size = size;
    build_maxheap_261100690007(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap_261100690007(&arr[0], &arr[i]);
        heap_size--;
        heapify_261100690007(arr, heap_size, 0);
    }
}



// Check Stability
bool checkStability_261100690007(Element arr[], int n)
{
    // For every pair of equal values, their original positions must be increasing.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].value == arr[j].value)
            {
                if (arr[i].originalPos > arr[j].originalPos)
                {
                    return false;
                }
            }
        }
    }

    return true;
}


//  Display Stability Results
void displayStability_261100690007(Element arr[], int n)
{
    printf("\nSTABILITY \n\n");
    printf("Value(Original Position):\n");
    printArray_261100690007(arr, n);
    printf("\n");
    if (checkStability_261100690007(arr, n))
    {
        printf("RESULT: STABLE\n");
        printf("Relative order of equal elements is preserved.\n");
    }
    else
    {
        printf("RESULT: NOT STABLE\n");
        printf("Relative order of equal elements has changed.\n");
    }

    printf("\n");
}


// Function to take array input
int inputArray_261100690007(Element arr[])
{
    int n;
    printf("\nEnter number of elements (1-%d): ", MAX);
    scanf("%d", &n);
    while (n < 1 || n > MAX)
    {
        printf("Invalid size!\n");
        printf("Enter number of elements (1-%d): ", MAX);
        scanf("%d", &n);
    }
    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i].value);
        // Save original position.
        arr[i].originalPos = i + 1;
    }
    return n;
}



void displayMenu_261100690007()
{
    printf("\n");
    printf("\nSORTING & STABILITY MENU\n\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Display Input Array\n");
    printf("8. Check Stability of All Algorithms\n");
    printf("9. Enter New Array\n");
    printf("10. Exit\n\n");
}


void performSort_261100690007(int choice, Element original[], int n)
{
    Element arr[MAX];

    //Copy original array
    memcpy(arr, original, n * sizeof(Element));
    printf("\n\n");

    switch (choice)
    {
        case 1:
            printf("BUBBLE SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            bubbleSort_261100690007(arr, n);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        case 2:
            printf("INSERTION SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            insertionSort_261100690007(arr, n);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        case 3:
            printf("SELECTION SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            selectionSort_261100690007(arr, n);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        case 4:
            printf("QUICK SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            quickSort_261100690007(arr, 0, n - 1, n);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        case 5:
            printf("MERGE SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            mergeSort_261100690007(arr, 0, n - 1);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        case 6:
            printf("HEAP SORT\n\n");
            printf("Original Array:\n");
            printArray_261100690007(arr, n);
            printf("\n");
            heap_sort_261100690007(arr, n);
            printf("\nSorted Array:\n");
            printArray_261100690007(arr, n);
            displayStability_261100690007(arr, n);
            break;

        default:
            printf("Invalid sorting choice!\n");
    }

    printf("\n");
}


// To check all the algorithms at once
void checkAllAlgorithms_261100690007(Element original[], int n)
{
    Element arr[MAX];

    printf("\n");
    printf("STABILITY OF ALL ALGORITHMS\n\n");

    // Bubble Sort
    memcpy(arr, original, n * sizeof(Element));

    bubbleSort_261100690007(arr, n);

    printf("\nBubble Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    // Insertion Sort
    memcpy(arr, original, n * sizeof(Element));

    insertionSort_261100690007(arr, n);

    printf("\nInsertion Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    // Selection Sort
    memcpy(arr, original, n * sizeof(Element));

    selectionSort_261100690007(arr, n);

    printf("\nSelection Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    // Quick Sort
    memcpy(arr, original, n * sizeof(Element));

    quickSort_261100690007(arr, 0, n - 1, n);

    printf("\nQuick Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    // Merge Sort
    memcpy(arr, original, n * sizeof(Element));

    mergeSort_261100690007(arr, 0, n - 1);

    printf("\nMerge Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    // Heap Sort
    memcpy(arr, original, n * sizeof(Element));

    heap_sort_261100690007(arr, n);

    printf("\nHeap Sort: ");

    if (checkStability_261100690007(arr, n))
        printf("STABLE\n");
    else
        printf("NOT STABLE\n");


    printf("\n\n");
}


int main()
{
    Element original[MAX];

    int n;
    int choice;


    printf("\nSORTING ALGORITHM & STABILITY PROGRAM\n\n");

    n = inputArray_261100690007(original);

    do
    {
        displayMenu_261100690007();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                performSort_261100690007(1, original, n);
                break;

            case 2:
                performSort_261100690007(2, original, n);
                break;

            case 3:
                performSort_261100690007(3, original, n);
                break;

            case 4:
                performSort_261100690007(4, original, n);
                break;

            case 5:
                performSort_261100690007(5, original, n);
                break;

            case 6:
                performSort_261100690007(6, original, n);
                break;

            case 7:
                printf("\nInput Array:\n");
                printf("Value(Original Position)\n");
                printArray_261100690007(original, n);
                printf("\nValues only:\n");
                printValues_261100690007(original, n);
                break;

            case 8:
                checkAllAlgorithms_261100690007(original, n);
                break;

            case 9:
                printf("\nEnter New Array\n\n");
                n = inputArray_261100690007(original);
                printf("\nNew array successfully stored.\n");
                break;

            case 10:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                printf("Please enter a number between 1 and 10.\n");
        }

    } while (choice != 10);

    return 0;
}
