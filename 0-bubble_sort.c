#include "sort.h"

/**
 * _swap - swap between 2 pointers of type int
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
 * bubble_sort - Bubble sort algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
unsigned int x = 0, j = 0;

if (size <= 1)
return;

for (x = 0; x < (size - 1); x++)
for (j = 1; j < size; j++)
if (array[j - 1] > array[j])
{
_swap(&array[j - 1], &array[j]);
print_array(array, size);
}
}
