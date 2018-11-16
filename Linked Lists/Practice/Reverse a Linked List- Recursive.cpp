#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	Node* next;
};

struct Node* head;

void Reverse(Node* p)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}

	Reverse(p->next);

	// p->next->next = p;
	Node* q = p->next;
	q->next = p;

	p->next = NULL;
}

Node* Reverse(Node* p)
{
	if(p->next == NULL || p == NULL) return p; // If list has only one node or list doest not exist

	Node* head = Reverse(p->next); // Recursive call on head
	p->next->next = p;
	// Node* q = p->next;
	// q->next = p;
	p->next = NULL;

	return head;
}

int main()
{
	struct Node* head = NULL; //Local Variable
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);
}