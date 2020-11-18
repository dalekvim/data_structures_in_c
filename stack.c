#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

int* stack;
int nextfree = 1;

bool isEmpty(int* stack)
{
	if (nextfree == 1) {
		return true;
	}
	return false;
}

bool isFull(int* stack)
{
	if (nextfree == STACK_SIZE)
		return true;
	return false;
}

void push(int* stack, int value)
{
	if (!isFull(stack))
		stack[nextfree] = value;
		nextfree++;
}

int pull(int* stack)
{
	if (isEmpty(stack)) { return -1; };

	nextfree--;
	return stack[nextfree];
}

int peek(int* stack)
{
	if (isEmpty(stack)) { return -1; };

	return stack[nextfree - 2];
}

int main()
{
	stack = (int*)malloc(STACK_SIZE * sizeof(int));

	push(stack, 10);
	printf("%i\n", pull(stack));

	push(stack, 3);
	push(stack, 7);

	printf("%i, %i\n", pull(stack), peek(stack));

	free(stack);
	return 0;
}
