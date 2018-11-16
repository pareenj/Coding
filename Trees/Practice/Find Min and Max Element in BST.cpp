// Binary Search Tree - Implemenation in C++
// Find min and max element in BST 
#include <iostream>
using namespace std;

// Definition of Node for BST
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

// Iterative Function(s)
int FindMin(BstNode* root)
{
	if(root == NULL) return -1;
	BstNode* current = root;
	while(current->left != NULL) current = current->left;
	return current->data;
}

int FindMin(BstNode* root)
{
	if(root == NULL) return -1;
	while(root->left != NULL) root = root->left;
	return root->data;
}

// Recursive function
int FindMin(BstNode* root)
{
	if(root == NULL) return -1;
	else if(root->left == NULL) return root->data;

	// Search in left subtree
	return FindMin(root->left);
}