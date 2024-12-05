/* 6-binary_tree_preorder.c */
#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: Performs pre-order traversal on a binary tree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
