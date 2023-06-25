#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: integer pointer
 * @b: integer pointer
*/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - performs Lomuto Partition algorithm
 * @array: array of integers to sort
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: ending endex of the new array
 */
size_t lomuto_partition(int *array, int low, int high, int size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high && array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * _quick_sort - sorts an array of integers in ascending order
 *               using the Quick sort algorithm
 * @array: array of integers to sort
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: None
 */
void _quick_sort(int *array, int low, int high, int size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		_quick_sort(array, low, p - 1, size);
		_quick_sort(array, p + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 *               using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort(array, 0, size - 1, size);
}
