#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Function to sort a doubly linked list using Cocktail Shaker Sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		for (current = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
				print_array_from_list(*list);
			}
		}

		end = current;

		if (swapped == 0)
			break;

		swapped = 0;

		for (; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
				print_array_from_list(*list);
			}
		}

		start = current->next;

	} while (swapped);
}

/**
 * swap_nodes - Function to swap two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *prev1 = (*node1)->prev;
	listint_t *next2 = (*node2)->next;

	if (prev1)
		prev1->next = *node2;
	else
		*list = *node2;

	if (next2)
		next2->prev = *node1;

	(*node2)->prev = prev1;
	(*node2)->next = *node1;

	(*node1)->prev = *node2;
	(*node1)->next = next2;
}

/**
 * print_array_from_list - Prints the values of a doubly linked list as an array
 *
 * @list: The list to be printed as an array
 */
void print_array_from_list(const listint_t *list)
{
	size_t size = 0;
	const listint_t *temp = list;
	int *array;
	size_t i;
	while (temp)
	{
		size++;
		temp = temp->next;
	}

	array = malloc(sizeof(int) * size);
	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		array[i] = list->n;
		list = list->next;
	}

	print_array(array, size);
	free(array);
}

