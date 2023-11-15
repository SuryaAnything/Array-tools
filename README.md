
# Array Utilities Header File
## Overview

The `arrays_utils.h` header file provides a collection of array operations implemented through function pointers. These operations include sorting, searching, concatenating arrays, finding min/max values, and more. The functions in this header file offer flexibility in manipulating and analyzing ***integer arrays***.

## Usage

To use the array operations provided by this header file:
1. **Include the Header:**
   ```c
   #include \"arrays_utils.h\"
   ```

2. **Initialize Functions:**
   Call `useArrayFunctions()` to initialize the function pointers.
   ```c
   status_code status = useArrayFunctions();
   if (status == SUCCESS) {
       // Functions are now accessible through the Arrays structure.
   }
   ```
   
3. **Access Functions:**
   Functions can be accessed via the `Arrays` structure. For example:
   ```c
   int array[] = {4, 7, 2, 9, 1};
   int* sortedArray = Arrays.sort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
   // Use the returned sortedArray...
   free(sortedArray); // Don't forget to free allocated memory!
   ```

4. **Memory Management:**
   For functions that return dynamically allocated memory (such as arrays or strings), ensure to free the memory explicitly using `free()` when done using the returned values.

## Function Descriptions

The Functions available to use when the header file is imported:

- `copyOfRange`: Create a copy of a specified range of an array.
- `rotate`: Rotate an array to the right by a specified number of positions.
- `searchLIN`: Search for the first occurrence of a value using linear search.
- `search`: Search for all occurrences of a value in the array.
- `searchBIN`: Search for the first occurrence in a sorted array using binary search.
- `reverse`: Reverse the elements of an array in-place.
- `minValue`: Search for the minimum value in the array.
- `maxValue`: Search for the maximum value in the array.
- `sort`: Sort the array in ascending order.
- `compare`: Compare two arrays element wise.
- `isSorted`: Check whether the array is sorted in ascending order or not.
- `concat`: Concatenate two array into one array.
- `indexOf`: Search for an element in the array and returns the index of first occurrence of the element.
- `hashCode`: Returns a unique int value for a particular array.
- `toString`: Convert the array into a String format.
- `getMaxOccurrence`: Find the value that occurs maximum times in the array and return its count.
- `sum`: Find the Sum of all element in the array.

All the function listed above must be used in the format: `Arrays._function_name_`
Refer to the header file comments for detailed descriptions of each function and its parameters.

## Note

- Ensure proper memory allocation and deallocation when using functions returning dynamically allocated memory.
- Some functions may assume certain conditions (e.g., sorted input for binary search).
- Read function descriptions and usage instructions in the header file before using them.


## Contributor

This header file was created and maintained by [Surya].