// Inorder Successor in a BST
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Function to find some data in the tree
Node* Find(Node* root, int data)
{
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right, data);
	else return Find(root->left, data);
}

// Function to find Node with minimum value in a BST
Node* FindMin(Node* root)
{
	if(root == NULL) return NULL;
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to find Inorder Successor in a BST
struct Node* getSuccessor(Node* root, int data)
{
	// Search the Node
	Node* current = Find(root, data);

	if(current == NULL) return NULL;

	// Case 1: Node has right subtree
	if(current->right != NULL)
	{
		return FindMin(current->right);
	}

	// Case 2: No right subtree
	else
	{
		Node* successor = NULL;
		Node* ancestor = root;

		while(ancestor != current)
		{
			if(current->data < ancestor->data)
			{
				successor = ancestor; // So far this is the deepest node for which the current node is in left
				ancestor = ancestor->left;
			}
			else ancestor = ancestor->right;
		}

		return successor;
	}
}

// Recursive function
struct Node* getSuccessor(Node* root, Node* current)
{
	if(root == NULL) return NULL;

	if(root->val <= current->data)
	{
		return getSuccessor(root->right, current);
	}
	else
	{
		Node* left = getSuccessor(root->left, current);
		return (left != NULL) ? left : root;
	}
}

// http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
// http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
// https://discuss.leetcode.com/topic/25076/share-my-java-recursive-solution
// https://gist.github.com/mycodeschool/6515e1ec66482faf9d79

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Function to find some data in the tree
TreeNode* Find(TreeNode* root, int data)
{
	if(root == NULL) return NULL;
	else if(root->val == data) return root;
	else if(root->val < data) return Find(root->right, data);
	else return Find(root->left, data);
}

// Function to find Node with minimum value in a BST
TreeNode* FindMin(TreeNode* root)
{
	if(root == NULL) return NULL;
	while(root->left != NULL) root = root->left;
	return root;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // Search the Node
	TreeNode* current = Find(A, B);

	if(current == NULL) return NULL;

	// Case 1: Node has right subtree
	if(current->right != NULL)
	{
		return FindMin(current->right);
	}

	// Case 2: No right subtree
	else
	{
		TreeNode* successor = NULL;
		TreeNode* ancestor = A;

		while(ancestor != current)
		{
			if(current->val < ancestor->val)
			{
				successor = ancestor; // So far this is the deepest node for which the current node is in left
				ancestor = ancestor->left;
			}
			else ancestor = ancestor->right;
		}

		return successor;
	}
}