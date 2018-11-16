/* Deleting a node from Binary search tree */
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

// Function to find minimum in a tree
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->next;
	return root;
}

// Function to search and delete a value from the BST
Node* Delete(Node* root, int data)
{
	if(root == NULL) return root;
	else if(data <= root->data) root->left = Delete(root->left, data);
	else if(data <= root->right) root->right = Delete(root->right, data);

	// Delete the root
	else
	{
		// Case 1: No child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}

		// Case 2: One child
		else if(root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}

		// Case 3: Two children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}