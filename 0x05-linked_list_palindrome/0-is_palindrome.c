#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of linked list
 * Return: 0 not a palindrome, 1 for palindrome
 */
int is_palindrome(listint_t **head)
{
	int A[999], i, j;
	listint_t *temporal = *head;

	if (!head)
		return (1);

	for (i = 0; temporal; i++)
	{
		A[i] = temporal->n;
		temporal = temporal->next;
	}

	i--;

	for (j = 0; j <= i; ++j, i--)
	{
		if (A[i] != A[j])
			return (0);
	}
	return (1);
}
