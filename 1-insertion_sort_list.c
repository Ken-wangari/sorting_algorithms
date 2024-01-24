#include "sort.h"

/**
 * nodes_swp - This function Swaps two nodes in a listint_t doubly-linked list.
 * @h: Head pointer..
 * @n1: pointer to the 1st node to swap.
 * @n2: 2nd node to swap.
 */
void nodes_swp(listint_t **h, listint_t **n1, listint_t *n2)
{
    (*n1)->next = n2->next;
    if (n2->next != NULL)
        n2->next->prev = *n1;
    n2->prev = (*n1)->prev;
    n2->next = *n1;
    if ((*n1)->prev != NULL)
        (*n1)->prev->next = n2;
    else
        *h = n2;
    (*n1)->prev = n2;
    *n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts using insertion sort algorithm.
 * @list: head pointed of the doubly_linked integers..
 *
 * Description: after wapping, list is printed - 0x1B. C - Sorting algorithms & Big O.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iter_, *insert, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
     
    for (iter_ = (*list)->next; iter_ != NULL; iter_ = tmp)
    {
        tmp = iter_->next;
        insert = iter_->prev;
        while (insert != NULL && iter_->n < insert->n)
        {
            nodes_swp(list, &insert, iter_);
            print_list((const listint_t *)*list);
        }
    }
}
