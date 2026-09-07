#ifndef CDS_AVL_H
#define CDS_AVL_H

#include <stddef.h>
#include <stdbool.h>

typedef struct CDSAVL CDSAVL;

/**
 * Creates an empty AVL tree.
 *
 * @return Pointer to the created tree, or NULL if memory allocation fails.
 */
CDSAVL *cds_avl_create(void);

/**
 * Destroys the tree and frees all allocated memory.
 *
 * If tree is NULL, the function does nothing.
 *
 * @param tree Tree to destroy.
 */
void cds_avl_destroy(CDSAVL *tree);

/**
 * Returns the number of elements in the tree.
 *
 * @param tree Tree to inspect.
 * @return Number of elements in the tree, or 0 if tree is NULL.
 */
size_t cds_avl_size(const CDSAVL *tree);

/**
 * Checks whether the tree is empty.
 *
 * @param tree Tree to inspect.
 * @return true if the tree is empty or NULL, false otherwise.
 */
bool cds_avl_empty(const CDSAVL *tree);

/**
 * Checks whether the tree contains the specified value.
 *
 * @param tree Tree to inspect.
 * @param value Value to search for.
 * @return true if the value is found, false otherwise.
 */
bool cds_avl_contains(const CDSAVL *tree, int value);

/**
 * Retrieves the minimum value in the tree.
 *
 * @param tree Tree to inspect.
 * @param value Pointer where the minimum value will be stored.
 * @return true on success, false if tree or value is NULL,
 *         or if the tree is empty.
 */
bool cds_avl_min(const CDSAVL *tree, int *value);

/**
 * Retrieves the maximum value in the tree.
 *
 * @param tree Tree to inspect.
 * @param value Pointer where the maximum value will be stored.
 * @return true on success, false if tree or value is NULL,
 *         or if the tree is empty.
 */
bool cds_avl_max(const CDSAVL *tree, int *value);

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
bool cds_avl_height(const CDSAVL *tree, int *value);

/**
 * Traverses the tree in inorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_avl_inorder(const CDSAVL *tree, void (*visit)(int));

/**
 * Traverses the tree in preorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_avl_preorder(const CDSAVL *tree, void (*visit)(int));

/**
 * Traverses the tree in postorder and calls visit for each element.
 *
 * If tree or visit is NULL, the function does nothing.
 *
 * @param tree Tree to traverse.
 * @param visit Function called for each visited value.
 */
void cds_avl_postorder(const CDSAVL *tree, void (*visit)(int));

/**
 * Inserts a value into the tree.
 *
 * Duplicate values are not allowed. The tree is automatically
 * rebalanced after insertion when necessary.
 *
 * @param tree Tree to modify.
 * @param value Value to insert.
 * @return true if the value was inserted successfully, false if tree is NULL,
 *         the value already exists, or memory allocation fails.
 */
bool cds_avl_insert(CDSAVL *tree, int value);

/**
 * Removes a value from the tree.
 *
 * The tree is automatically rebalanced after removal when necessary.
 *
 * @param tree Tree to modify.
 * @param value Value to remove.
 * @return true if the value was found and removed, false otherwise.
 */
bool cds_avl_remove(CDSAVL *tree, int value);

/**
 * Removes all elements from the tree.
 *
 * @param tree Tree to clear.
 */
void cds_avl_clear(CDSAVL *tree);

#endif