#include "sort.h"
/**
 * swap_3 - swap_3
 * @p1: p1
 * @p2: p2
 */
void swap_3(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
/***
 * part_sort - part_sort
 * @array: array
 * @size: size
 * @left: left
 * @right: right
 * @return
 */
int part_sort(int *array, size_t size, size_t left, size_t right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && array[right] >= array[key])
		{
			right--;
		}
		while (left < right && array[left] <= array[key])
		{
			left++;
		}
		swap_3(&array[right], &array[left]);
		print_array(array, size);
	}
	swap_3(&array[key], &array[left]);
	print_array(array, size);
	key = left;
	return left;
}
/**
 * _quick_sort - _quick_sort
 * @array: array
 * @size: size
 * @begin: begin
 * @end: end
 */
void _quick_sort(int* array, size_t size, size_t begin, size_t end)
{
	if (begin >= end)
	{
		return;
	}
	int key = part_sort(array, size, begin, end);
	_quick_sort(array, size, begin, key - 1);
	_quick_sort(array, size, key + 1, end);
}
/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	size_t begin = 0, end = size - 1;
	_quick_sort(array, size, begin, end);
}
