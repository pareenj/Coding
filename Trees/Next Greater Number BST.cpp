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

// http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
// http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
// https://discuss.leetcode.com/topic/25076/share-my-java-recursive-solution