/* Binary tree - Level Order Traversal */
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

// Function to print Nodes in a binary tree in Level Order
vector<char> LevelOrder(Node* root)
{
	vector<char> ans;
	if(root == NULL) return ans;

	queue<Node*> Q;
	Q.push(root);

	// While there is at least one discovered node
	while(!Q.empty())
	{
		Node* current = Q.front();
		Q.pop(); // Removing the element at front
		ans.push_back(current->data);

		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

// Function to Insert Node in BST
Node* Insert(Node* root, char data)
{
	if(root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left, data);
	else root->right = Insert(root->right, data);
	return root;
}

int main() 
{
	/*Code To Test the logic
	  Creating an example tree
	                    M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */

	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');

	//Print Nodes in Level Order. 
	vector<int> printElements = LevelOrder(root);
	return;
}

// https://gist.github.com/mycodeschool/9507131