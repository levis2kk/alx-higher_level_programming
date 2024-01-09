#include "lists.h"
#include <stdio.h>

void reverse(listint_t **head);
int compare_lists(listint_t *head, listint_t *middle, int len);

/**
 * is_palindrome - checks if singly linked list is a palindrome
 *
 * @head: pointer to pointer of first list node
 *
 * Return: 0 if not palindrome
 */
int is_palindrome(listint_t **head)
{
	int len, i;
	listint_t *tmp;
	listint_t *middle;

	if (head == NULL || *head == NULL)
		return (1);
	tmp = *head;
	middle = *head;

	for (len = 0; tmp != NULL; len++)
		tmp = tmp->next;
	len = len / 2;

	for (i = 1; i < len; i++)
		middle = middle->next;
	if (len % 2 != 0 && len != 1)
	{
		middle = middle->next;
		len = len - 1;
	}
	reverse(&middle);
	i = compare_lists(*head, middle, len);

	return (i);
}
/**
 * compare_lists - compares two lists
 * @head: the poiter to the head node
 * @middle: the pointer to the middle node
 * @len: length of the list
 * Return: 1 if the same, else 0
 */
int compare_lists(listint_t *head, listint_t *middle, int len)
{
	int i;

	if (head == NULL || middle == NULL)
		return (1);
	for (i = 0; i < len; i++)
	{
		if (head->n != middle->n)
			return (0);
		head = head->next;
		middle = middle->next;
	}
	return (1);
}
/**
 * reverse - rverses a list
 * @head: the pointer to the reversed head
 */
void reverse(listint_t **head)
{
	listint_t *current;
	listint_t *next;
	listint_t *previous;

	if (head == NULL || *head == NULL)
		return;

	previous = NULL;
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}
