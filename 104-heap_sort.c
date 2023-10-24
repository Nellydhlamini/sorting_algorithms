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
 * heapify - build a heap tree where the head is bigger of value branches
 * @array: unsorted array of integer
 * @size: size of the array
 * @i: index of starter head
 * @print_size: size of the array to print
 * Return: void
 */
void heapify(int *array, size_t size, int i, size_t print_size)
{
int head = i; /* head to compare -> big number */
int left = 2 * i + 1; /* left branch */
int right = 2 * i + 2; /* right branch */

if (left < (int)size && array[left] > array[head])
head = left;

if (right < (int)size && array[right] > array[head])
head = right;
if (head != i)
{
_swap(&array[i], &array[head]);
print_array(array, print_size);
heapify(array, size, head, print_size);
}
}

/**
 * heap_sort - heap sort algorithm
 * @array: unsorted array of integer
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
int first, x;
size_t print_size = size;

if (size <= 1 || !array)
return;

first = (int)(size / 2 - 1);

for (x = first; x >= 0; x--)
heapify(array, size, x, print_size);

for (x = size - 1; x >= 0; x--)
{
if (x != 0)
{
_swap(&array[0], &array[x]);
print_array(array, print_size);
heapify(array, x, 0, print_size);
}
}
}
