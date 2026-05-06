#include "binary_trees.h"

/**
 * height - measures height of a tree
 * @tree: pointer to node
 *
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * is_bst - checks if tree is BST
 * @tree: pointer to node
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - checks balance of tree
 * @tree: pointer to node
 *
 * Return: 1 if balanced, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
	int left, right, diff;

	if (tree == NULL)
		return (1);

	left = height(tree->left);
	right = height(tree->right);
	diff = left - right;

	if (diff > 1 || diff < -1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - checks if tree is AVL
 * @tree: pointer to root
 *
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst(tree, -2147483648, 2147483647))
		return (0);

	return (is_avl(tree));
}
