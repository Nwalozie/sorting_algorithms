#include "sort.h"

/**
 * swap - Swaps the values of two integers using pointers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * This function takes two pointers to integers and swaps their values.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using the last element as the pivot
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot after partitioning
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursive - sorts the array using the Quick Sort algorithm
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		print_array(array, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
	{
		return;
	}


	quick_sort_recursive(array, 0, size - 1);
	print_array(array, size);


}
