#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_avl_helper - Helper function to check if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed
 * @max: Maximum value allowed
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int balance;
	size_t left_height, right_height;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	balance = left_height > right_height ?
		left_height - right_height : right_height - left_height;

	if (balance > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
