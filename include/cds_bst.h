#ifndef CDS_BST_H
#define CDS_BST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CDSBST CDSBST;

/**
 * Creates an empty binary search tree.
 *
 * @return Pointer to the created tree, or NULL if memory allocation fails.
 */
CDSBST *cds_bst_create(void);

/**
 * Destroys the tree and frees all allocated memory.
 *
 * If tree is NULL, the function does nothing.
 *
 * @param tree Tree to destroy.
 */
void cds_bst_destroy(CDSBST *tree);

/**
 * Returns the number of elements in the tree.
 *
 * @param tree Tree to inspect.
 * @return Number of elements in the tree, or 0 if tree is NULL.
 */
size_t cds_bst_size(const CDSBST *tree);

/**
 * Checks whether the tree is empty.
 *
 * @param tree Tree to inspect.
 * @return true if the tree is empty or NULL, false otherwise.
 */
bool cds_bst_empty(const CDSBST *tree);

/**
 * Checks whether the tree contains the specified value.
 *
 * @param tree Tree to inspect.
 * @param value Value to search for.
 * @return true if the value is found, false otherwise.
 */
bool cds_bst_contains(const CDSBST *tree, int value);

/**
 * Retrieves the minimum value in the tree.
 *
 * @param tree Tree to inspect.
 * @param value Pointer where the minimum value will be stored.
 * @return true on success, false if tree or value is NULL,
 *         or if the tree is empty.
 */
bool cds_bst_min(const CDSBST *tree, int *value);

/**
 * Retrieves the maximum value in the tree.
 *
 * @param tree Tree to inspect.
 * @param value Pointer where the maximum value will be stored.
 * @return true on success, false if tree or value is NULL,
 *         or if the tree is empty.
 */
bool cds_bst_max(const CDSBST *tree, int *value);

/**
 * Retrieves the height of the tree.
 *
 * The height of an empty tree is -1, and the height of a tree
 * containing only the root is 0.
 *
 * @param tree Tree to inspect.
 * @param value Pointer where the tree height will be stored.
 * @return true on success, false if tree or value is NULL.
 */
bool cds_bst_height(const CDSBST *tree, int *value);

/**
 * Traverses the tree in inorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_bst_inorder(const CDSBST *tree, void (*visit)(int));

/**
 * Traverses the tree in preorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_bst_preorder(const CDSBST *tree, void (*visit)(int));

/**
 * Traverses the tree in postorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_bst_postorder(const CDSBST *tree, void (*visit)(int));

/**
 * Inserts a value into the tree.
 *
 * Duplicate values are not allowed.
 *
 * @param tree Tree to modify.
 * @param value Value to insert.
 * @return true if the value was inserted successfully, false if tree is NULL,
 *         the value already exists, or memory allocation fails.
 */
bool cds_bst_insert(CDSBST *tree, int value);

/**
 * Removes a value from the tree.
 *
 * @param tree Tree to modify.
 * @param value Value to remove.
 * @return true if the value was found and removed, false otherwise.
 */
bool cds_bst_remove(CDSBST *tree, int value);

/**
 * Removes all elements from the tree.
 *
 * @param tree Tree to clear.
 */
void cds_bst_clear(CDSBST *tree);

#endif