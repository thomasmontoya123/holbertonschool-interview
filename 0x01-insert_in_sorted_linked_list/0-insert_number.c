#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head
 * @number: node value
 * Return: new node address
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *temporal;

	newNode = malloc(sizeof(listint_t));
	if (!newNode)
		return (NULL);

	newNode->n = number;

	if (!*head)
	{
		newNode->next = NULL;
		*head = newNode;
		return (newNode);
	}

	temporal = *head;

	if (number < temporal->n)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	while ((temporal->next) && (temporal->next->n < number))
		temporal = temporal->next;

	newNode->next = temporal->next;
	temporal->next = newNode;
	return (newNode);

}
