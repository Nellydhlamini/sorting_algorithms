#include "sort.h"

/**
 * _swap - swap between 2 pointers of int
 * @a: first int pointer
 * @b: second int pointer
 * Return: void
 */
void _swap(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * hoare_partition - Hoare partition the array
 * the pivot is part of while
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
int hoare_partition(int *array, int left, int right, size_t size)
{
int a, j, pivot;

pivot = array[right]; /* pivot start at left */
a = left; /* in the for i = left + 1 */
for (a = left, j = right; "C is fun"; a++, j--)
{
while (array[a] < pivot)
a++;
while (array[j] > pivot)
j--;

if (j <= a)
return (a);

_swap(&array[a], &array[j]);
print_array(array, size);
}
}

/**
 * recursive_quick_sort - recursive to the array to have quick sort
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
void recursive_quick_sort(int *array, int left, int right, size_t size)
{
int x;

if (left >= right)
return;
x = hoare_partition(array, left, right, size);
recursive_quick_sort(array, left, x - 1, size);
recursive_quick_sort(array, x, right, size);
}

/**
 * quick_sort_hoare - choose a pivot and be part of while
 * for this case pivot = last element
 * best case - pivot is the middle value of array (O(nlog(n))
 * worst case - sorted -> necesary we will need to run O(n^2)
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
if (size <= 1)
return;
recursive_quick_sort(array, 0, size - 1, size);
}
