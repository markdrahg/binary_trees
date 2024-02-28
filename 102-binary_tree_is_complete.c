#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: If the tree is complete, 1, otherwise, 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int complete = 1;
    int full = 0;

    if (tree == NULL)
        return (0);

    /* Create a queue for level order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
    if (queue == NULL)
        return (0);

    int front = 0, rear = -1, size = 1;
    const binary_tree_t *current;

    /* Enqueue root */
    queue[++rear] = (binary_tree_t *)tree;

    while (front <= rear)
    {
        /* Dequeue node and make it current */
        current = queue[front++];

        if (current->left)
        {
            if (full)
            {
                complete = 0;
                break;
            }
            queue[++rear] = current->left;
        }
        else
        {
            full = 1;
        }

        if (current->right)
        {
            if (full)
            {
                complete = 0;
                break;
            }
            queue[++rear] = current->right;
        }
        else
        {
            full = 1;
        }
    }

    /* Free the queue */
    free(queue);

    return (complete);
}
