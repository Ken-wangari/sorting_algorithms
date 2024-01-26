#include "sort.h"

void swp_integers(int *a, int *b);
int hoare_parti_tion(int *array, size_t size, int left, int right);
void hoare_srt(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swp_integers - Swap two integers.
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
 * hoare_parti_tion - This function order a subset of an array which consists of integers
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_parti_tion(int *array, size_t size, int left, int right)
{
        int piv, above, below;

        piv = array[right]; 
        for (above = left - 1, below = right + 1; above < below;)
        {
                do {
                        above++;
                } while (array[above] < piv);
                do {
                        below--;
                } while (array[below] > piv);

                if (above < below)
                {
                        swp_integers(array + above, array + below);
                        print_array(array, size);
                }
        }

        return (above);
}

/**
 * hoare_srt - This function Implement the quicksort algorithm using recursion process
 *
 * Description: Uses the Hoare partition scheme - 0x1B. sorting algorithms & Big O.
 */
void hoare_srt(int *array, size_t size, int left, int right)
{
        int part;

        if (right - left > 0)
        {
                part = hoare_parti_tion(array, size, left, right);
                hoare_srt(array, size, left, part - 1);
                hoare_srt(array, size, part, right);
        }
}

/**
 * quick_sort_hoare - uses quicksort algorithm to sort in ascending order.
 */
void quick_sort_hoare(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        hoare_srt(array, size, 0, size - 1);
}
