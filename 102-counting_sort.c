#include "sort.h"

/**
 * max_value - max value of an array of integers
 * @array: array of integers
 * @size: size of the array
 * Return: max number of the array
 */
int max_value(int *array, size_t size)
{
int maximum = 0;
size_t x = 0;

while (x < size)
{
if (maximum < array[x])
maximum = array[x];
x++;
}
return (maximum);
}

/**
 * counting_sort - counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
int maximum = 0, x = 0;
int *count, *new;

if (size <= 1)
return;

maximum = max_value(array, size);

count = malloc(sizeof(int) * (maximum + 1));
if (!count)
return;
for (x = 0; x <= maximum; x++)
count[x] = 0;

for (x = 0; x < (int)size; x++)
count[(array[x])] += 1;

for (x = 0; x < maximum; x++)
count[x + 1] += count[x];
print_array(count, maximum + 1);


new = malloc(sizeof(int) * size);
if (!new)
{
free(count);
return;
}

for (x = 0; x < (int)size; x++)
{
new[count[array[x] - 1]] = array[x];
count[(array[x] - 1)] += 1;
}
for (x = 0; x < (int)size; x++)
array[x] = new[x];
free(count);
free(new);
}
