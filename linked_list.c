#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

typedef struct LinkedList
{
	Node* head;
} LinkedList;

Node* newNode(int value)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	if (temp)
	{
		temp->value = value;
		temp->next = NULL;

		return temp;
	}

	return NULL;
}

LinkedList* createLinkedList()
{
	LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

	if (temp)
	{
		temp->head = NULL;

		return temp;
	}

	return NULL;
}

void rec_add(Node* nextNode, Node* nodeVal)
{
	if (!(nextNode->next))
	{
		nextNode->next = nodeVal;
	}
	else
	{
		rec_add(nextNode->next, nodeVal);
	}
}

void add(LinkedList* ll, int value)
{
	Node* temp = newNode(value);

	if (!(ll->head))
	{
		ll->head = temp;
	}
	else
	{
		rec_add(ll->head, temp);
	}
}

int index(LinkedList* ll, int index)
{
	Node* cur = ll->head;

	for (int i=0; i < index; i++)
	{
		cur = cur->next;
	}

	return cur->value;
}

void print_all(LinkedList* ll)
{
	Node* cur = ll->head;

	while (cur)
	{
		if (cur != ll->head)
		{
			printf(" -> ");
		}

		printf("%i", cur->value);

		cur = cur->next;
	}
}

int main()
{
	LinkedList* ll = createLinkedList();

	add(ll, 3);
	add(ll, 7);

	printf("%i\n", index(ll, 1));

	print_all(ll);

	return 0;
}
