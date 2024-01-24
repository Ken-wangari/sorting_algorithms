#include "sort.h"

/**
 * swp_integers - This function Swaps 2 integers that are in an array.
 * @a: 1st integer.
 * @b: 2nd integer.
 *
 */
void swp_integers(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * b_sort - integers ares sorted in an ascending order.
 * @array: integers to sort.
 * @size: size of array.
 *
 * Description: array is printed after swapping.
 */
void b_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool b_ = false;

    if (array == NULL || size < 2)
        return;

    while (b_ == false)
    {
        b_ = true;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swp_integers(array + i, array + i + 1);
                pr_array(array, size);
                b_ = false;
            }
        }
        len--;
    }
}
