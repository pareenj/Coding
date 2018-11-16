#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	Node* next;
};

struct Node* Insert(Node* head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head = NULL) head = temp;
	else {
		Node* temp1 = head;
		while(temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

void Print(Node* p) // p is local node
{
	if(p == NULL) return; // Exit condition
	printf("%d ", p->data); // First print the value in the node
	Print(p->next); // Recursive call to printing functions in other nodes
}

void ReversePrint(Node* p) // p is local node
{
	if(p == NULL) return; // Exit condition
	ReversePrint(p->next); // Recursive call to printing functions in other nodes
	printf("%d ", p->data); // First print the value in the node
}

int main()
{
	Node* head = NULL; // Local Variable
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 5);
	Print(head);
}

