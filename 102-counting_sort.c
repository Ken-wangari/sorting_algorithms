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
 * counting_sort - Sorts in ascending order and uses count sort algorithm.
 *                 
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: Prints setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *count_, *sort_ed, maximum, i;

    if (array == NULL || size < 2)
        return;

    sort_ed = malloc(sizeof(int) * size);
    if (sort_ed == NULL)
        return;
    maximum = get_maximum(array, size);
    count_ = malloc(sizeof(int) * (maximum + 1));
    if (count_ == NULL)
    {
        free(sort_ed);
        return;
    }

    for (i = 0; i < (maximum + 1); i++)
        count_[i] = 0;
    for (i = 0; i < (int)size; i++)
        count_[array[i]] += 1;
    for (i = 0; i < (maximum + 1); i++)
        count_[i] += count_[i - 1];
    print_array(count_, maximum + 1);

    for (i = 0; i < (int)size; i++)
    {
        sort_ed[count_[array[i]] - 1] = array[i];
        count_[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sort_ed[i];

    free(sort_ed);
    free(count_);
}

