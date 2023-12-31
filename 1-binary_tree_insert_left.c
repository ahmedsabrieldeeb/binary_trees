#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * Description: If parent already has a left-child, the new node
 * must take its place, and the old left-child must be set
 * as the left-child of the new node.
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure, or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = parent;

	if (parent->left != NULL)
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
	}

	/* should come after if, not before */
	parent->left = new_node;

	return (new_node);
}
