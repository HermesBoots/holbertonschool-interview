#include <stdlib.h>
#include <string.h>
#include "list.h"


/**
 * add_node_end - add a node to the end of a circular list
 * @list: list to add to
 * @str: string to add to the list
 * Return: pointer to the new node, NULL if it couldn't be created
 */
List *add_node_end(List **list, char *str)
{
	List *newNode;
	char *newStr;

	if (list == NULL)
		return (NULL);
	newNode = malloc(sizeof(*newNode));
	newStr = strdup(str);
	if (newNode == NULL || newStr == NULL)
	{
		free(newNode);
		free(newStr);
		return (NULL);
	}
	newNode->str = newStr;
	if (*list == NULL) {
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
	}
	else if ((*list)->prev == *list)
	{
		newNode->next = *list;
		newNode->prev = *list;
		(*list)->next = newNode;
		(*list)->prev = newNode;
	}
	else
	{
		newNode->next = *list;
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	return (newNode);
}


/**
 * add_node_begin - add a node to the beginning of a circular list
 * @list: list to add to
 * @str: string to add to list
 * Return: pointer to the new node, NULL if it couldn't be created
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode;
	char *newStr;

	if (list == NULL)
		return (NULL);
	newNode = malloc(sizeof(*newNode));
	newStr = strdup(str);
	if (newNode == NULL || newStr == NULL)
	{
		free(newNode);
		free(newStr);
		return (NULL);
	}
	newNode->str = newStr;
	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else if ((*list)->prev == *list)
	{
		newNode->next = *list;
		newNode->prev = *list;
		(*list)->next = newNode;
		(*list)->prev = newNode;
	}
	else
	{
		newNode->next = *list;
		newNode->prev = (*list)->prev;
		(*list)->prev->next = newNode;
		(*list)->prev = newNode;
	}
	*list = newNode;
	return (newNode);
}
