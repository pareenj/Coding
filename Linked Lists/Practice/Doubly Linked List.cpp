#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node* next;
	Node* prev;	
};

struct Node* head; // Global variable- pointer to head node

struct Node* GetNewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void InsertAtHead(int x)
{
	Node* newNode = GetNewNode(x);

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void InsertAtTail(int x)
{
	Node* temp = head;
	Node* newNode = GetNewNode(x);

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	while(temp->next != NULL) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void Print()
{
	Node* temp = head;
	printf("Forward: ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint()
{
	Node* temp = head;
	if(temp == NULL) return; // Empty List, exit
	while(temp->next != NULL) temp = temp->next;
	printf("Reverse: ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	head = NULL;
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
}