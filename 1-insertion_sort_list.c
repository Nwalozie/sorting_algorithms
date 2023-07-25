#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion Sort algorithm.
 *
 * @list: Pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *sorted = NULL;
        listint_t *temp;
        listint_t *current = *list;
        listint_t *next_node;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        while (current != NULL)
        {
                next_node = current->next;

                if (sorted == NULL || sorted->n >= current->n)
                {
                        current->next = sorted;
                        current->prev = NULL;
                        if (sorted)
                                sorted->prev = current;
                        sorted = current;
                }
                else
                {
                        temp = sorted;
                        while (temp->next != NULL && temp->next->n < current->n)
                                temp = temp->next;

                        current->next = temp->next;
                        current->prev = temp;
                        if (temp->next)
                                temp->next->prev = current;
                        temp->next = current;
                }

                current = next_node;

                print_list(sorted); 
        }

        *list = sorted;

	listint_t *sorted = NULL;
	listint_t *temp;
	listint_t *current = *list;
	listint_t *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		next_node = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			print_list(sorted);
			*temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;
			if (temp->next)
				temp->next->prev = current;
			temp->next = current;
		}

		current = next_node;
	}

	*list = sorted;
}

