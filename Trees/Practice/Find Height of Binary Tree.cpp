// Binary Tree - Implemenation in C++
// Find height of Binary Tree
#include <iostream>
using namespace std;

// Definition of Node for Binary Tree
struct Node
{
	int data;
	Node* left;
	Node* right;
};

int FindHeight(Node* root)
{
	if(root == NULL) return -1;
	return (max(FindHeight(root->left), FindHeight(root->right))) + 1;
}
