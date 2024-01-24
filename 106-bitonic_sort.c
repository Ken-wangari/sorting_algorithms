#include "sort.h"

void swp_integers(int *a, int *b);
void bi_merge(int *array, size_t size, size_t start, size_t seq,
        char flow);
void bi_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bi_sort(int *array, size_t size);

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
 * @seq: size of sequence.
 * @flow: the flow of direction.
 */
void bi_merge(int *array, size_t size, size_t start, size_t seq,
        char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == UP && array[i] > array[i + jump]) ||
                (flow == DOWN && array[i] < array[i + jump]))
                swp_integers(array + i, array + i + jump);
        }
        bi_merge(array, size, start, jump, flow);
        bi_merge(array, size, start + jump, jump, flow);
    }
}

/**
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index.
 * @seq: The size of a block.
 * @flow: The direction.
 */
void bi_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    char *str = (flow == UP) ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        pr_array(array + start, seq);

        bi_seq(array, size, start, cut, UP);
        bi_seq(array, size, start + cut, cut, DOWN);
        bi_merge(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        pr_array(array + start, seq);
    }
}

/**
 * bi_sort - Sort in ascending
 *                 
 * @array: An array of integers.
 * @size: The size of array.
 *
 * Description: uses the bitonic sort algorithm.
 */
void bi_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bi_seq(array, size, 0, size, UP);
}

