#include <stdlib.h>
#include "binary_trees.h"


/**
 * do_build_avl - recursive helper function for sorted_array_to_avl
 * @arr: array to build tree from
 * @left: first index to consider in this sub-array
 * @right: first index to ignore in this sub-array
 * @parent: parent of the new node
 * Return: 0 on failure, 1 on success
 */
int do_build_avl(int *arr, size_t left, size_t right, avl_t *parent)
{
	avl_t *node;
	size_t index;

	index = left + (right - left - 1) / 2;
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (0);
	node->parent = parent;
	node->n = arr[index];
	node->left = NULL;
	node->right = NULL;
	if (arr[index] < parent->n)
		parent->left = node;
	else
		parent->right = node;
	if (index - left > 0)
		if (!do_build_avl(arr, left, index, node))
		{
			free(node);
			return (0);
		}
	if (right - index > 1)
		if (!do_build_avl(arr, index + 1, right, node))
		{
			free(node);
			return (0);
		}
	return (1);
}

/**
 * sorted_array_to_avl - build an AVL tree using values from a sorted array
 * @array: array with values to put in tree
 * @size: number of elements in array
 * Return: pointer to new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	if (size < 1)
		return (NULL);
	middle = (size - 1) / 2;
	root = malloc(sizeof(*root));
	if (root == NULL)
		return (NULL);
	root->parent = NULL;
	root->n = array[middle];
	root->left = NULL;
	root->right = NULL;
	if (middle > 0)
		if (!do_build_avl(array, 0, middle, root))
		{
			free(root);
			return (NULL);
		}
	if (size - middle  > 1)
		if (!do_build_avl(array, middle + 1, size, root))
		{
			free(root);
			return (NULL);
		}
	return (root);
}
