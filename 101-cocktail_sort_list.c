#include "sort.h"

void nodes_swp_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void nodes_swp_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cock_sortList(listint_t **list);

/**
 * nodes_swp_ahead - swaps node.
 * @list: pointer to the head
 * @tail: pointer to the tail 
 * @shaker: current node to be swapped. - 0x1B. C - Sorting algorithms & Big O
 */
void nodes_swp_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->next;

    if ((*shaker)->previous != NULL)
        (*shaker)->previous->nxt = tmp;
    else
        *list = tmp;
    tmp->previous = (*shaker)->previous;
    (*shaker)->nxt = tmp->nxt;
    if (tmp->nxt != NULL)
        tmp->nxt->previous = *shaker;
    else
        *tail = *shaker;
    (*shaker)->previous = tmp;
    tmp->nxt = *shaker;
    *shaker = tmp;
}

/**
 * nodes_swp_behind - swaps the node behind.
 * @list: A pointer to the head.
 * @tail: A pointer to the tail.
 * @shaker: current swap node in the algorithm used, shaking. - 0x1B. C - Sorting algorithms & Big O.
 */
void nodes_swp_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->previous;

    if ((*shaker)->nxt != NULL)
        (*shaker)->nxt->previous = tmp;
    else
        *tail = tmp;
    tmp->nxt = (*shaker)->nxt;
    (*shaker)->previous = tmp->previous;
    if (tmp->previous != NULL)
        tmp->previous->nxt = *shaker;
    else
        *list = *shaker;
    (*shaker)->nxt = tmp;
    tmp->previous = *shaker;
    *shaker = tmp;
}

/**
 * cock_sortList - sorts in an ascending order using the shaker algorithm.
 * @list: pointer to the head.
 */
void cock_sortList(listint_t **list)
{
    listint_t *tail, *shaker;
    bool shake_not_stir = false;

    if (list == NULL || *list == NULL || (*list)->nxt == NULL)
        return;

    for (tail = *list; tail->nxt != NULL;)
        tail = tail->nxt;

    while (shake_not_stir == false)
    {
        shake_not_stir = true;
        for (shaker = *list; shaker != tail; shaker = shaker->nxt)
        {
            if (shaker->n > shaker->nxt->n)
            {
                nodes_swp_ahead(list, &tail, &shaker);
                print_list((const listint_t *)*list);
                shake_not_stir = false;
            }
        }
        for (shaker = shaker->previous; shaker != *list;
                shaker = shaker->previous)
        {
            if (shaker->n < shaker->previous->n)
            {
                nodes_swp_behind(list, &tail, &shaker);
                print_list((const listint_t *)*list);
                shake_not_stir = false;
            }
        }
    }
}
