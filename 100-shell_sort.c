#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Function to sort an array of integers using Shell Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp;
	size_t j, i;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);

		gap /= 3;
	}
}
