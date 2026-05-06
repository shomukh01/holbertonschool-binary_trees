#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
<<<<<<< HEAD
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value == tree->n)
			return ((bst_t *)tree);
		else if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
=======
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for
 *
 * Return: Pointer to the node containing value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	return (bst_search(tree->right, value));
}      
>>>>>>> d169844 (Update binary trees tasks)
