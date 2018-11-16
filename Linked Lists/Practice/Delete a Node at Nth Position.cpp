#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	Node* next;
};

struct Node* head; // Global

void Insert(int data) // Insert an integer at beginning list
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = head;
	head = temp1;
}

void Print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n) // Delete Node at position n
{
	Node* temp1 = head;
	if(n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}

	for(int i = 0; i < n-2; i++) temp1 = temp1->next;
	// temp1 points to (n-1)th Node

	Node* temp2 = temp1->next;  //nth Node
	temp1->next = temp2->next;
	delete temp2;
}

int main()
{
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Print();
	Delete(3);
	Print();
}