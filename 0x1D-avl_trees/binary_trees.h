#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int val);
void binary_tree_print(binary_tree_t const *tree);
int binary_tree_height(binary_tree_t const *tree, int height);
int binary_tree_is_avl(binary_tree_t const *tree);

#endif
