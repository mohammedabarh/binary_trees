#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/* Definition of the binary tree node */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(binary_tree_t *first, binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_bst(const binary_tree_t *tree);
binary_tree_t *bst_insert(binary_tree_t **tree, int value);
binary_tree_t *array_to_bst(int *array, size_t size);
binary_tree_t *bst_search(const binary_tree_t *tree, int value);
binary_tree_t *bst_remove(binary_tree_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
binary_tree_t *avl_insert(binary_tree_t **tree, int value);
binary_tree_t *array_to_avl(int *array, size_t size);
binary_tree_t *avl_remove(binary_tree_t *root, int value);
int binary_tree_is_heap(const binary_tree_t *tree);
binary_tree_t *heap_insert(binary_tree_t **root, int value);
binary_tree_t *array_to_heap(int *array, size_t size);
int heap_extract(binary_tree_t **root);
void heap_to_sorted_array(binary_tree_t *tree, int **array, size_t *size);

#endif /* BINARY_TREES_H */
