#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create an empty node for a heap
 * @parent: the parent of the new node
 * @value: value to put in the node
 * Return: the new node or NULL if creation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
