#include "binary_trees.h"

/**
 * bst_min_val - Finds the smallest node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the smallest node
 */
bst_t *bst_min_val(bst_t *root)
{
	bst_t *temp = root;

	while (temp && temp->left != NULL)
		temp = temp->left;

	return (temp);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

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
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = bst_min_val(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
