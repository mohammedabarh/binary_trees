#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				   const binary_tree_t *second)
{
	binary_tree_t *temp1, *temp2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	temp1 = first->parent;
	temp2 = second->parent;

	if (first == temp2 || !temp1 || (!temp1->parent && temp2))
		return (binary_trees_ancestor(first, temp2));
	else if (temp1 == second || !temp2 || (!temp2->parent && temp1))
		return (binary_trees_ancestor(temp1, second));

	return (binary_trees_ancestor(temp1, temp2));
}
