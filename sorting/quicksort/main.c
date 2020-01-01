#include <stdio.h>
#include "quicksort.h"

int main(void)
{
    int arr[8] = {1, -4, 5, 3, 2, 0, 9, 2};
    size_t n = 8;
    size_t i;
    
    
    printf("Before sorting\n");
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    qsort_user(arr, n, 0);
    printf("After sorting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

