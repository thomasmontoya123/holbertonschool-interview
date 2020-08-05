#include "binary_trees.h"


/**
 * place - find location for the new node
 * @root: pointer to the root node
 *
 * Return: pointer to the place
 */
heap_t *place(heap_t *root)
{
	heap_t *queue[100], *place = root;
	int start = 0, end = 0;

	while (place && place->left && place->right)
	{
		queue[start] = place->left;
		start++;
		if (start >= 99)
			start = 0;
		queue[start] = place->right;
		start++;
		if (start >= 99)
			start = 0;
		place = queue[end];
		end++;
		if (end >= 99)
			end = 0;
	}

	return (place);
}

/**
 * heap_insert - insert a value into a max binary heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *spot;
	int holder;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}

	spot = place(*root);
	new_node = binary_tree_node(spot, value);
	if (spot->left == NULL)
		spot->left = new_node;
	else
		spot->right = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		holder = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = holder;
		new_node = new_node->parent;
	}

	return (new_node);
}

