#include "binary_trees.h"

/**
 * create_tree - helper that builds an AVL tree recursively
 * @array: pointer to the first element of the array
 * @start: starting index
 * @end: ending index
 * @parent: pointer to the parent node
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *create_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	new_node->left = create_tree(array, start, mid - 1, new_node);
	new_node->right = create_tree(array, mid + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (create_tree(array, 0, (int)size - 1, NULL));
}
