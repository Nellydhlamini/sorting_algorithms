#include "sort.h"

/**
 * _swap - swap between two int pointers
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
 * partition - partition the array
 * @array: array
 * @left: first int pointer
 * @right: second int pointer
 * @size: size of the array
 * Return: void
 */
int partition(int *array, int left, int right, size_t size)
{
int x, a, pivot;

pivot = array[right];
x = left - 1;
for (a = left; a <= right - 1; a++)
{
if (array[a] < pivot)
{
x = x + 1;
if (array[x] != array[a])
{
_swap(&array[x], &array[a]);
print_array(array, size);
}
}
}
if (array[x + 1] != array[right])
{
_swap(&array[x + 1], &array[right]);
print_array(array, size);
}
return (x + 1);
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
int a;

if (left >= right)
return;
a = partition(array, left, right, size);
recursive_quick_sort(array, left, a - 1, size);
recursive_quick_sort(array, a + 1, right, size);
}

/**
 * quick_sort - choose the min number and swap between the first
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (size <= 1)
return;
recursive_quick_sort(array, 0, size - 1, size);
}
