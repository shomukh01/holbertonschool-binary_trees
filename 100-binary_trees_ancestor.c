#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *p1, *p2;

	if (first == NULL || second == NULL)
		return (NULL);

	p1 = (binary_tree_t *)first;
	p2 = (binary_tree_t *)second;

	while (p1 != p2)
	{
		if (p1 == NULL)
			p1 = (binary_tree_t *)second;
		else
			p1 = p1->parent;

		if (p2 == NULL)
			p2 = (binary_tree_t *)first;
		else
			p2 = p2->parent;
	}

	return (p1);
}
