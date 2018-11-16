// Stack - Array based implementation. 
// Creating a stack of integers. 

#include <stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE]; // An integer array to store the stack
int top = -1; // Variable to mark top of stack in array.

// Push operation to insert an element on top of stack
void Push(int x)
{
	if(top == MAX_SIZE - 1) // Overflow Case
	{
		printf("Error: Stack Overflow\n");
		return;
	}
	A[++top] = x;
}

// Pop operations to remove an element from top of stack
void Pop()
{
	if(top == -1) // If stack is empty, pop should throw error
	{
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

// Top operation to return element at top of stack
int Top()
{
	return A[top];
}

// IsEmpty function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty()
{
	if(top == -1) return 1;
	return 0;
}

// This function is just to test implementation of stack.
// This will print all elements in the stack at any stage.
void Print()
{
	int i;
	printf("Stack: ");
	for(i = 0; i <= top; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();
}