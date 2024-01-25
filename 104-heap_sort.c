#include "sort.h"

void swp_integers(int *a, int *b);
void maximum_heap_ify(int *array, size_t size, size_t base_, size_t ro_ot);
void heap_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void swp_integers(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * maximum_heap_ify - turns to binary heap.
 * @array: represents a binary tree.
 * @size: The size.
 * @base: The index.
 * @root: Root node.
 */
void maximum_heap_ify(int *array, size_t size, size_t base_, size_t ro_ot)
{
    size_t left, right, large;

    left = 2 * ro_ot + 1;
    right = 2 * ro_ot + 2;
    large = ro_ot;

    if (left < base_ && array[left] > array[large])
        large = left;
    if (right < base_ && array[right] > array[large])
        large = right;

    if (large != ro_ot)
    {
        swp_integers(array + ro_ot, array + large);
        print_array(array, size);
        maximum_heap_ify(array, size, base_, large);
    }
}

/**
 * heap_sort - Sorts in ascending order
 *             
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: uses heap sort algorithm to swap in ascending order. - Big O and sorting algorithms.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        maximum_heap_ify(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swp_integers(array, array + i);
        print_array(array, size);
        maximum_heap_ify(array, size, i, 0);
    }
}

