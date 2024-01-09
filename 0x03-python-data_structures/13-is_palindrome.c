#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return 1;  /* Empty list or single element list is considered a palindrome */

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev = NULL;
    listint_t *temp;

    /* Move slow to the middle and reverse the first half */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    /* If the number of elements is odd, move slow one step forward */
    if (fast != NULL)
        slow = slow->next;

    /* Compare the reversed first half with the second half */
    while (slow != NULL)
    {
        if (slow->n != prev->n)
            return 0;  /* Not a palindrome */

        slow = slow->next;
        prev = prev->next;
    }

    return 1;  /* It is a palindrome */
}
