#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using LTO
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;
  
    const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);
    if (queue == NULL)
        return;

    int front = 0, rear = -1;
    const binary_tree_t *curr = tree;

    while (curr != NULL)
    {
        func(curr->n);

        if (curr->left != NULL)
            queue[++rear] = curr->left;

        if (curr->right != NULL)
            queue[++rear] = curr->right;
      
        if (front <= rear)
            curr = queue[front++];
        else
            curr = NULL;
    }

    free(queue);
}
