/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    // Check for empty tree
    if(A == NULL) return ans;

    TreeNode* current = A;
    stack<TreeNode*> nodeStack;

    while(current != NULL || !nodeStack.empty())
    {
    	if(current != NULL)
    	{
    		nodeStack.push(current);
    		current = current->left; 
    	}
    	else
    	{
    		TreeNode* peek = nodeStack.top();
    		TreeNode* peekRight = peek->right;

    		if(peekRight == NULL)
    		{
    			TreeNode* peekRight = nodeStack.top();
    			ans.push_back(peekRight->val);
    			nodeStack.pop();

    			while((!nodeStack.empty()) && peekRight == (nodeStack.top())->right)
    			{
    				peekRight = nodeStack.top();
    				ans.push_back(peekRight->val);
    				nodeStack.pop();
    			}
    		}
    		else current = peekRight;
    	}
    }

    return ans;
}

// https://www.youtube.com/watch?v=xLQKdq0Ffjg
// http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
// https://www.youtube.com/watch?v=qT65HltK2uE
// http://www.geeksforgeeks.org/iterative-postorder-traversal/