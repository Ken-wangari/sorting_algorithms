#include "sort.h"

int get_maximum(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - This function gest the maximum value.
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
 * radix_counting_sort - sorts in ascending order
 * @array: array of integers.
 * @size: size of array.
 * @sig: significant digit.
 * @buff: storage.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10] += 1;

    for (i = 0; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        buff[count[(array[i] / sig) % 10] - 1] = array[i];
        count[(array[i] / sig) % 10] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = buff[i];
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
    int maximum, sig, *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    maximum = get_maximum(array, size);
    for (sig = 1; maximum / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buff);
        pr_array(array, size);
    }

    free(buff);
}

