#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if no common
 * ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = second;
	while (first)
 	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = temp;
		first = first->parent;
	}

	return (NULL);
}
