#include "sort.h"

void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
        size_t back);
void merge_sort_rec(int *subarray, int *buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - sorting of a sub-array of given integers.
 * @subarr: subarray of integers.
 * @buffer: stores the result of sorted sub array.
 * @front: The front index.
 * @mid: The middle index.
 * @back: The back index.
 */
void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
        size_t back)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarray + front, mid - front);

    printf("[right]: ");
    print_array(subarray + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
    for (; i < mid; i++)
        buffer[k++] = subarray[i];
    for (; j < back; j++)
        buffer[k++] = subarray[j];
    for (i = front, k = 0; i < back; i++)
        subarray[i] = buffer[k++];

    printf("[Done]: ");
    print_array(subarray + front, back - front);
}

/**
 * merge_sort_rec - uses merge sort algorithm.
 * @subarray: A subarray of integers.
 * @buffer: stores the result of sorted sub array
 * @front: The front index.
 * @back: The back index.
 */
void merge_sort_rec(int *subarray, int *buffer, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_rec(subarray, buffer, front, mid);
        merge_sort_rec(subarray, buffer, mid, back);
        merge_subarray(subarray, buffer, front, mid, back);
    }
}

/**
 * merge_sort - uses merge sort algorithm to sort in ascending order.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: uses merge sort algorithm. - 0x1B. C - Sorting algorithms & Big O
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    merge_sort_rec(array, buffer, 0, size);

    free(buffer);
}

