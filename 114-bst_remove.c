#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_min - Finds the minimum node in a BST
 * @tree: Pointer to the root node
 *
 * Return: Pointer to the minimum node
 */
bst_t *bst_min(bst_t *tree)
{
	while (tree && tree->left)
		tree = tree->left;

	return (tree);
}

/**
 * remove_node - Removes the current node
 * @root: Pointer to the node to remove
 *
 * Return: Pointer to the new subtree root
 */
bst_t *remove_node(bst_t *root)
{
	bst_t *tmp;

	if (root->left == NULL)
	{
		tmp = root->right;
		if (tmp)
			tmp->parent = root->parent;
		free(root);
		return (tmp);
	}
	if (root->right == NULL)
	{
		tmp = root->left;
		if (tmp)
			tmp->parent = root->parent;
		free(root);
		return (tmp);
	}
	tmp = bst_min(root->right);
	root->n = tmp->n;
	root->right = bst_remove(root->right, tmp->n);
	if (root->right)
		root->right->parent = root;
	return (root);
}

/**
 * bst_remove - Removes a node from a BST
 * @root: Pointer to the root node
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
		return (remove_node(root));

	return (root);
}
