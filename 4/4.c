#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct node *merge(struct node *one, struct node *two)
{
	struct node* three;
	if (one == NULL)
	{
		return two;
	}

	if (two == NULL)
	{
		return one;
	}

	if (one->data > two->data)
	{
		three = one;
		three->next = merge(one->next, two);
	}
	else
	{
		three = two;
		three->next = merge(one, two->next);
	}

	return three;
}

struct node *mergeSort(struct node* head)
{
	// Implements (opposite) MergeSort

	struct node *one, *two;

	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	one = head;
	two = head->next;

	while (two != NULL && two->next != NULL)
	{
		head = head->next;
		two = head->next->next;
	}

	two = head->next;
	head->next = NULL;

	return merge(mergeSort(one), mergeSort(two));	

}

void reverseString(char* string, char* reversed)
{
	int i, j;
	j = strlen(string) - 1;

	for (i = j; i >= 0; i--)
	{
		reversed[j - i] = string[i];
	}
	reversed[j + 1] = 0;
}

int main(int argc, char const *argv[])
{
	int num[2];
	char numString[7];
	char reversedString[7];
	struct node* head = NULL;
	for(num[0] = 100; num[0] <= 999; num[0]++)
	{
		for(num[1] = 100; num[1] <= 999; num[1]++)
		{
			sprintf(numString, "%d", num[0]*num[1]);
			reverseString(numString, reversedString);
			if (strcmp(numString, reversedString) == 0)
			{
				push(&head, num[0]*num[1]);
			}
		}
	}

	head = mergeSort(head);
	printf("%d\n", head->data);
	return 0;
}