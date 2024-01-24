#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#define UP 0
#define DOWN 1

/**
 * enum bool - Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
    false = 0,
    true
} bool;

/**
 * struct listint_s - This represents doubly linked list node
 *
 * @n: the Integer that is stored in the node
 * @previous: the Pointer to the previous element
 * @nxt: the Pointer to the next element
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *previous;
    struct listint_s *nxt;
} listint_t;

/* Pr functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* The Sorting algoritms */
void merge_sort(int *arry, size_t size);
void cock_sortList(listint_t **list);
void bubble_sort(int *array, size_t size);
void q_sort(int *arry, size_t size);
void s_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void sel_srt(int *arry, size_t size);
void count_sort(int *arry, size_t size);
void bi_sort(int *arry, size_t size);
void quick_sort_hoare(int *arry, size_t size);
void heap_sort(int *arry, size_t size);
void radix_sort(int *arry, size_t size);

#endif /* SORT_H */
