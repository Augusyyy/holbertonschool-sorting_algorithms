#include "sort.h"
/**
 * swap_102 - swap_102
 * @p1: p1
 * @p2: p2
 */
void swap_102(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
/**
 * find_count_len - find_count_len
 * @a:
 * @len:
 * @return
 */
int find_count_len(int* a, size_t len)
{
	int min = a[0], max = a[0];
	int i;
	int count = 0;

	for (i = 0; i < len; i++)
	{
		count++;
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	return max - min + 1;
}
/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int count_arr_len = find_count_len(array, size);
	int* count_arr = (int*)malloc(sizeof(int) * count_arr_len);
	size_t i;
	int j, offset;
	int *b;

	for (i = 0; i < count_arr_len; i++)
		count_arr[i] = 0;

	offset = array[0];
	for (i = 1; i < size; i++)
		if (array[i] < offset)
			offset = array[i];

	b = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		count_arr[array[i] - offset]++;

	for (j = 1; j < count_arr_len; j++)
		count_arr[j] += count_arr[j - 1];

	for (i = size; i > 0; i--)
		b[--count_arr[array[i - 1] - offset]] = array[i - 1];

	print_array(count, offset + 1);
	for (i = 0; i < size; i++)
		swap_102(&array[i], &b[i]);

	free(count_arr);
	count_arr = NULL;
	free(b);
	b = NULL;
}
