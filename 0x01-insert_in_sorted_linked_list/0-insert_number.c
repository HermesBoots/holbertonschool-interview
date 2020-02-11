#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node into a sorted linked list
 * @head: list to insert into
 * @number: value to put in new node
 * Return: new node or NULL if node could not be inserted
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *node;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	node = *head;
	if (node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}
	while (node->next != NULL && node->next->n < number)
		node = node->next;
	new->next = node->next;
	node->next = new;
	return (new);
}
