#include "sort.h"

/**
 * swap_nodes - swap between 2 nodes
 * @slow: pointer to the first node to swap
 * @fast: pointer to the second node to swap
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
 * cocktail_sort_list - improve of bubble sort algorithm
 * go through the array since head to tail
 * @list: double linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *slow, *fast;
int left = -1, right = -1, counter = 0;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
return;

slow = *list;
fast = (*list)->next;
while (left <= right)
{
left++;
while (slow && fast && counter != right)
{
if (slow->n > fast->n)
swap_nodes(&slow, &fast, list), print_list(*list);
slow = slow->next;
fast = fast->next;
counter++;
}
if (left == 0)
right = counter;
right--;

slow = slow->prev;
fast = slow->prev;
while (slow && fast && counter >= left)
{
if (slow->n < fast->n)
swap_nodes(&fast, &slow, list), print_list(*list);
slow = slow->prev;
fast = fast->prev;
counter--;
}

slow = slow->next;
fast = slow->next;
}
}
