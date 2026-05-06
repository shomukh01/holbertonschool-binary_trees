#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	temp = *tree;
	while (temp != NULL)
	{
		if (value == temp->n)
			return (NULL);

		if (value < temp->n)
		{
			if (temp->left == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->left = new_node;
				return (new_node);
			}
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			if (temp->right == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->right = new_node;
				return (new_node);
			}
			temp = temp->right;
		}
	}
	return (NULL);
}
