
int min(int a, int b){
    return (a > b) ? b : a;
}

int linearSearch(int arr[], int n, int target) {

    // Iterate linearly through the array
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    return -1;
}

// A recursive binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1
int binarySearchR(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchR(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearchR(arr, mid + 1, high, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}


// Returns index of x if present, else returns -1
int fibonnaciSearch(int arr[], int n, int x) {

    // initialize first three fibonacci numbers
    int a =  0, b = 1, c = 1;

    // iterate while c is smaller than n
    // c stores the smallest Fibonacci
    // number greater than or equal to n
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }

    // marks the eliminated range from front
    int offset = -1;

    // while there are elements to be inspected
    // Note that we compare arr[a] with x.
    // When c becomes 1, a becomes 08
    while (c > 1) {

        // check if a is a valid location
        int i = min(offset + a, n - 1);

        // if x is greater than the value at index a,
        // cut the subarray array from offset to i
        if (arr[i] < x) {
            c = b;
            b = a;
            a = c - b;
            offset = i;
        }

        // else if x is greater than the value at
        // index a,cut the subarray after i+1
        else if (arr[i] > x) {
            c = a;
            b = b - a;
            a = c - b;
        }

        // else if element found, return index
        else
            return i;
    }

    // comparing the last element with x
    if (b && arr[offset + 1] == x)
        return offset + 1;

    // element not found, return -1
    return -1;
}



int main() {
    //int arr[] = {2, 3, 4, 7, 1, 5};

    int arr[] = {1,2,3,4,5,7};

    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int index = linearSearch(arr, n, target);
    printf("%d\n", index);

    int index1 = binarySearch(arr, n, target);
    printf("%d\n", index1);

    int index3 = fibonnaciSearch(arr, n, target);
    printf("%d\n", index3);

    int index4 = binarySearchR(arr, 0,n-1, target);
    printf("%d\n", index3);

    return 0;
}
