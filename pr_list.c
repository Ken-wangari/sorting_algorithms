#include <stdio.h>
#include "sort.h"

/**
 * print_list - lists of integers is printed
 *
 * @list: The list that will be printed
 */
void pr_list(const listint_t *list)
{
        int i;

        i = 0;
        while (list)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", list->n);
                ++i;
                list = list->nxt;
        }
        printf("\n");
}
