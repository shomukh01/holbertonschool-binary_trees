#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + tree_height(tree->left) : 0;
	right_h = tree->right ? 1 + tree_height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * print_level - Prints nodes at a specific level
 * @tree: Pointer to the root node
 * @func: Pointer to a function to call for each node
 * @level: Level to print
 */
void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 * @tree: Pointer to the root node
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree) + 1;

	for (i = 1; i <= height; i++)
		print_level(tree, func, i);
}
