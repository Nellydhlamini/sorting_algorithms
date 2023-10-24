#include "sort.h"

/**
 * recursive_radix_sort - radix sort algorithm - LSD
 * the number of do arecursion is linear depend with
 * the #digits of max number
 * @array: unsorted array of integer
 * @result: possible result
 * @size: size of the array
 * @lsd: least significant digit (1 last: 1, 2nd last: 1*10, 3: 1*10*10)
 * Return: void
 */
void recursive_radix_sort(int *array, int *result, size_t size, int lsd)
{
int x, idx_start, idx_index;
int ind[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


for (x = 0; x < (int)size; x++)
ind[(array[x] / lsd) % 10] += 1;

if (ind[0] == (int)size)
return;

for (x = 1; x < 10; x++)
ind[x] += ind[x - 1];
for (x = 9; x > 0; x--)
ind[x] = ind[x - 1];
ind[0] = 0;


for (x = 0; x < (int)size; x++)
{

idx_index = (array[x] / lsd) % 10;
idx_start = ind[idx_index];

result[idx_start] = array[x];

ind[idx_index]++;
}

for (x = 0; x < (int)size; x++)
array[x] = result[x];
print_array(array, size);
recursive_radix_sort(array, result, size, lsd * 10);
}

/**
 * radix_sort - radix sort algorithm - LSD
 * properties:
 * [LSD] least significant digit
 * stable -> not relevant to sort equals values
 * lenght of index table = base of number(binary, 10, hexa)
 * how many times sort -> max number of digit of nbr
 * @array: unsorted array of integer
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
int *result;

if (!array || size <= 1)
return;
result = malloc(sizeof(int) * size);
if (!result)
return;

recursive_radix_sort(array, result, size, 1);
free(result);
}
