#include "binary_trees.h"

/**
 * count_nodes - Counts the nodes in a binary tree
 * @root: Pointer to the root node
 *
 * Return: Number of nodes
 */
int count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @root: Pointer to the root node
 * @index: Index of current node
 * @number_nodes: Total number of nodes
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *root, int index, int number_nodes)
{
	if (root == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, number_nodes) &&
		is_complete(root->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (tree == NULL)
		return (0);

	node_count = count_nodes(tree);
	return (is_complete(tree, 0, node_count));
}
