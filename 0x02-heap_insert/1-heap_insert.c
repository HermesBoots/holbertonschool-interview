#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_swap - swap two nodes in binary tree
 * @a: first node
 * @b: second node
 */
void binary_tree_swap(binary_tree_t *a, binary_tree_t *b)
{
	binary_tree_t oldA, oldB;
	char sideA, sideB;

	oldA.parent = a->parent, oldA.left = a->left, oldA.right = a->right;
	oldB.parent = b->parent, oldB.left = b->left, oldB.right = b->right;
	sideA = a->parent != NULL ? (a->parent->left == a ? 'l' : 'r') : '\0';
	sideB = b->parent != NULL ? (b->parent->left == b ? 'l' : 'r') : '\0';
	a->parent = oldB.parent == a ? b : oldB.parent;
	a->left = oldB.left == a ? b : oldB.left;
	a->right = oldB.right == a ? b : oldB.right;
	b->parent = oldA.parent == b ? a : oldA.parent;
	b->left = oldA.left == b ? a : oldA.left;
	b->right = oldA.right == b ? a : oldA.right;
	if (a->left != NULL)
		a->left->parent = a;
	if (a->right != NULL)
		a->right->parent = a;
	if (b->left != NULL)
		b->left->parent = b;
	if (b->right != NULL)
		b->right->parent = b;
	if (sideB == 'l')
		a->parent->left = a;
	if (sideB == 'r')
		a->parent->right = a;
	if (sideA == 'l')
		b->parent->left = b;
	if (sideA == 'r')
		b->parent->right = b;
}

/**
 * heapify - ensure that a binary tree is a max heap
 * @root: root of the subtree to modify
 * Return: the new root of the subtree
 */
heap_t *heapify(heap_t *root)
{
	heap_t *new_root;

	if (root == NULL || (root->left == NULL && root->right == NULL))
		return (root);
	if (root->left != NULL)
		heapify(root->left);
	if (root->right != NULL)
		heapify(root->right);
	new_root = root;
	if (
		(root->left != NULL && root->left->n > root->n) &&
		(root->right == NULL || root->left->n >= root->right->n)
	)
	{
		binary_tree_swap(root, root->left);
		new_root = root->parent;
	}
	else if (root->right != NULL && root->right->n > root->n)
	{
		binary_tree_swap(root, root->right);
		new_root = root->parent;
	}
	return (new_root);
}

/**
 * find_hole - find the best place to insert to keep a binary tree complete
 * @root: root of tree
 * @node: node to insert
 * Return: 0 on failure, non-zero if node inserted
 */
int find_hole(binary_tree_t *root, binary_tree_t *node)
{
	size_t back = 1, front = 0, level = 0, size = 1;
	binary_tree_t **queue, **temp;

	if (root == NULL)
		return (0);
	queue = malloc(size * sizeof(*queue));
	if (queue == NULL)
		return (0);
	queue[0] = root;
	while (front <= back)
	{
		if (queue[front]->left == NULL)
		{
			queue[front]->left = node;
			node->parent = queue[front];
			break;
		}
		else if (queue[front]->right == NULL)
		{
			queue[front]->right = node;
			node->parent = queue[front];
			break;
		}
		else
		{
			if (back == size)
			{
				size += 1 << ++level;
				temp = realloc(queue, size * sizeof(*queue));
				if (temp == NULL)
					break;
				queue = temp;
			}
			queue[back++] = queue[front]->left;
			queue[back++] = queue[front++]->right;
		}
	}
	free(queue);
	return (node->parent != NULL);
}

/**
 * heap_insert - insert a new node into a max heap
 * @root: tree to put node in
 * @value: value to put in new node
 * Return: new node or NULL if creation fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (root == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	if (*root == NULL)
	{
		new->parent = NULL;
		*root = new;
		return (new);
	}
	if (!find_hole(*root, new))
		return (NULL);
	parent = heapify(*root);
	if (*root != parent)
		*root = parent;
	return (new);
}
