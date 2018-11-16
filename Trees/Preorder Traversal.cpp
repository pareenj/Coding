// https://www.interviewbit.com/problems/preorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    // Base Case
    if(A == NULL) return ans;

    // Create an empty stack and push root to it
    stack<TreeNode*> nodeStack;
    nodeStack.push(A);

    // Pop all items one by one. Do following for every popped item
    // 1. Add it to the answer
    // 2. Push its right child
    // 3. Push its left child
    // Note that right child is pushed first so that left is processed first
    while(!nodeStack.empty())
    {
    	// Pop the top item from stack and add it to ans
    	TreeNode* current = nodeStack.top();
    	ans.push_back(current->val);
    	nodeStack.pop();

    	// Push right and left children of the popped node to the stack
    	if(current->right != NULL) nodeStack.push(current->right);
    	if(current->left != NULL) nodeStack.push(current->left);
    }
    
    return ans;
}