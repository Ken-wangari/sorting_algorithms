#include "sort.h"

void nodes_swp_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void nodes_swp_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * nodes_swp_ahead - swaps node.
 * @list: pointer to the head
 * @tail: pointer to the tail 
 * @sha_ker: current node to be swapped. - 0x1B. C - Sorting algorithms & Big O
 */
void nodes_swp_ahead(listint_t **list, listint_t **tail, listint_t **sha_ker)
{
    listint_t *tmp = (*sha_ker)->next;

    if ((*sha_ker)->prev != NULL)
        (*sha_ker)->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = (*sha_ker)->prev;
    (*sha_ker)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *sha_ker;
    else
        *tail = *sha_ker;
    (*sha_ker)->prev = tmp;
    tmp->next = *sha_ker;
    *sha_ker = tmp;
}

/**
 * nodes_swp_behind - swaps the node behind.
 * @list: A pointer to the head.
 * @tail: A pointer to the tail.
 * @shaker: current swap node in the algorithm used, shaking. - 0x1B. C - Sorting algorithms & Big O.
 */
void nodes_swp_behind(listint_t **list, listint_t **tail, listint_t **sha_ker)
{
    listint_t *tmp = (*sha_ker)->prev;

    if ((*sha_ker)->next != NULL)
        (*sha_ker)->next->prev = tmp;
    else
        *tail = tmp;
    tmp->next = (*sha_ker)->next;
    (*sha_ker)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *sha_ker;
    else
        *list = *sha_ker;
    (*sha_ker)->next = tmp;
    tmp->prev = *sha_ker;
    *sha_ker = tmp;
}

/**
 * cocktail_sort_list - sorts in an ascending order using the shaker algorithm.
 * @list: pointer to the head.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *sha_ker;
    bool shake_not_stir = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    while (shake_not_stir == false)
    {
        shake_not_stir = true;
        for (sha_ker = *list; sha_ker != tail; sha_ker = sha_ker->next)
        {
            if (sha_ker->n > sha_ker->next->n)
            {
                nodes_swp_ahead(list, &tail, &sha_ker);
                print_list((const listint_t *)*list);
                shake_not_stir = false;
            }
        }
        for (sha_ker = sha_ker->prev; sha_ker != *list;
                sha_ker = sha_ker->prev)
        {
            if (sha_ker->n < sha_ker->prev->n)
            {
                nodes_swp_behind(list, &tail, &sha_ker);
                print_list((const listint_t *)*list);
                shake_not_stir = false;
            }
        }
    }
}
