#include "sort.h"

/**
 * Swap - Swap two integers in an array.
 * @num: array
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void Swap(int *num, int i, int j)
{
	int temp;

	temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}
/**
 * Heapify - Turn a binary tree into a complete binary heap.
 * @num: An array of integers representing a binary tree.
 * @len: The size of the array/tree.
 * @k: The index of the base row of the tree.
 */
void Heapify(int *num, int len, int k)
{
	int root, lchild, rchild;
	
	if (k < len)
	{
		root = k;
		lchild = 2 * k + 1;
		rchild = 2 * k + 2;
		if (lchild < len && num[root] < num[lchild])
		{
			root = lchild;
		}
		if (rchild < len && num[root] < num[rchild])
		{
			root = rchild;
		}

		if (root != k)
		{
			Swap(num, root, k);
			print_array(array, size);
			Heapify(num, len, root);
		}
	}
}
/**
 * CreateHeap - Turn a binary tree into a complete binary heap.
 * @num: An array of integers representing a binary tree.
 * @len: The size of the array/tree.
 */
void CreateHeap(int *num, int len)
{
	int i;
	int last = len - 1;
	int parent = (last - 1) / 2;

	for (i = parent; i >= 0; i--)
	{
		Heapify(num, len, i);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	CreateHeap(array, size);
	for (i = size - 1; i >= 0; i--)
	{
		Swap(array, i, 0);
		print_array(array, size);
		Heapify(array, i, 0);
	}
}
