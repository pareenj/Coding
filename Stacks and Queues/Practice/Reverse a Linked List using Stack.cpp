#include <iostream>
#include <stack> // Stack from Standard Template Library (STL)
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Reverse(Node* head)
{
	if(head == NULL) return;
	
	stack<struct Node*> S;

	// Pushing all the nodes
	Node* temp = head;
	while(temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}

	// Popping the nodes from the stack and adding the top elements to the final linked list
	temp = S.top(); head = temp;
	S.pop();
	while(!S.empty())
	{
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;

	return head;
}