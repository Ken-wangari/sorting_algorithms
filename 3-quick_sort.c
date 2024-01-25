#include "sort.h"

void swp_integers(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swp_integers - the function Swaps two integers in an array.
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
 * lomuto_part - the last element is the pivot.
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index.
 * @right: ending index 
 *
 * Return: partition index finality - 0x1B. C - Sorting algorithms & Big O 
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
    int *piv, above, below;

    piv = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *piv)
        {
            if (above < below)
            {
                swp_integers(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *piv)
    {
        swp_integers(array + above, piv);
        print_array(array, size);
    }

    return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: size of array.
 * @left: The starting index. 
 * @right: The ending index.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_part(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - uses quicksort algorithm to sort.
 * @array: array of the integers.
 * @size: size of array.
 *
 * Description: prints array after each swap - 0x1B. C - Sorting algorithms & Big O 
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
