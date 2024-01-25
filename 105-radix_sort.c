#include "sort.h"

int get_maximum(int *array, int size);
void radix_count_sort_(int *array, size_t size, int significance, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_maximum - This function gest the maximum value.
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: maximum integer.
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
 * radix_count_sort_ - sorts in ascending order
 * @array: array of integers.
 * @size: size of array.
 * @significance: significant digit.
 * @buffer: storage.
 */
void radix_count_sort_(int *array, size_t size, int significance, int *buffer)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / significance) % 10] += 1;

    for (i = 0; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        buffer[count[(array[i] / significance) % 10] - 1] = array[i];
        count[(array[i] / significance) % 10] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = buffer[i];
}

/**
 * radix_sort - sorts in ascending order.
 * @array: array integers.
 * @size: size ofarray.
 *
 * Description: uses radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
    int maximum, significance, *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    maximum = get_maximum(array, size);
    for (significance = 1; maximum / significance > 0; significance *= 10)
    {
        radix_count_sort_(array, size, significance, buffer);
        print_array(array, size);
    }

    free(buffer);
}

