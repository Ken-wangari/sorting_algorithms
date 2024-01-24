#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - This function prints an array of integers
 *
 * @array: array to be printed
 * @size: No. of elements in the array
 */
void pr_array(const int *array, size_t size)
{
        size_t i;

        i = 0;
        while (array && i < size)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", array[i]);
                ++i;
        }
        printf("\n");
}
