#include <stdio.h>
#include <stdlib.h>

//Linked List Implenentation

struct node {
    unsigned long long int data;
	struct node *next;
};

void push(struct node** headRef, unsigned long data)
{
	// Created a new Node
	struct node* newNode;

	// Assign space to the new node
	newNode = malloc(sizeof(*newNode));

	// Assign data to the new node
	newNode->data = data;

	// Make the next pointer point to the current head
	newNode->next = *headRef;

	// Set the current head to the new Node
	*headRef = newNode;
}

int primeFactors(unsigned long long num, struct node** head)
{	
	if (num == 1)
	{
		return 0;
	}
	unsigned long long int i = 2ULL, factor = 1ULL;
	while (i <= num)
	{
		if (num % i == 0)
		{
			factor = i;
			break;
		}
		i++;
	}
	push(head, factor);
	primeFactors(num / factor, head);
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	primeFactors(600851475143ULL, &head);
	printf("%llu\n", head->data);
}