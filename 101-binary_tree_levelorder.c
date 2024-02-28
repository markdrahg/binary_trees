#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue for level order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
    if (queue == NULL)
        return;

    int front = 0, rear = -1, size = 1;
    const binary_tree_t *current;

    /* Enqueue root */
    queue[++rear] = (binary_tree_t *)tree;

    while (front <= rear)
    {
        /* Dequeue node and make it current */
        current = queue[front++];

        /* Call the function */
        func(current->n);

        /* Enqueue left child */
        if (current->left)
        {
            if (rear >= size - 1)
            {
                size *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * size);
                if (queue == NULL)
                    return;
            }
            queue[++rear] = current->left;
        }

        /* Enqueue right child */
        if (current->right)
        {
            if (rear >= size - 1)
            {
                size *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * size);
                if (queue == NULL)
                    return;
            }
            queue[++rear] = current->right;
        }
    }

    /* Free the queue */
    free(queue);
}
