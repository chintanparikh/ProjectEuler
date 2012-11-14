#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** headRef, int data)
{
	struct node* newNode = malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

int nextPrime(struct node* head, int num)
{
	struct node* current = head;
	while (current != NULL)
	{
		if (num % current->data == 0)
		{
			num++;
			current = head;
		}
		else
		{
			current = current->next;
		}
	}
	return num;
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	struct node* current;
	int primes = 0;
	int i = 0;
	int next;

	while (primes <= 10001)
	{
		if (head == NULL)
		{
			i = 2;
			push(&head, i);
			primes++;
		}
		else
		{
			i = head->data + 1;
			next = nextPrime(head, i);
			push(&head, next);
		}
		printf("%d : %d\n", primes, head->data);
		primes++;

	}

	printf("%d\n", head->data);
	return 0;
}