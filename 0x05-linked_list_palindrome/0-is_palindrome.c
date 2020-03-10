#include <stddef.h>
#include "lists.h"


/**
 * do_is_palindrome - recursive helper function for is_palindrome
 * @left: left-side node
 * @right: right-side node
 * Return: 1 if nodes match, 2 if list is a palindrome, 0 if it can't be
 */
int do_is_palindrome(listint_t **left, listint_t *right)
{
	int result = 1;

	if (right->next != NULL)
		result = do_is_palindrome(left, right->next);
	if (result != 1)
		return (result);
	if ((*left)->n == right->n)
	{
		if ((*left)->next == right || *left == right)
			return (2);
		*left = (*left)->next;
		return (1);
	}
	return (0);
}


/**
 * is_palindrome - determine whether a singly-linked list is a palindrome
 * @head: point to linked list
 * Return: 1 if list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t **copy;

	if (head == NULL)
		return (0);
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	copy = head;
	return (!!do_is_palindrome(copy, *copy));
}
