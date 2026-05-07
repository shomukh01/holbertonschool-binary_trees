#include "binary_trees.h"

/**
 * r_insert_node - recursive helper to insert node in AVL
 * @tree: double pointer to the root of the subtree
 * @parent: pointer to the parent node
 * @new_node: double pointer to store the newly created node
 * @value: the value to insert
 *
 * Return: pointer to the new root of the subtree
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent,
		     avl_t **new_node, int value)
{
	int b_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if (value < (*tree)->n)
		(*tree)->left = r_insert_node(&((*tree)->left), *tree, new_node, value);
	else if (value > (*tree)->n)
		(*tree)->right = r_insert_node(&((*tree)->right), *tree, new_node, value);
	else
		return (*tree);

	b_factor = binary_tree_balance(*tree);

	if (b_factor > 1 && value < (*tree)->left->n) /* LL Case */
		return (binary_tree_rotate_right(*tree));

	if (b_factor < -1 && value > (*tree)->right->n) /* RR Case */
		return (binary_tree_rotate_left(*tree));

	if (b_factor > 1 && value > (*tree)->left->n) /* LR Case */
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (b_factor < -1 && value < (*tree)->right->n) /* RL Case */
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* التعديل الجوهري: لازم نساوي الجذر بنتيجة الدالة */
	*tree = r_insert_node(tree, NULL, &new_node, value);

	return (new_node);
}
