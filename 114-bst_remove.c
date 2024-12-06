#include "binary_trees.h"

/**
 * find_successor - Finds the minimum value in the right subtree
 * @node: Pointer to the right subtree
 *
 * Return: Minimum value in the subtree
 */
bst_t *find_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = find_successor(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
