#include "binary_trees.h"

/**
 * successor - gets the next in-order successor
 * @node: right child of node being deleted
 * Return: pointer to the successor node
 */
avl_t *successor(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bal - balances an AVL tree after deletion
 * @root: root of the tree to balance
 * Return: new root after balancing
 */
avl_t *bal(avl_t *root)
{
	int b_factor;

	if (root == NULL)
		return (NULL);

	b_factor = binary_tree_balance(root);

	if (b_factor > 1)
	{
		if (binary_tree_balance(root->left) < 0)
			root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (b_factor < -1)
	{
		if (binary_tree_balance(root->right) > 0)
			root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove
 * Return: pointer to the new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (bal(temp));
		}
		temp = successor(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	return (bal(root));
}
