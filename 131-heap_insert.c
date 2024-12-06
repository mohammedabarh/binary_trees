#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap for insertion.
 * @value: The value to be stored in the newly created node.
 *
 * Return: Pointer to the newly created node,
 *         or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* Subtract all nodes except for those on the bottom-most level */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse the tree to find the first empty slot based on the binary
	 * representation of the number of leaves.
	 * Example:
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * the 4th tier. 5 in binary is 101. 1 indicates right, 0 indicates left.
	 * The first empty node corresponds to 101 == RLR, which is
	 * *root->right->left->right.
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Swap values with parent until the parent's value exceeds the new value */

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root of the tree to measure.
 *
 * Return: The size of the tree,
 *         or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
