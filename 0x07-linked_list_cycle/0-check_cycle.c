#include "lists.h"


/**
 * check_cycle - checks if a linked list loops back on itself
 * @list: pointer to first node structure in the list
 *
 * Return: 1 if list has a cycle, 0 if it doesn't
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (list == NULL || list->next == NULL)
		return (0);
	slow = list;
	fast = list->next;
	while (fast != NULL)
	{
		if (fast == slow)
			return (1);
		fast = fast->next;
		if (fast == NULL)
			break;
		if (fast == slow)
			return (1);
		fast = fast->next;
		slow = slow->next;
	}
	return (0);
}
