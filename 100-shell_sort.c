#include "sort.h"

/**
 * _shell_sort - sorts an array of integers in ascending order
 *               using the  shell sort algorithm
 * @array: array of integers to sort
 * @n: sequence number from Knuth sequence
 * @size: size of the array
 */
void _shell_sort(int *array, int n, int size)
{
	int i, j, tmp;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			j = i;
			tmp = array[i];
			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
				array[j] = tmp;
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
/**
 * shell_sort - sorts an array of integers in ascending order
 *               using the  shell sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n <= size / 3)
		n = n * 3 + 1;
	_shell_sort(array, n, size);
}
