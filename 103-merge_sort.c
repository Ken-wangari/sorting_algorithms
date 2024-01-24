#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
        size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sorting of a sub-array of given integers.
 * @subarr: subarray of integers.
 * @buff: stores the result of sorted sub array.
 * @front: The front index.
 * @mid: The middle index.
 * @back: The back index.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
        size_t back)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    pr_array(subarr + front, mid - front);

    printf("[right]: ");
    pr_array(subarr + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    for (; i < mid; i++)
        buff[k++] = subarr[i];
    for (; j < back; j++)
        buff[k++] = subarr[j];
    for (i = front, k = 0; i < back; i++)
        subarr[i] = buff[k++];

    printf("[Done]: ");
    pr_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - uses merge sort algorithm.
 * @subarr: A subarray of integers.
 * @buff: stores the result of sorted sub array
 * @front: The front index.
 * @back: The back index.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(subarr, buff, front, mid);
        merge_sort_recursive(subarr, buff, mid, back);
        merge_subarr(subarr, buff, front, mid, back);
    }
}

/**
 * merge_sort - uses merge sort algorithm to sort in ascending order.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: uses merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}

