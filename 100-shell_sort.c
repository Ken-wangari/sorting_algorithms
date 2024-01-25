#include "sort.h"

/**
 * swp_integers - this function Swaps 2 integers in an array.
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
 * shell_sort - uses shell sort algorithm to sort in an ascending order.
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: shell_sort.c - interval sequence.
 */
void shell_sort(int *array, size_t size)
{
    size_t g_ap, i, j;

    if (array == NULL || size < 2)
        return;

    for (g_ap = 1; g_ap < (size / 3);)
        g_ap = g_ap * 3 + 1;

    for (; g_ap >= 1; g_ap /= 3)
    {
        for (i = g_ap; i < size; i++)
        {
            j = i;
            while (j >= g_ap && array[j - g_ap] > array[j])
            {
                swp_integers(array + j, array + (j - g_ap));
                j -= g_ap;
            }
        }
        print_array(array, size);
    }
}
