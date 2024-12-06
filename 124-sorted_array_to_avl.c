#include "binary_trees.h"

/**
 * aux_sort - Creates an AVL tree using the middle element of the array.
 * @parent: Pointer to the parent node for the new node.
 * @array: The sorted array from which the tree is created.
 * @begin: The starting index of the array segment.
 * @last: The ending index of the array segment.
 * Return: Pointer to the created AVL tree, or NULL on failure.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: The sorted array to convert into an AVL tree.
 * @size: The number of elements in the sorted array.
 * Return: Pointer to the AVL tree created from the sorted array, or NULL if empty.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
