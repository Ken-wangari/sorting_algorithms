#include "sort.h"

/**
 * get_maximum - This function gets the maximum value in the array of integers.
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: Maximum integer.
 */
int get_maximum(int *array, int size)
{
    int maximum, i;

    for (maximum = array[0], i = 1; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }

    return (maximum);
}

/**
 * count_sort - Sorts in ascending order and uses count sort algorithm.
 *                 
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Prints setting it up.
 */
void count_sort(int *array, size_t size)
{
    int *count, *sorted, maximum, i;

    if (array == NULL || size < 2)
        return;

    sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
        return;
    maximum = get_maximum(array, size);
    count = malloc(sizeof(int) * (maximum + 1));
    if (count == NULL)
    {
        free(sorted);
        return;
    }

    for (i = 0; i < (maximum + 1); i++)
        count[i] = 0;
    for (i = 0; i < (int)size; i++)
        count[array[i]] += 1;
    for (i = 0; i < (maximum + 1); i++)
        count[i] += count[i - 1];
    pr_array(count, maximum + 1);

    for (i = 0; i < (int)size; i++)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}

