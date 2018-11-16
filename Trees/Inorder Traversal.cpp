/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    stack<TreeNode*> st;

    // Set current to root of binary tree
    TreeNode* current = A;
    bool done = 0;

    while(!done)
    {
    	// Reach the left most node of the current node
    	if(current != NULL)
    	{
    		// Push the tree node into the stack before traversing the node's left subtree
    		st.push(current);
    		current = current->left;
    	}

    	// Backtrack from the empty subtree and visit the node at the top of the stack
    	// But if the stack is empty, we are done
    	else
    	{
    		if(!st.empty())
    		{
    			// We have visited the node and its left subtree
    			// Now it's the right subtree's turn
    			current = st.top();
    			int value = current->val;
    			ans.push_back(value);
    			current = current->right;
    			st.pop();
    		}
    		else done = 1;
    	}
    }

    return ans;
}

// https://www.hackerearth.com/practice/notes/iterative-tree-traversals/
// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
// https://www.youtube.com/watch?v=VsxLHGUqAKs
// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
// https://www.youtube.com/watch?v=wGXB9OWhPTg