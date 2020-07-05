#include <stdlib.h>
#include <string.h>

/*
 * mergesort.c
 * Implementation of the mergesort sorting algorithm.
 *
 */

/*
 * Local functions
 */
void static msort_util(int *arr, size_t low, size_t high);
void static merge_util(int *arr, size_t low, size_t mid, size_t high);


/* ----------------------------------------------------------------------------
 * Function: msort_user
 *
 * Sort the array 'arr' using the merge sort alogrithm.
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - size      (size_t)        : size of the array
 *  - reverse   (unsingned int) : should the array be reversed
 * 
 * returns: void
 * ----------------------------------------------------------------------------
 */
void msort_user(int *arr, size_t n, unsigned int reverse)
{
    /* Handle bad reverse value */
    if (reverse != 0 && reverse != 1) {
        return;
    }

    /* The function that perfoms merge sort */
    msort_util(arr, 0, n);

    if (reverse) {
        size_t i, j;
        int temp;


        for (i = 0, j = n - 1; i < j; i++, j--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    /* WE DONE! */
    return;
}


/* ----------------------------------------------------------------------------
 * Function: msort_util
 *
 * Implements the logic for merge algorithm 
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - low       (size_t)        : lowest index to sort
 *  - high      (size_t)        : highest index + 1 to sort to 
 * 
 * returns: void
 * ----------------------------------------------------------------------------
 */
 void static msort_util(int *arr, size_t low, size_t high) 
{
    /*
     * Check if atleast 2 elements are present
     */
    if (low < high - 1)
    {
        size_t m = (low + high) / 2; // Can overflow 
        
        msort_util(arr, low, m); // merge sort left sub array
        msort_util(arr, m + 1, high); // merge sort right sub array

        // now merge the two sorted subarrays
        merge_util(arr, low, m, high);
    }

    return;
}


/* ----------------------------------------------------------------------------
 * Function: merge_util
 *
 * Merge 2 sorted arrays
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - low       (size_t)        : lowest index of first sorted sub array
 *  - mid       (size_t)        : highest index of the first sorted sub array
 *  - high      (size_t)        : highest index of the last sorted sub array
 * 
 * returns: void
 * ----------------------------------------------------------------------------
 */
 void static merge_util(int *arr, size_t low, size_t mid, size_t high)
 {
    size_t i = low;
    size_t j = mid + 1;
    size_t k = low;

    // Create copy of the left and right sub array
    int *left_subarray, *right_subarray;
    
    memcpy(left_subarray, arr + i, mid - low);
    memcpy(right_subarray, arr + mid + 1, high - (mid + 1));

    if (!left_subarray || !right_subarray)
    {
        // Not enough memory
        return;
    }

    // Overwrite the merged values for the subarrays
    while (i < mid + 1 && j < high)
    {
        if (left_subarray[i] > right_subarray[j]) {
            arr[k] = right_subarray[j];
            j += 1;
        } else {
            arr[k] = left_subarray[i];
            i += 1;
        }
        
        k += 1;
    }

    while (i < mid + 1)
    {
        arr[k++] = left_subarray[i++];
    }

    while (j < high)
    {
        arr[k++] = right_subarray[j++];
    }
 }