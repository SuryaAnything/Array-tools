/**
 * @file arrays_utils.h
 * @brief Header file providing a set of array operations through function pointers.
 *
 * Usage:
 * - Include this header.
 * - Initialize functions with useArrayFunctions().
 * - Access array functions via the Arrays structure(Arrays.{function}).
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Returns a copy of a specified range of an array.
 */
int* copyOfRange(const int* arr, int start, int end);

/**
 * @brief Rotates an array to the right by a specified number of positions.
 */
int* rotate(int* arr, int n, int k);

/**
 * @brief Searches for the first occurrence of a value in the array using linear search.
 */
int searchLIN(const int* arr, int n, int sr);

/**
 * @brief Searches for all occurrences of a value in the array.
 */
int search(const int* arr, int n, int sr);

/**
 * @brief Searches for the first occurrence of a value in the sorted array using binary search.
 */
int searchBIN(const int* arr, int n, int sr);

/**
 * @brief Reverses the elements of an array in-place.
 */
int* reverse(int* arr, int n);

/**
 * @brief Counts the occurrences of the maximum value in the array.
 */
int MAX_count(const int* arr, int n);

/**
 * @brief Finds the minimum value in the array.
 */
int getminOf(const int* arr, int n);

/**
 * @brief Finds the maximum value in the array.
 */
int getmaxOf(const int* arr, int n);

/**
 * @brief Converts an integer array to a string representation.
 */
char* convertToString(const int* arr, int n);

/**
 * @brief Sorts an array using the dual-pivot QuickSort algorithm.
 */
void dualPivotQuickSort(int* arr, int low, int high);

/**
 * @brief Compare one array with another array digit by digit.
*/
bool compareTwoArray(int* arr1, int size1, int* arr2, int size2);

/**
 * @brief Calculate the sum of all the elements of an array.
*/
int sumAllElements(int* arr, int n);

/**
 * @brief Check whether the array is Sorted in increasing order or not.
*/
bool checkForSort(int* arr, int n);

/**
 * @brief Concatenate two arrays.
*/
int* concatenateTwoArrays(int* arr1, int size1, int* arr2, int size2);

/**
 * @brief Return the index of first Occurrence of the element.
*/
int firstIndexOf(int* arr, int n, int element);

/**
 * @brief Generate a HashCode and returns a unique integer value.
*/
unsigned long long getHashCodeOf(int* arr, int n);

typedef enum {
    SUCCESS,
    FAILURE,
}status_code;

/**
 * @struct Array_Functions
 * @brief Represents a collection of array operations using function pointers.
 */
typedef struct {
    int* (*copyOfRange)(const int*, int, int);
    int* (*rotate)(int*, int, int);
    int (*searchLIN)(const int*, int, int);
    int (*search)(const int*, int, int);
    int (*searchBIN)(const int*, int, int);
    int* (*reverse)(int*, int);
    int (*maxValue)(const int*, int);
    int (*minValue)(const int*, int);
    int (*getMaxOccurrence)(const int*, int);
    char* (*toString)(const int*, int);
    void (*sort)(int*, int, int);
    bool (*compare)(int* arr1, int size1, int* arr2, int size2);
    int (*sum) (int* arr, int n);
    bool (*isSorted)(int* arr, int n);
    int* (*concat)(int* arr1, int size1, int* arr2, int size2);
    int (*indexOf)(int* arr, int n, int element);
    unsigned long long (*hashCode)(int* arr, int n);
}Array_Functions;

Array_Functions Arrays;

status_code useArrayFunctions();



/**
 * @brief Initializes the Array_Functions structure with appropriate function pointers.
 */
status_code useArrayFunctions() {
    Arrays.copyOfRange = copyOfRange;
    Arrays.getMaxOccurrence = MAX_count;
    Arrays.toString = convertToString;
    Arrays.maxValue = getmaxOf;
    Arrays.minValue = getminOf;
    Arrays.reverse = reverse;
    Arrays.rotate = rotate;
    Arrays.search = search;
    Arrays.searchBIN = searchBIN;
    Arrays.searchLIN = searchLIN;
    Arrays.sort = dualPivotQuickSort;
    Arrays.compare = compareTwoArray;
    Arrays.sum = sumAllElements;
    Arrays.isSorted = checkForSort;
    Arrays.concat = concatenateTwoArrays;
    Arrays.indexOf = firstIndexOf;
    Arrays.hashCode = getHashCodeOf;
    return SUCCESS;
}

/**
 * 
 * Function: copyOfRange
 * ---------------------
 * Creates a copy of a specified range of an array.
 *
 * Parameters:
 * - arr: The original array.
 * - start: The starting index of the range.
 * - end: The ending index of the range.
 *
 * Returns:
 * A new array containing the specified range of elements.
 * NOTE: The array returned must be freed explicitly by the user.
 */
inline int* copyOfRange(const int* arr, int start, int end) {
    int *ret_arr = (int*)malloc(end - start);
    for (int i = 0, j = start; i < end - start; ++i, ++j) {
        ret_arr[i] = arr[j];
    }
    return ret_arr;
}

/**
 * Function: rotate
 * ----------------
 * Rotates an array to the right by a specified number of positions.
 *
 * Parameters:
 * - arr: The array to be rotated.
 * - n: The size of the array.
 * - k: The number of positions to rotate the array.
 *
 * Returns:
 * The rotated array.
 * 
 * NOTE: The array returned must be freed explicitly by the user.
 */
inline int* rotate(int* arr, int n, int k) {
    k = k % n;
    for (int i = 0; i < k; ++i) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
    return arr;
}

/**
 * Function: searchLIN
 * -------------------
 * Searches for the first occurrence of a value in the array using linear search.
 *
 * Parameters:
 * - arr: The array to be searched.
 * - n: The size of the array.
 * - sr: The value to search for.
 *
 * Returns:
 * The index of the first occurrence of the value, or -1 if not found.
 */
inline int searchLIN(const int* arr, int n, int sr) {
    int index = -1;
    for (int i = 0; i < n && index < 0; ++i) {
        if (arr[i] == sr) {
            index = i;
        }
    }
    return index;
}

/**
 * Function: search
 * ----------------
 * Searches for all occurrences of a value in the array.
 *
 * Parameters:
 * - arr: The array to be searched.
 * - n: The size of the array.
 * - sr: The value to search for.
 *
 * Returns:
 * The count of occurrences and prints the indices of each occurrence.
 */
inline int search(const int* arr, int n, int sr) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == sr) {
            printf("%d ", i);
            count++;
        }
    }
    return count;
}

/**
 * Function: searchBIN
 * -------------------
 * Searches for the first occurrence of a value in the sorted array using binary search.
 *
 * Parameters:
 * - arr: The sorted array to be searched.
 * - n: The size of the array.
 * - sr: The value to search for.
 *
 * Returns:
 * The index of the first occurrence of the value, or -1 if not found.
 */
inline int searchBIN(const int* arr, int n, int sr) {
    int start = 0, end = n, mid;
    int index = -1;
    while (start < end && index != mid) {
        mid = (start + end) / 2;
        if (arr[mid] == sr)
            index = mid;
        else if (arr[mid] < sr)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return index;
}

/**
 * Function: reverse
 * -----------------
 * Reverses the elements of an array in-place.
 *
 * Parameters:
 * - arr: The array to be reversed.
 * - n: The size of the array.
 *
 * Returns:
 * The reversed array.
 * 
 * NOTE: The array returned must be freed explicitly by the user.
 */
inline int* reverse(int* arr, int n) {
    for (int i = 0; i < n / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    return arr;
}

/**
 * Function: MAX_count
 * -------------------
 * Counts the occurrences of the maximum value in the array.
 *
 * Parameters:
 * - arr: The array to be processed.
 * - n: The size of the array.
 *
 * Returns:
 * The count of occurrences of the maximum value.
 */
inline int MAX_count(const int* arr, int n) {
    int maximum = arr[0];
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maximum) {
            count = 1;
        } else if (arr[i] == maximum)
            count++;
    }
    return count;
}

/**
 * Function: getminOf
 * -------------------
 * Finds the minimum value in the array.
 *
 * Parameters:
 * - arr: The array to be processed.
 * - n: The size of the array.
 *
 * Returns:
 * The minimum value in the array.
 */
inline int getminOf(const int* arr, int n) {
    int minimum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

/**
 * Function: getmaxOf
 * -------------------
 * Finds the maximum value in the array.
 *
 * Parameters:
 * - arr: The array to be processed.
 * - n: The size of the array.
 *
 * Returns:
 * The maximum value in the array.
 */
inline int getmaxOf(const int* arr, int n) {
    int maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

/**
 * Function: convertToString
 * -------------------------
 * Converts an integer array to a string representation.
 *
 * Parameters:
 * - arr: The array to be converted.
 * - n: The size of the array.
 *
 * Returns:
 * A string representation of the array.
 * 
 * NOTE: The array returned must be freed explicitly by the user.
 */
inline char* convertToString(const int* arr, int n) {
    char* ch = (char*)(malloc(2000));
    ch[0] = '[';
    ch[1] = '\0';
    int count;
    if (n == 0) {
        count = snprintf(ch, 2000, "%s%s", ch, "NULL");
        ch[count] = ']';
        ch[count + 1] = '\0';
    } 
    else{
        for (int i=0; i<n; i= i + 1) {
            count = snprintf(ch, 2000, "%s%d, ",ch,arr[i]);
        }
        ch[count-2] = ']';
        ch[count-1] = '\0';
    }

    return ch;
}


struct record {
    int left;
    int right;
};
/**
 * Function: swapNumbers
 * ---------------------
 * Swaps two elements in an array.
 *
 * Parameters:
 * - arr: The array containing elements to be swapped.
 * - index1: The index of the first element to be swapped.
 * - index2: The index of the second element to be swapped.
 */

void swapNumbers(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

/**
 * Function: pivotPartition
 * ------------------------
 * Partitions the array around two pivot elements for dual-pivot QuickSort.
 *
 * Parameters:
 * - arr: The array to be partitioned.
 * - low: The starting index of the partition.
 * - high: The ending index of the partition.
 * - pivot: A structure to store the left and right pivot indices.
 */
void pivotPartition(int* arr, int low, int high, struct record* pivot) {
    if (arr[low] > arr[high]) {
        swapNumbers(arr, low, high);
    }
    int leftPivot = low + 1;
    int rightPivot = high - 1;

    int iterator = low + 1;
    while (iterator <= rightPivot) {
        if (arr[iterator] < arr[low])
            swapNumbers(arr, iterator++, leftPivot++);
        else if (arr[iterator] > arr[high])
            swapNumbers(arr, iterator, rightPivot--);
        else
            iterator++;
    }

    swapNumbers(arr, low, --leftPivot);
    swapNumbers(arr, high, ++rightPivot);

    pivot->left = leftPivot;
    pivot->right = rightPivot;
}



/**
 * Function: dualPivotQuickSort
 * ----------------------------
 * This algorithm offers O(nlog(n)) performance on many data sets that cause other quicksorts to degrade
 * to quadratic performance, and is typically faster than traditional (one-pivot) Quicksort implementations.
 *
 * Parameters:
 * - arr: The array to be sorted.
 * - low: The starting index of the array or subarray.
 * - high: The ending index of the array or subarray.
 */
void dualPivotQuickSort(int* arr, int low, int high) {
    struct record Pivot;
    Pivot.left = -1;
    Pivot.right = -1;
    if (low >= high)
        return;
    pivotPartition(arr, low, high, &Pivot);
    dualPivotQuickSort(arr, low, Pivot.left - 1);
    dualPivotQuickSort(arr, Pivot.left + 1, Pivot.right - 1);
    dualPivotQuickSort(arr, Pivot.right + 1, high);
}


/**
 * Function: compareTwoArray
 * Description: This function compares two integer arrays for equality.
 * Parameters:
 * - arr1: Pointer to the first integer array.
 * - size1: Size of the first array.
 * - arr2: Pointer to the second integer array.
 * - size2: Size of the second array.
 * Returns:
 * - bool: Returns true if the arrays are equal in size and content; otherwise, returns false.
 */
inline bool compareTwoArray(int* arr1, int size1, int* arr2, int size2){
    int iterator = 0;
    if (size1!=size2)
        return false;
    while (iterator<size1 && iterator<size2 && arr1[iterator]==arr2[iterator]){
        iterator++;
    }
    return iterator==size1;    
}


/**
 * @brief Calculates the sum of all elements in an integer array.
 *
 * This inline function iterates through the elements of the given array
 * and calculates the sum. The function is designed to be used with small,
 * frequently called operations for potential performance optimization.
 *
 * @param arr Pointer to the integer array.
 * @param n   Number of elements in the array.
 * @return    The sum of all elements in the array.
 */
inline int sumAllElements(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + arr[i];
        }
    return 0;
}


/**
 * @brief Checks if an integer array is sorted in ascending order.
 *
 * This inline function iterates through the elements of the given array,
 * comparing each element with its predecessor. If any element is smaller
 * than its preceding element, the function returns false, indicating that
 * the array is not sorted. Otherwise, it returns true, signifying that the
 * array is sorted in ascending order.
 *
 * @param arr Pointer to the integer array.
 * @param n   Number of elements in the array.
 * @return    True if the array is sorted in ascending order, false otherwise.
 */
inline bool checkForSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i]<arr[i-1])
        return false;
    }
    
    return true;
}


/**
 * @brief Concatenates two arrays into a new array.
 *
 * @param arr1 The first array.
 * @param size1 The size of the first array.
 * @param arr2 The second array.
 * @param size2 The size of the second array.
 * @return A new array containing elements from both input arrays.
 * 
 * NOTE: The array returned must be freed explicitly by the user.
 */
inline int *concatenateTwoArrays(int *arr1, int size1, int *arr2, int size2)
{
    int* new_array = (int*)malloc((size1+size2)*sizeof(int));
    int i = 0;
    for (; i < size1 && i<size2; i++)
    {
        new_array[i] = arr1[i];
        new_array[size1+i] = arr2[i];
    }
    while (i<size1)
    {
        new_array[i] = arr1[i];
        i++;
    }
    while (i<size2)
    {
        new_array[size1+i] = arr2[i];
        i++;
    }
    
    return new_array;
}


/**
 * @brief Return the index of first occurrence of the element in the array.
 * @param arr Array.
 * @param n Size of the array.
 * @param element Element to be searched
 * @return index of the found element 
*/
inline int firstIndexOf(int *arr, int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==element)
            return i;
    }
    
    return -1;
}


/**
 * @brief Calculates the hash code of an integer array.
 *
 * This function takes an integer array and calculates its hash code using a specific formula.
 *
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 *
 * @return Unsigned long long representing the hash code.
 */
inline unsigned long long getHashCodeOf(int *arr, int n)
{
    if (arr==NULL)
        return 0;
    unsigned long long hash = 1;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        val = val ^ (val>>31);
        hash = hash * 19 + val ;
    }
    
    return hash;
}


