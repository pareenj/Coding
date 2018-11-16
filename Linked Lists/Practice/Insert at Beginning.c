#include <stdlib.h>
#include <stdio.h>

	/*   struct Node
		{
			int data;
			struct Node* link;	// Node* next;
		}
	*/
	// Node* A;
	// Node* temp = new Node(); //Node* temp = (Node*)malloc(sizeof(Node));
	// temp->data = 2; // (*temp).data = 2;
	// temp->link = NULL; // (*temp).data = NULL; 
	// A = temp;

	// temp = new Node();
	// temp->data = 4;
	// temp->link = NULL;

	// // Traversal
	// Node* temp1 = A;
	// while(temp1->link != NULL) temp1 = temp1->link;

	// temp1->link = temp;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head; // Global Variable, can be accessed anywhere

void Insert(int x)
{
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	// temp->next = NULL;
	// if(head != NULL) temp->next = head;
	temp->next = head;
	head = temp;

}

void Print()
{
	struct Node* temp = head;
	printf("List is: ");
	while(temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL; // Empty List
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter the number \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}

}


// If head is local and not Global

struct Node
{
	int data;
	struct Node* next;
}

struct Node* head; // Global Variable, can be accessed anywhere

// Approach 1
Node* Insert(Node* head, int x)
{
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	// temp->next = NULL;
	// if(head != NULL) temp->next = head;
	temp->next = head;
	head = temp;

	return head;
}

// Approach 2
void Insert(Node** head, int x)
{
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	// temp->next = NULL;
	// if(head != NULL) temp->next = head;
	temp->next = *head;
	*head = temp;

	return head;
}

void Print(Node* head)
{
	printf("List is: ");
	while(head != NULL)
	{
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	Node* head = NULL; // Empty List
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter the number \n");
		scanf("%d", &x);

		// Approach 1
		head = Insert(head, x);

		// Approach 2
		Insert(&head, x);

		Print(head);
	}

}
