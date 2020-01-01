"""
    quicksort.py

    Python implementation of the quicksort sorting algorithm
"""



def qsort(arr: list, reverse: bool):
    """
        The quicksort function
    """
    qsort_util(arr, 0, len(arr))
    if reverse:
        arr[:] = arr[::-1]


def qsort_util(arr: list, low: int, high: int):
    """
        Utility function
    """
    if low < high - 1:
        pivot_index = qsort_partition(arr, low, high)
        qsort_util(arr, low, pivot_index)
        qsort_util(arr, pivot_index + 1, high)


def qsort_partition(arr: list, low: int, high: int):
    """
        Quicksort partition logic.
        The first element is chosen as the pivot
    """
    i = low
    j = high
    pivot = arr[low]


    while i < j:

        i += 1
        while i < high and pivot > arr[i]:
            i += 1

        j -= 1
        while j > low and pivot < arr[j]:
            j -= 1

        if (i < j and arr[i] > arr[j]):
            arr[i], arr[j] = arr[j], arr[i]

    arr[j], arr[low] = pivot, arr[j]
    
    return j


if __name__ == "__main__":
    arr = [1, -4, 5, 3, 2, 0, 9, 2]
    
    print("Before sorting:", arr)
    qsort(arr, False)
    print("After sorting:", arr)