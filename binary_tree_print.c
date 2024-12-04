#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Function prototypes */
void binary_tree_print(const binary_tree_t *tree);
static void print_tree(const binary_tree_t *tree, int level, int is_left);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        printf("(nil)\n");
        return;
    }
    print_tree(tree, 0, 0);
}

/**
 * print_tree - Helper function to print a binary tree
 * @tree: Pointer to the root node of the tree to print
 * @level: Current level in the tree
 * @is_left: Indicates if the current node is a left child
 */
static void print_tree(const binary_tree_t *tree, int level, int is_left)
{
    if (tree == NULL)
        return;

    if (tree->right)
    {
        print_tree(tree->right, level + 1, 0);
    }

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }

    if (is_left)
    {
        printf("L---- ");
    }
    else
    {
        printf("R---- ");
    }

    printf("%d\n", tree->n);

    if (tree->left)
    {
        print_tree(tree->left, level + 1, 1);
    }
}
