#include "binary_trees.h"

/**
 * binary_tree_height_p - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height_p(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = binary_tree_height_p(tree->left);
	right_height = binary_tree_height_p(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (!tree)
		return (0);

	l = tree->left;
	r = tree->right;

	if (!l && !r)
		return (1);

	if (!l || !r)
		return (0);

	if (binary_tree_height_p(l) == binary_tree_height_p(r))
		return (binary_tree_is_perfect(l) && binary_tree_is_perfect(r));

	return (0);
}