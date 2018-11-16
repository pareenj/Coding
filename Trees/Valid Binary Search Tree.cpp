/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int isValid(TreeNode* root, int min, int max){

	if(root == NULL) return 1;

	else if((root->val < max) && (root->val > min) && (isValid(root->left, min, root->val)) && (isValid(root->right, root->val, max)))
		return 1;

	return 0;
}

int Solution::isValidBST(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return isValid(A, INT_MIN, INT_MAX);
}