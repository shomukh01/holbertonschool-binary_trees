#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root
 * @value: value to insert
 *
 * Return: pointer to the created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;
	int balance;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		node = avl_insert((avl_t **)&(*tree)->left, value);
		if ((*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		node = avl_insert((avl_t **)&(*tree)->right, value);
		if ((*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	balance = binary_tree_balance(*tree);

	/* Left heavy */
	if (balance > 1)
	{
		if (value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}

	/* Right heavy */
	if (balance < -1)
	{
		if (value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (node);
}
