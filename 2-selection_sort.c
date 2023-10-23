#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
unsigned int a, b, ind, swap;
int min;

if (size <= 1)
return;

for (b = 0; b < size; b++)
{

swap = 0;
min = array[b];
for (a = b; a < size; a++)
{
if (array[a] < min)
min = array[a], ind = a, swap = 1;
}

if (swap == 1)
{
array[ind] = array[b];
array[b] = min;
print_array(array, size);
}
}
}
