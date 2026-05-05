#include "binary_trees.h"

/**
 * tree_depth - measures the depth of the leftmost leaf
 * @tree: pointer to the root node
 *
 * Return: depth of the tree
 */
int tree_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_rec - recursive helper to check if tree is perfect
 * @tree: pointer to the root node
 * @d: depth of the leftmost leaf
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_rec(tree->left, d, level + 1) &&
		is_perfect_rec(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if NULL or not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = tree_depth(tree);
	return (is_perfect_rec(tree, d, 0));
}
