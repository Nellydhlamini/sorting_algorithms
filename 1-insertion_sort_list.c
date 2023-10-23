#include "sort.h"

/**
 * swap_nodes - swap between two nodes
 * @slow: pointer to the first node to be swapped
 * @fast: pointer to the second node to be swapped
 * @list: double linked list
 * Return: void
 */
void swap_nodes(listint_t **slow, listint_t **fast, listint_t **list)
{
listint_t *a, *b;

if (!(*slow) || !(*fast))
return;

a = (*slow)->prev;
b = (*fast)->next;

if (a)
a->next = (*fast);
(*fast)->prev = a;

(*fast)->next = (*slow);
(*slow)->prev = (*fast);

(*slow)->next = b;
if (b)
b->prev = (*slow);

*slow = *fast;
*fast = (*slow)->next;

if (!a)
*list = *slow;
}

/**
 * insertion_sort_list - sort the list like insertion
 * @list: linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *head, *reverse, *temp;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
return;

head = *list;
head = head->next;
while (head)
{
reverse = head->prev;

if (reverse->n > head->n)
{

swap_nodes(&reverse, &head, list);
print_list(*list);

while (reverse->prev)
{
if ((reverse->n) < (reverse->prev->n))
{

temp = reverse->prev;
swap_nodes(&(temp), &reverse, list);
print_list(*list);
}
reverse = reverse->prev;
}
}
head = head->next;
}
}
