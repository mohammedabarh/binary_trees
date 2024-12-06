/* 14-binary_tree_balance.c */
#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of binary tree for balance factor
 * @tree: Pointer to root node of tree to measure height
 *
 * Return: Height of tree, 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
        size_t left_height, right_height;

        if (!tree)
                return (0);

        left_height = binary_tree_height_b(tree->left);
        right_height = binary_tree_height_b(tree->right);

        return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Pointer to root node of tree to measure balance factor
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
        int left_height, right_height;

        if (!tree)
                return (0);

        left_height = binary_tree_height_b(tree->left);
        right_height = binary_tree_height_b(tree->right);

        return (left_height - right_height);
}
