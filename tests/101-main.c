#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * create_listint - It creates a doubly linked list from an array of given ints.
 *
 * @array: It's an array to convert to a doubly linked list.
 * @size: Is the size of the array.
 *
 * Return: A pointer to the starting element of the created list. Otherwise, NULL.
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * main - main function.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
