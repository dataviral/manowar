#include <stdlib.h>

/*
 * quicksort.c
 * Implementation of the quicksort sorting algorithm.
 *
 * Works using a pivot. worst case O(n^2), average case O(nlogn).
 * Generally works better than merge sort as sorting is done in place. Which
 * allows for better use of caching, furthermore merge sort has extra storage
 * requirements.
 * This implementation of quick sort is not stable.
 *
 * THE LOGIC:
 *  * divide and conquer
 *  * #1 choose a an element in the pivot and make sure all elements to left
 *    are less than it and all elements to its right are grater than it.
 *  * this ensures the pivot ends up in its sorted position. 
 */


/*
 * Local functions
 */
void static qsort_util(int *arr, size_t low, size_t high);
size_t static qsort_partition(int *arr, size_t l, size_t h);


/* ----------------------------------------------------------------------------
 * Function: qsort_user
 *
 * Sort the array 'arr' using the quicksort alogrithm.
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - size      (size_t)        : size of the array
 *  - reverse   (unsingned int) : should the array be reversed
 * 
 * returns: void
 * ----------------------------------------------------------------------------
 */
void qsort_user(int *arr, size_t n, unsigned int reverse)
{
    /* Handle bad reverse value */
    if (reverse != 0 && reverse != 1) {
        return;
    }

    /* A util function for cleaner interface */
    qsort_util(arr, 0, n);

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
 * Function: qsort_util
 *
 * Implements the logic for qicksort algorithm 
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - low       (size_t)        : lowest index to sort
 *  - high      (size_t)        : highest index + 1 to sort to 
 * 
 * returns: void
 * ----------------------------------------------------------------------------
 */
void static qsort_util(int *arr, size_t low, size_t high) 
{
    /*
     * Check if atleast 2 elements are present
     */
    if (low < high - 1)
    {   
        /* Get the pivot and sort apply the logic in #1*/
        size_t j = qsort_partition(arr, low, high);
        
        /* quicksort on the values to the left of pivot */
        qsort_util(arr, low, j);
        /* quicksort on the values to the right of the pivot */
        qsort_util(arr, j + 1, high);
    }

    return;
}


/* ----------------------------------------------------------------------------
 * Function: qsort_partition
 *
 * Implements the logic as described in #1. 
 * ----------------------------------------------------------------------------
 * params:
 *  - arr       (int *)         : the array to sort
 *  - low       (size_t)        : lowest index to sort
 *  - high      (size_t)        : highest index + 1 to sort to
 * 
 * returns: (size_t) index of the sorted location of the pivot
 * ----------------------------------------------------------------------------
 */
size_t static qsort_partition(int *arr, size_t l, size_t h)
{
    int pivot = arr[l];
    size_t i = l, j = h; 
    int t;


    while (i < j)
    {
        do
        {
            i++;
        } while (i < h && pivot > arr[i]);

        do
        {
            j--;
        } while (j > l && pivot < arr[j]);
        
        if (arr[i] > arr[j] && i < j)
        {
            int temp = arr[i];


            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[l] = arr[j];
    arr[j] = pivot;

    return j;
}