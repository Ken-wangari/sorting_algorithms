#include "sort.h"

/**
 * swp_integers - Swap two integers in an array.
 * @a: 1st integer for swapping.
 * @b: 2nd integer for swapping.
 */
void swp_integers(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * sel_srt - uses the selection sort algorithm to sort in ascending order.
 * @arry: the array of integers.
 * @size: size  array.
 *
 * Description: after swapping, the array is printed - 0x1B. C - Sorting algorithms & Big O.
 */
void sel_srt(int *array, size_t size)
{
    int *min_;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_ = array + i;
        for (j = i + 1; j < size; j++)
	min_ = (array[j] < *min_) ? (array + j) : min_;

        if ((array + i) != min_)
        {
            swp_integers(array + i, min_);
            pr_array(array, size);
        }
    }
}
