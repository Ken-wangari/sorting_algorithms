#include "sort.h"

void swp_integers(int *a, int *b);
void maximum_heapify(int *array, size_t size, size_t base, size_t root);
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
 * maximum_heapify - turns to binary heap.
 * @array: represents a binary tree.
 * @size: The size.
 * @base: The index.
 * @root: Root node.
 */
void maximum_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, large;

    left = 2 * root + 1;
    right = 2 * root + 2;
    large = root;

    if (left < base && array[left] > array[large])
        large = left;
    if (right < base && array[right] > array[large])
        large = right;

    if (large != root)
    {
        swp_integers(array + root, array + large);
        pr_array(array, size);
        maximum_heapify(array, size, base, large);
    }
}

/**
 * heap_sort - Sorts in ascending order
 *             
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: uses heap sort algorithm to swap in ascending order.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        maximum_heapify(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swp_integers(array, array + i);
        pr_array(array, size);
        maximum_heapify(array, size, i, 0);
    }
}

