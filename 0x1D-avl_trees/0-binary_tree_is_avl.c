#include <limits.h>
#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_height - find the height of a binary tree
 * @tree: tree to check
 * @height: intermediate height value (used recursively, pass 0)
 * Return: height of tree
 */
int binary_tree_height(binary_tree_t const *tree, int height)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (height);
	height++;
	left = binary_tree_height(tree->left, height);
	right = binary_tree_height(tree->right, height);
	if (left - right > 1 || left - right < -1)
		return (-1);
	return (left > right ? left : right);
}


/**
 * binary_tree_is_bst - check if tree is sorted like a binary search tree
 * @tree: tree to check
 * @val: smallest value in the current subtree (used recursively, pass NULL)
 * Return: 1 if tree exists and is a BST, 0 otherwise
 */
int binary_tree_is_bst(binary_tree_t const *tree, int *val)
{
	int base = INT_MIN;

	if (val == NULL)
		val = &base;
	if (tree == NULL)
		return (1);
	if (!binary_tree_is_bst(tree->left, val))
		return (0);
	if (tree->n <= *val)
		return (0);
	*val = tree->n;
	return (binary_tree_is_bst(tree->right, val));
}


/**
 * binary_tree_is_avl - check if a binary tree is an AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is AVL tree, 0 otherwise
 */
int binary_tree_is_avl(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	if (!binary_tree_is_bst(tree, NULL))
		return (0);
	if (binary_tree_height(tree, 0) < 0)
		return (0);
	return (1);
}
