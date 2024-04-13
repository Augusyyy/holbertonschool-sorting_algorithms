#include "sort.h"
/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	int base = 1;
	int bucket[10] = { 0 };
	int i;
	int *tmp;
	
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	tmp = (int *)malloc(sizeof(int) * size);

	while (max / base > 0)
	{
		for (i = 0; i < size; i++)
			bucket[array[i] / base % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for ( i = size - 1; i >= 0; i--)
		{
			tmp[bucket[array[i] / base % 10] - 1] = array[i];
			bucket[array[i] / base % 10]--;
		}
		for (i = 0; i < size; i++)
		{
			array[i] = tmp[i];
		}
		base *= 10;
		print_array(array, size);
	}
	free(tmp);
}
