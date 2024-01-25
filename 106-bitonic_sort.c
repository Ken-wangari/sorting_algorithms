#include "sort.h"

void swp_integers(int *a, int *b);
void bi_merge(int *array, size_t size, size_t start_, size_t sequence,
        char flow_d);
void bi_seq(int *array, size_t size, size_t start_, size_t sequence, char flow_d);
void bitonic_sort(int *array, size_t size);

/**
 * swp_integerss - Swap two integers.
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
 * bi_merge - sorts sequences which are bitonic.
 * @array: array.
 * @size: The size array.
 * @start: Starting index.
 * @sequence: size of sequence.
 * @flow_d: the flow of direction.
 */
void bi_merge(int *array, size_t size, size_t start_, size_t sequence,
        char flow_d)
{
    size_t i, jump = sequence / 2;

    if (sequence > 1)
    {
        for (i = start_; i < start_ + jump; i++)
        {
            if ((flow_d == UP && array[i] > array[i + jump]) ||
                (flow_d == DOWN && array[i] < array[i + jump]))
                swp_integers(array + i, array + i + jump);
        }
        bi_merge(array, size, start_, jump, flow_d);
        bi_merge(array, size, start_ + jump, jump, flow_d);
    }
}

/**
 * @array: An array of integers.
 * @size: The size of the array.
 * @start_: The starting index.
 * @sequence: The size of a block.
 * @flow_d: The direction.
 */
void bi_sequence(int *array, size_t size, size_t start_, size_t sequence, char flow_d)
{
    size_t cut = sequence / 2;
    char *str = (flow_d == UP) ? "UP" : "DOWN";

    if (sequence > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_, sequence);

        bi_sequence(array, size, start_, cut, UP);
        bi_sequence(array, size, start_ + cut, cut, DOWN);
        bi_merge(array, size, start_, sequence, flow_d);

        printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
        print_array(array + start_, sequence);
    }
}

/**
 * bitonic_sort - Sort in ascending
 *                 
 * @array: An array of integers.
 * @size: The size of array.
 *
 * Description: uses the bitonic sort algorithm.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bi_sequence(array, size, 0, size, UP);
}

