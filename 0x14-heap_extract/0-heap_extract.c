#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


#define DELETE_CHILD(node) do { \
	if (node->parent->left == node) \
		node->parent->left = NULL; \
	if (node->parent->right == node) \
		node->parent->right = NULL; \
	node->parent = NULL; \
} while (0)


/**
 * tree_height - get the height of a binary tree
 * @tree: tree to search
 * @height: make this 0
 * Return: tree height
 */
size_t tree_height(heap_t const *tree, size_t height)
{
	size_t left = 0, right = 0;

	height++;
	if (tree->left != NULL)
		left = tree_height(tree->left, height);
	if (tree->right != NULL)
		right = tree_height(tree->right, height);
	if (left == 0 && right == 0)
		return (height);
	return (left > right ? left : right);
}


/**
 * last_node - return the last node in the tree
 * @tree: tree to search
 * @depth: how deep we are in the tree
 * Return: last node in the tree
 */
heap_t *last_node(heap_t *tree, size_t depth)
{
	heap_t *result = NULL;

	if (depth == 0)
		return (tree);
	if (tree->left == NULL && tree->right == NULL)
		return (NULL);
	if (tree->right != NULL)
		result = last_node(tree->right, depth - 1);
	if (tree->left != NULL && result == NULL)
		result = last_node(tree->left, depth - 1);
	return (result);
}


/**
 * swap_nodes - swap two nodes in a tree
 * @parent: first node to swap
 * @child: second node to swap
 */
void swap_nodes(heap_t *parent, heap_t *child)
{
	heap_t temp;

	temp.parent = parent->parent;
	temp.left = parent->left, temp.right = parent->right;
	parent->left = child->left, parent->right = child->right;
	if (parent->left != NULL)
		parent->left->parent = parent;
	if (parent->right != NULL)
		parent->right->parent = parent;
	parent->parent = child;
	if (temp.left == child)
	{
		child->left = parent;
		child->right = temp.right;
		if (child->right != NULL)
			child->right->parent = child;
	}
	else
	{
		child->right = parent;
		child->left = temp.left;
		if (child->left != NULL)
			child->left->parent = child;
	}
	child->parent = temp.parent;
	if (temp.parent != NULL && temp.parent->left == parent)
		temp.parent->left = child;
	if (temp.parent != NULL && temp.parent->right == parent)
		temp.parent->right = child;
}


/**
 * heap_extract - extract the root value from a heap
 * @root: pointer to root of the heap
 * Return: value at root
 */
int heap_extract(heap_t **root)
{
	heap_t *child, *parent;
	int ret;

	if (root == NULL || *root == NULL)
		return (0);
	ret = (*root)->n;
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (ret);
	}
	parent = last_node(*root, tree_height(*root, 0) - 1);
	parent->left = (*root)->left, parent->right = (*root)->right;
	DELETE_CHILD(parent);
	free(*root);
	*root = parent;
	while ((parent->left != NULL && parent->left->n > parent->n) ||
		(parent->right != NULL && parent->right->n > parent->n))
	{
		if ((parent->left != NULL && parent->right != NULL) &&
			(parent->right->n > parent->left->n))
			child = parent->right;
		else if (parent->left != NULL && parent->left->n > parent->n)
			child = parent->left;
		else if (parent->right != NULL && parent->right->n > parent->n)
			child = parent->right;
		swap_nodes(parent, child);
		if (child->parent == NULL)
			*root = child;
	}
	return (ret);
}
