#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list && *list && (*list)->next)
	{
		current = *list;
		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			while (tmp->prev != NULL && tmp->prev->n > tmp->n)
			{
				tmp->prev->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = tmp->prev;
				tmp->next = tmp->prev;
				tmp->prev = tmp->prev->prev;
				tmp->next->prev = tmp;
				if (tmp->prev == NULL)
					*list = tmp;
				else
					tmp->prev->next = tmp;
				print_list(*list);
			}
		}
	}
}
